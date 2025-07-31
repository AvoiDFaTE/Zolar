#include "Battery.h"

ESPBattery Battery(PinBattery, 100);

SemaphoreHandle_t BatteryVoltageMutex = xSemaphoreCreateMutex();
float BatteryVoltage = 0.;
uint16_t BatteryState;

void BAT_Init(void){
  analogReadResolution(12);
}

void BAT_loop(void){
  Battery.loop();
  BAT_Get_Volts();
}

float BAT_Get_Volts(void)
{
  if(xSemaphoreTake(BatteryVoltageMutex, 0)){
    BatteryVoltage = Battery.getVoltage();
    xSemaphoreGive(BatteryVoltageMutex);
  }

  return BatteryVoltage;
}

uint16_t BAT_Get_State(void)
{
  if(xSemaphoreTake(BatteryVoltageMutex, 0)){
    BatteryState = Battery.getState();
    xSemaphoreGive(BatteryVoltageMutex);
  }
  
  return BatteryState;
}