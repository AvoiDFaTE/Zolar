/////////////////////////////////////////////////////////////////
/*
    Arduino Library to calculate the ESP8266 (Feather Huzzah) LiPo battery level.
	Created by Lennart Hennigs, November 4, 2017.
*/
/////////////////////////////////////////////////////////////////

#pragma once

#ifndef ESPBattery_h
#define ESPBattery_h

/////////////////////////////////////////////////////////////////

#include <Arduino.h>

/////////////////////////////////////////////////////////////////

#define Measurement_offset 0.992857

#define ESPBATTERY_CHARGING 4150	// lower boundary
#define ESPBATTERY_FULL     4100	// lower boundary
#define ESPBATTERY_OK       3600	// picked value
#define ESPBATTERY_LOW      3000	// upper boundary
#define ESPBATTERY_CRITICAL 2700	// upper boundary

/////////////////////////////////////////////////////////////////

class ESPBattery {
  private:
    byte pin;
    float v;
    float mv;
    int percentage;
    int min_level, max_level;
    int interval, last_read;
    int state, last_state;

    void readData();

    typedef void (*CallbackFunction) (ESPBattery&);
    
    CallbackFunction changed_cb = NULL;
    CallbackFunction low_cb = NULL;
    CallbackFunction critical_cb = NULL;
    CallbackFunction charging_cb = NULL;
    
  public:
    ESPBattery(byte analog_pin = 4, int polling_interval_ms = 500, int min_lvl = ESPBATTERY_CRITICAL, int max_lvl = ESPBATTERY_FULL);

	float getVoltage();
    int getPercentage();
    int getState();
    int getPreviousState();
	String stateToString(int state);
    
    void setLevelChangedHandler(CallbackFunction f);
    void setLevelLowHandler(CallbackFunction f);
    void setLevelCriticalHandler(CallbackFunction f);    
    void setLevelChargingHandler(CallbackFunction f);    

	void loop();
};

/////////////////////////////////////////////////////////////////
#endif
/////////////////////////////////////////////////////////////////