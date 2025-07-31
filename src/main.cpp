#include <numeric>

#include "drivers/LVGL_Driver.h"

#include "drivers/TCA9554PWR.h"
#include "RTC_PCF85063.h"

#include "Types.h"
#include "Battery.h"
#include "PulseCounter.h"
#include "Calc.h"
#include "Button.h"
#include "Settings.h"
#include "Logger.h"
#include "WebSettings.h"

#include "ui/ui_custom.h"
#include "ui/ui_functions.h"


void Driver_Loop(void *parameter)
{
  while(1)
  {    
    RTC_Loop();
    BAT_loop();
    vTaskDelay(pdMS_TO_TICKS(100));
  }
}
void Driver_Init()
{
  BAT_Init();
  I2C_Init();
  TCA9554PWR_Init(0x00);   
  Set_EXIO(EXIO_PIN8,Low);
  Backlight_Init();
  Set_Backlight(50);      //0~100 
  PCF85063_Init();
  
  xTaskCreatePinnedToCore(
    Driver_Loop,     
    "Other Driver task",   
    4*configMINIMAL_STACK_SIZE,                
    NULL,                 
    3,                    
    NULL,                
    0                    
  );
}

QueueHandle_t calcCpsQueue;

void mockCps(void *pvParameters){ 
  std::vector<uint16_t> storedCps;
  uint16_t currentPulseCount;
  cps_t cpsData;
  while(1){
    
    cpsData.CurrentCps = lv_rand(220,285);
   
    storedCps.push_back(cpsData.CurrentCps);
    if (storedCps.size() > 10){
      storedCps.erase( storedCps.begin() );
    };

    cpsData.AvgCps = accumulate( storedCps.begin(), storedCps.end(), 0) / storedCps.size();

    xQueueOverwrite( CpsQueue, &cpsData );
    
    vTaskDelay(1000);        
  }
}

void setup()
{
  Serial.begin(115200);

  Driver_Init();
  LCD_Init();
  Lvgl_Init();

  setupSettings();
  setupLogger();

  if(!GS.MockCPS){
    setupPulseCounter();
  }
  else {
    CpsQueue = xQueueCreate( 1, sizeof(cps_t) );
    xTaskCreateUniversal( 
          mockCps, 
          "mockCps", 
          4*configMINIMAL_STACK_SIZE, 
          NULL, 
          configMAX_PRIORITIES-1, 
          NULL, 
          0
    );
  }
 
  calcCpsQueue = xQueueCreate( 1, sizeof(cps_t) ); /*Second CPS queue for processing in calc*/
  setupCalc(calcCpsQueue);

  ui_init_all(); 
}

void loop()
{
  cps_t receivedCps;
  if(xQueueReceive(CpsQueue, &receivedCps, 0)) {
    xQueueOverwrite( calcCpsQueue, &receivedCps );
    uiUpdateOnGetCPS(receivedCps);
  }

  calcLoop();
  buttonLoop();

  Lvgl_Loop();

  vTaskDelay(pdMS_TO_TICKS(5));  
}