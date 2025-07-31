#pragma once

#include <Arduino.h> 
#include "Pinout.h"
#include "modules/ESPBattery.h"

extern ESPBattery Battery;
extern float BatteryVoltage;
extern uint16_t BatteryState;

void BAT_Init(void);
void BAT_loop(void);
float BAT_Get_Volts(void);
uint16_t BAT_Get_State(void);