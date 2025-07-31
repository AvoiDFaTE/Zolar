#pragma once

/////////////////////////////////////////////////////////////////
#ifndef AshCalc_h
#define AshCalc_h
/////////////////////////////////////////////////////////////////

#include "Arduino.h"
#include "Types.h"

typedef enum class MeasureState {StandBy, Measure} MeasureState;   

class AshCalc {
  private:
    QueueHandle_t _cpsQueue;
    MeasureState _state;

    uint8_t _maxMeasurementsCount;
    uint8_t _minMeasurementsCountToAvg;
    TickType_t _minMeasureTime;
    float _cpsRsdThreshold;
    
    TickType_t _measureBeginTime;
    TickType_t _measurePlanEndTime;    
    TickType_t _measureEndTime;    

    measurements_t _measurement;
    calibration_t _calibration;
    std::vector<measurements_t> _measurementsVector;
    averaged_t _averagedMeasurements;  
    float _cpsRsdPowSum;      

    bool setCalibration(calibration_t calibration);
    bool autoEndMeasure();
    void measure(cps_t receivedCps);
    void standBy(cps_t receivedCps);  

  public:
    AshCalc(uint8_t maxMeasurementsCount = 12, float cpsRsdThreshold = 0.5, uint8_t minMeasurementsCountToAvg = 1);

    cps_t LastReceivedCPS;
    
    void begin(QueueHandle_t cpsQueue, uint8_t minMeasureSeconds, std::vector<measurements_t> loadedMeasurements);

    calibration_t getCalibration();

    void setMaxMeasurementsCount(uint8_t maxMeasurementsCount);
    void setMinMeasurementsCountToAvg(uint8_t minMeasurementsCountToAvg);
    void setCpsRsdThreshold(float cpsRsd);

    std::vector<measurements_t> getMeasurements();
    averaged_t getAveraged();
    uint16_t getMeasurementRemainingSeconds();
    measurements_t getCurrentMeasurment();    
    MeasureState getState();

    bool canBeginMeasure();
    bool canEndMeasure();  
    bool canPerformAverage();  
    
    bool beginMeasure(calibration_t calibration, uint16_t timeSetSeconds);
    bool endMeasure();

    bool performAverage();
    bool clearMeasurements();

  	void loop();    
};

/////////////////////////////////////////////////////////////////
#endif
/////////////////////////////////////////////////////////////////