#include "modules/AshCalc.h"
#include <numeric>

AshCalc::AshCalc(uint8_t maxMeasurementsCount, float cpsRsdThreshold, uint8_t minMeasurementsCountToAvg) {  
  setMaxMeasurementsCount(maxMeasurementsCount);
  setMinMeasurementsCountToAvg(minMeasurementsCountToAvg);
  setCpsRsdThreshold(cpsRsdThreshold);
}

void AshCalc::begin(QueueHandle_t cpsQueue, uint8_t minMeasureSeconds, std::vector<measurements_t> loadedMeasurements) {
  _state = MeasureState::StandBy;  
  _minMeasureTime = minMeasureSeconds * portTICK_PERIOD_MS * 1000;
  _measurementsVector = loadedMeasurements;
  performAverage();

  _cpsQueue = cpsQueue;
}

calibration_t AshCalc::getCalibration() {
  return _calibration;
}

bool AshCalc::setCalibration(calibration_t calibration) {
  for (auto measurement : _measurementsVector){
    if(calibration.FactorA != measurement.Calibration.FactorA || calibration.FactorB != measurement.Calibration.FactorB)
      return false;
  };  

  _calibration = calibration;
  return true;
}

bool AshCalc::autoEndMeasure(){
  return _state == MeasureState::Measure
         && (xTaskGetTickCount() >= _measurePlanEndTime
             || (_cpsRsdThreshold > 0
                && _measurement.CpsRsd <= _cpsRsdThreshold)
             );
}

void AshCalc::setMaxMeasurementsCount(uint8_t maxMeasurementsCount) {
  _maxMeasurementsCount = maxMeasurementsCount;
}

void AshCalc::setMinMeasurementsCountToAvg(uint8_t minMeasurementsCountToAvg) {
  _minMeasurementsCountToAvg = minMeasurementsCountToAvg > 1 ? minMeasurementsCountToAvg : 1;
}

void AshCalc::setCpsRsdThreshold(float cpsRsd){
  _cpsRsdThreshold = (cpsRsd > 0 && cpsRsd <= 100) ? cpsRsd : 0;
}

std::vector<measurements_t> AshCalc::getMeasurements() {
  return _measurementsVector;
}

averaged_t AshCalc::getAveraged() {
  return _averagedMeasurements;
}

uint16_t AshCalc::getMeasurementRemainingSeconds(){
  return _state == MeasureState::Measure ? (uint16_t)(_measurePlanEndTime - xTaskGetTickCount()) / 1000 / portTICK_PERIOD_MS  : 0 ;
}

measurements_t AshCalc::getCurrentMeasurment(){
  return _state == MeasureState::Measure ? _measurement : _measurementsVector.back() ;
}

MeasureState AshCalc::getState(){
  return _state;
}

bool AshCalc::canBeginMeasure() {
  return _state == MeasureState::StandBy 
         && _measurementsVector.size() < _maxMeasurementsCount;
}

bool AshCalc::canEndMeasure() {
  return _state == MeasureState::Measure 
         && xTaskGetTickCount() - _measureBeginTime >= _minMeasureTime;
}

bool AshCalc::canPerformAverage() {
  return _state == MeasureState::StandBy 
         && _measurementsVector.size() >= _minMeasurementsCountToAvg;
}

bool AshCalc::beginMeasure(calibration_t calibration, uint16_t timeSetSeconds) {
  if(!canBeginMeasure() || !setCalibration(calibration)) {
    return false;
  }   
  _state = MeasureState::Measure;

  _measurement = {};
  _cpsRsdPowSum = 0;
  
  _measureBeginTime = xTaskGetTickCount();
  _measurePlanEndTime = _measureBeginTime + timeSetSeconds * portTICK_PERIOD_MS * 1000;
  _measurement.Calibration = _calibration;  

  return true;
}

bool AshCalc::endMeasure() {
  if(!canEndMeasure()) {
    return false;
  }  
  _state = MeasureState::StandBy;

  _measureEndTime = xTaskGetTickCount();

  _measurement.IntegrationTime = (_measureEndTime - _measureBeginTime) / portTICK_PERIOD_MS / 1000;
  _measurement.Ash = _measurement.Calibration.FactorA * _measurement.IntegratedCps + _measurement.Calibration.FactorB;  
  
  _measurementsVector.push_back(_measurement);
 
  performAverage();

  return true;
}

bool AshCalc::performAverage() {
  if(!canPerformAverage()) {
    return false;
  }    

  _averagedMeasurements.AvgCps = 0;
  for (auto measurement : _measurementsVector){
    _averagedMeasurements.AvgCps += measurement.IntegratedCps;
  };
  _averagedMeasurements.AvgCps /= _measurementsVector.size();

  _averagedMeasurements.AvgAsh = 0;    
  for (auto measurement : _measurementsVector){
    _averagedMeasurements.AvgAsh += measurement.Ash;
  };
  _averagedMeasurements.AvgAsh /= _measurementsVector.size();

  _averagedMeasurements.AvgTime = 0;    
  for (auto measurement : _measurementsVector){
    _averagedMeasurements.AvgTime += measurement.IntegrationTime;
  };
  _averagedMeasurements.AvgTime /= _measurementsVector.size();                                                                           

  _averagedMeasurements.AbsoluteStdDeviation = 0;
  for (auto measurement : _measurementsVector){     
    _averagedMeasurements.AbsoluteStdDeviation += pow( (measurement.Ash - _averagedMeasurements.AvgAsh), 2);
  };
  _averagedMeasurements.AbsoluteStdDeviation = sqrt(_averagedMeasurements.AbsoluteStdDeviation / _measurementsVector.size());
  
  _averagedMeasurements.RelativeStdDeviation = _averagedMeasurements.AbsoluteStdDeviation / _averagedMeasurements.AvgAsh * 100; 

  _averagedMeasurements.Calibration = _measurementsVector.back().Calibration;

  return true;
}

bool AshCalc::clearMeasurements(){
  _measurementsVector.clear();
  _measurement = {};
  _averagedMeasurements = {};

  return true;
}

void AshCalc::measure(cps_t receivedCps) {
  _measurement.ProbesCount++;
  _measurement.IntegratedCps = ( _measurement.IntegratedCps * (_measurement.ProbesCount-1) + receivedCps.CurrentCps ) / _measurement.ProbesCount; 

  _cpsRsdPowSum += pow( (receivedCps.CurrentCps - _measurement.IntegratedCps), 2 );
  
  _measurement.CpsRsd = sqrt(_cpsRsdPowSum / _measurement.ProbesCount) / _measurement.IntegratedCps * 100;
}

void AshCalc::standBy(cps_t receivedCps) {
  
}

void AshCalc::loop() {
  cps_t receivedCps;
  
  if(xQueueReceive(_cpsQueue, &receivedCps, 0)) {
    LastReceivedCPS = receivedCps;
    switch(_state) { 
      case MeasureState::Measure:
        measure(receivedCps);
        break;
      case MeasureState::StandBy:
        standBy(receivedCps);
        break;
    } 
  }    

  if(autoEndMeasure()){
    endMeasure();
  }
}