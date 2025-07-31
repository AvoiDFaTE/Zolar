#pragma once

#include <Arduino.h>
#include "Pinout.h"
#include "modules/AshCalc.h"
#include "Settings.h"


extern AshCalc Calc;

void setupCalc(QueueHandle_t cpsQueue);
void calcLoop();
bool beginMeasure();
bool stopMeasure();
bool clearMeasurements();