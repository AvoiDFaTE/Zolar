/////////////////////////////////////////////////////////////////
/*
  Arduino Library to calculate the ESP8266 (Feather Huzzah) LiPo battery level.
  Created by Lennart Hennigs, November 4, 2017.
*/
/////////////////////////////////////////////////////////////////

#include "modules/ESPBattery.h"

/////////////////////////////////////////////////////////////////

ESPBattery::ESPBattery(byte analog_pin, int polling_interval_ms, int min_lvl, int max_lvl) {
  pin = analog_pin;
  interval = polling_interval_ms;
  min_level = min_lvl;  
  max_level = max_lvl;
  
  readData();
}

/////////////////////////////////////////////////////////////////

void ESPBattery::readData() {
  last_read = millis();
  uint16_t Volts = analogReadMilliVolts(pin); // millivolts
  mv = (float)(Volts * 3.0 ) / Measurement_offset; 
  v = mv / 1000.0;
  percentage = map(mv, min_level, max_level, 0, 100);

  if (percentage < 0) {
    percentage = 0;  
  } else if (percentage > 100) {
    percentage = 100;
  }
  getState();
}

/////////////////////////////////////////////////////////////////

void ESPBattery::loop() {
  if (millis() > last_read + interval) {
    readData();
  }
}

/////////////////////////////////////////////////////////////////

float ESPBattery::getVoltage() {
  return v;
}

/////////////////////////////////////////////////////////////////

int ESPBattery::getPercentage() {
  return percentage;
}

/////////////////////////////////////////////////////////////////

int ESPBattery::getState() {
    last_state = state;
    if (mv >= ESPBATTERY_CHARGING) {
        state = ESPBATTERY_CHARGING;
    } else if (mv >= ESPBATTERY_FULL) {
        state = ESPBATTERY_FULL;        
    } else if (mv <= ESPBATTERY_CRITICAL) {
        state = ESPBATTERY_CRITICAL;        
    } else if (mv <= ESPBATTERY_LOW) {
        state = ESPBATTERY_LOW;        
    } else {
        state = ESPBATTERY_OK;
    }
        
    if (state != last_state) {
        if (changed_cb != NULL) changed_cb (*this);    
        switch (state) {
            case ESPBATTERY_CHARGING:
                if (charging_cb != NULL) charging_cb (*this);    
                break;
            case ESPBATTERY_CRITICAL:
                if (critical_cb != NULL) critical_cb (*this);    
                break;
            case ESPBATTERY_LOW:
                if (low_cb != NULL) low_cb (*this);    
                break;
        }   
    }
    return state;
}

/////////////////////////////////////////////////////////////////

String ESPBattery::stateToString(int state) {
    String stateStr;
	switch (state) {
		case ESPBATTERY_OK:
			stateStr = "OK";
		case ESPBATTERY_FULL:
			stateStr = "FULL";
		case ESPBATTERY_CHARGING:
			stateStr = "CHARGING";
		case ESPBATTERY_CRITICAL:
			stateStr = "CRITICAL";
		case ESPBATTERY_LOW:
			stateStr = "LOW";
	}
    return stateStr;
}

/////////////////////////////////////////////////////////////////

int ESPBattery::getPreviousState() {
    return last_state;
}

/////////////////////////////////////////////////////////////////

void ESPBattery::setLevelChangedHandler(CallbackFunction f) {
    changed_cb = f;
}

/////////////////////////////////////////////////////////////////

void ESPBattery::setLevelLowHandler(CallbackFunction f) {
    low_cb = f;
}

/////////////////////////////////////////////////////////////////

void ESPBattery::setLevelCriticalHandler(CallbackFunction f) {
    critical_cb = f;
}

/////////////////////////////////////////////////////////////////

void ESPBattery::setLevelChargingHandler(CallbackFunction f) {
    charging_cb = f;    
}

/////////////////////////////////////////////////////////////////