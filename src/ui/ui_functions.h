#ifndef _UI_FUNCTIONS_H
#define _UI_FUNCTIONS_H

#include <Arduino.h>
#include "Types.h"
#include "ui/ui_custom.h"
#include "RTC_PCF85063.h"
#include "Battery.h"
#include "Types.h"
#include "Calc.h"
#include "Settings.h"
#include "drivers/TCA9554PWR.h"
#include "Constants.h"
#include "WebSettings.h"


void uiBuzzerBeep();

void uiProceedSplash(lv_timer_t * timer);

void uiUpdateOnGetCPS(cps_t cps);

void uiUpdateOnTimer(lv_timer_t * timer);

void uiFillScreenStandBy();

void uiFillScreenMeasurements();

void uiFillSettingsMenu();

void uiBeginMeasure();

void uiStopMeasure();

void uiMeasureEnded();

void uiClearMeasurements();

void uiEnterSettingsMenu();

void uiLeaveSettingsMenu();

void uiEnterCalibrationEdit();

void uiLeaveCalibrationEdit(bool save);

void uiEnterWebSettings();

void uiChangeCalibration();

void uiChangeTimeset();

#endif
