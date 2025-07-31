#pragma once

#include <Pinout.h>
#include "Types.h"

const uint16_t cGetCPSPeriodMs = 1000;
const uint16_t c1Second = 1000;
const uint8_t cStoredCpsCount = 10;
const uint16_t cDetectorReadyTime = 3000;

extern QueueHandle_t CpsQueue;
extern cps_t CpsData;

QueueHandle_t setupPulseCounter();
void pauseDetector();
void resumeDetector();
bool detectorEnabled();
bool detectorReady();