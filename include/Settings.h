#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include "Types.h"
#include "Constants.h"

typedef struct GlobalSettings {
    bool MockCPS;

    std::vector<calibration_t> Calibrations;
    std::vector<uint16_t> Timesets;
    std::vector<measurements_t> Measurements;
    
    uint8_t ActiveCalibration;
    uint8_t ActiveTimeset;

    uint8_t MinMeasureTime;
    uint8_t MaxMeasurementsCount;
    float CpsRsdThreshold;

    String apSSID;
    String apPassword;
    String apHostname;
} GlobalSettings;

extern GlobalSettings GS;
extern GlobalSettings GScopyForMenu;

bool setupSettings();

bool loadSettings();

bool saveSettings();