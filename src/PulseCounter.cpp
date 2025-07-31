#include <Arduino.h>
#include <vector>
#include <numeric>
#include "PulseCounter.h"

QueueHandle_t _cpsQueue;
QueueHandle_t CpsQueue;
cps_t CpsData = {};

TaskHandle_t _cpsTaskHandle;
volatile uint16_t _pulseCount = 0;
bool _detectorEnabled = false;
SemaphoreHandle_t _detectorEnabledMutex = xSemaphoreCreateMutex();
SemaphoreHandle_t _pulseCounterMutex = xSemaphoreCreateMutex();
TickType_t _detectorStartTime;

std::vector<uint16_t> StoredCps;

void IRAM_ATTR pulseInc() {  
    if(xSemaphoreTakeFromISR(_pulseCounterMutex,NULL)){
      _pulseCount++;
    }

    xSemaphoreGiveFromISR(_pulseCounterMutex, NULL);
}

uint16_t getAndZeroPulseCount( TickType_t xTicksToWait ){
    uint16_t oldPulseCount;
    if (xSemaphoreTake(_pulseCounterMutex, xTicksToWait)){
        oldPulseCount = _pulseCount;       
        _pulseCount = 0;

        xSemaphoreGive(_pulseCounterMutex);
    };
    return oldPulseCount;
}

bool detectorEnabled(){
    bool detectorEnabled = false;
    if (xSemaphoreTake(_detectorEnabledMutex, portMAX_DELAY)){
        detectorEnabled = _detectorEnabled;    
        xSemaphoreGive(_detectorEnabledMutex);
    };
    return detectorEnabled;
};

void setDetectorEnabled(bool detectorEnabled){
    if (xSemaphoreTake(_detectorEnabledMutex, portMAX_DELAY)){
        _detectorEnabled = detectorEnabled;    
        xSemaphoreGive(_detectorEnabledMutex);
    };
};

bool detectorReady(){
    bool detectorReady = detectorEnabled() && ( (xTaskGetTickCount() - _detectorStartTime) > cDetectorReadyTime);    

    return detectorReady;
};

void getCpsTask(void *pvParameters){ 
    uint16_t currentPulseCount;
    cps_t cpsData;

    _pulseCount = 0;  

    pinMode(PinDetectorPower, OUTPUT);
    digitalWrite(PinDetectorPower, HIGH);
    pinMode(PinDetectorSignal, INPUT);
    digitalWrite(PinDetectorSignal, LOW);
    _detectorStartTime = xTaskGetTickCount();
    attachInterrupt( digitalPinToInterrupt(PinDetectorSignal), pulseInc, RISING );

    setDetectorEnabled(true);
    
    TickType_t lastGetCpsTime = xTaskGetTickCount ();
    const TickType_t nextGetCpsTime = cGetCPSPeriodMs / portTICK_PERIOD_MS;
    vTaskDelayUntil(&lastGetCpsTime, nextGetCpsTime);
    while(true){
        currentPulseCount = getAndZeroPulseCount(nextGetCpsTime);

        cpsData.CurrentCps = currentPulseCount / (cGetCPSPeriodMs / c1Second);
        
        StoredCps.push_back(cpsData.CurrentCps);
        if (StoredCps.size() > cStoredCpsCount){
            StoredCps.erase( StoredCps.begin() );
        };

        cpsData.AvgCps = accumulate( StoredCps.begin(), StoredCps.end(), 0) / StoredCps.size();

        xQueueOverwrite( _cpsQueue, &cpsData );
    
        vTaskDelayUntil(&lastGetCpsTime, nextGetCpsTime);
    }

}

QueueHandle_t setupPulseCounter() {   
    _cpsQueue = xQueueCreate( 1, sizeof(cps_t) ); 
    
    CpsQueue = _cpsQueue;

    xTaskCreateUniversal( 
        getCpsTask, 
        "getCpsTask", 
        4*configMINIMAL_STACK_SIZE, 
        NULL, 
        configMAX_PRIORITIES-1, 
        &_cpsTaskHandle, 
        1
    );
    return _cpsQueue;
}

void pauseDetector(){
    digitalWrite(PinDetectorPower, LOW);
    vTaskSuspend(_cpsTaskHandle);
    xQueueReset(_cpsQueue);
    getAndZeroPulseCount(portMAX_DELAY);
    setDetectorEnabled(false);
};

void resumeDetector(){
    digitalWrite(PinDetectorPower, HIGH);
    _detectorStartTime = xTaskGetTickCount();
    vTaskResume(_cpsTaskHandle);
    setDetectorEnabled(true);    
}