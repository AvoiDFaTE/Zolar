#include "Calc.h"

#include "ui/ui_functions.h"
#include "Logger.h"

AshCalc Calc;

void setupCalc(QueueHandle_t cpsQueue) {
  Calc.setMaxMeasurementsCount(GS.MaxMeasurementsCount);
  Calc.setCpsRsdThreshold(GS.CpsRsdThreshold);
  
  Calc.begin(cpsQueue, GS.MinMeasureTime, GS.Measurements);  
}

void measureEnded(){
  GS.Measurements.push_back(Calc.getCurrentMeasurment());
  
  uiBuzzerBeep();
 
  logMeasurment(Calc.getCurrentMeasurment());
  saveSettings();

  uiMeasureEnded();
}

void calcLoop() {
  MeasureState prevState = Calc.getState();
  Calc.loop();
  if(prevState == MeasureState::Measure
     && Calc.getState() == MeasureState::StandBy)
    {
      measureEnded();
    }
}

bool beginMeasure(){
  return Calc.beginMeasure(GS.Calibrations[GS.ActiveCalibration], GS.Timesets[GS.ActiveTimeset]);
}

bool stopMeasure(){
  bool result;
  if(result = Calc.endMeasure()){
    measureEnded();
  }

  return result;
}

bool clearMeasurements(){
  bool result = false;
  if(Calc.getMeasurements().size() > 0){
    averaged_t averaged = Calc.getAveraged();
    if(result = Calc.clearMeasurements()){
      uiBuzzerBeep();
      GS.Measurements.clear();
      logAverage(averaged);
      saveSettings();   

      uiFillScreenMeasurements();         
    }
  }  

  return result;
}