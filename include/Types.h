#include <Arduino.h>

#pragma once

typedef struct calibration_t {
  String Name;
  float FactorA;
  float FactorB;
} calibration_t;

typedef struct measurements_t {
  uint16_t ProbesCount;
  uint16_t IntegrationTime;
  float IntegratedCps;
  float CpsRsd;
  calibration_t Calibration;
  float Ash;  
} measurements_t;

typedef struct averaged_t {
  float AvgCps;
  float AvgAsh;
  float RelativeStdDeviation;
  float AbsoluteStdDeviation;
  calibration_t Calibration;
  uint16_t AvgTime;  
} averaged_t;

typedef struct cps_t {
  uint16_t CurrentCps;  
  uint16_t AvgCps;  
} cps_t;