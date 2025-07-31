#include "Settings.h"
#include <LittleFS.h>

GlobalSettings GS;
GlobalSettings GScopyForMenu;

bool setupSettings() {
  if (!LittleFS.begin(true)) {
    printf("Failed to mount littlefs");
    return false;
  }    

  bool result = loadSettings();

  return result;
};

/*
void core0FileWrite( void * pvParameters ){
  LittleFS.begin(true);
  File settingsFile = LittleFS.open(ConfigFilePath, "w");
  char* fwData = ( char* ) pvParameters;
  settingsFile.print(fwData);
  settingsFile.close();
  vTaskDelete(NULL);
}
*/  

bool loadSettings() {
  File settingsFile = LittleFS.open(ConfigFilePath, FILE_READ);
  if (!settingsFile) {
    printf("Failed to open data file");
    return false;
  };
  

  JsonDocument doc;
  DeserializationError error = deserializeJson(doc, settingsFile);
  if (error) {
    printf("Failed to read file");
    return false;
  }
  settingsFile.close();

  GS.MockCPS = doc["General"]["MockCPS"];

  GS.apSSID = String(doc["AP"]["apSSID"]);
  GS.apPassword = String(doc["AP"]["apPassword"]);
  GS.apHostname = String(doc["AP"]["apHostname"]);

  JsonArray array;

  GS.ActiveCalibration = doc["Calibrtaions"]["Active"];
  
  GS.Calibrations.clear();
  array = doc["Calibrtaions"]["List"].as<JsonArray>();
  for(JsonObject v : array) {
    calibration_t cal = {
      v["Name"], 
      v["A"],
      v["B"]
    };

    GS.Calibrations.push_back(cal);
  }  

  GS.ActiveTimeset = doc["Timesets"]["Active"];
  
  GS.Timesets.clear();  
  array = doc["Timesets"]["List"].as<JsonArray>();
  for(JsonVariant v : array) {
    GS.Timesets.push_back(v.as<uint16_t>());
  }    

  GS.MaxMeasurementsCount = doc["Measurements"]["MaxMeasurementCount"];
  GS.MinMeasureTime = doc["Measurements"]["MinMeasureTime"];
  GS.CpsRsdThreshold = doc["Measurements"]["CpsRsdThreshold"];

  GS.Measurements.clear();
  array = doc["Measurements"]["List"].as<JsonArray>();
  for(JsonObject v : array) {
    measurements_t mes;
    mes.ProbesCount = v["ProbesCount"];
    mes.IntegrationTime = v["IntegrationTime"];
    mes.IntegratedCps = v["IntegratedCps"];
    mes.CpsRsd = v["CpsRsd"];
    mes.Ash = v["Ash"];

    mes.Calibration.FactorA = v["Calibration"]["A"];
    mes.Calibration.FactorB = v["Calibration"]["B"];

    GS.Measurements.push_back(mes);
  }  

  printf("loaded %d calibs; %d timesets; %d measurements\n", GS.Calibrations.size(), GS.Timesets.size(), GS.Measurements.size());

  return true;
}

bool saveSettings() {
  File settingsFile = LittleFS.open(ConfigFilePath, "w");
  if (!settingsFile) {
    printf("Failed to open data file");
    return false;
  };
  
  JsonDocument doc;
  JsonArray array;

  doc["General"]["MockCPS"] = GS.MockCPS;

  doc["AP"]["apSSID"] = GS.apSSID;
  doc["AP"]["apPassword"] = GS.apPassword;
  doc["AP"]["apHostname"] = GS.apHostname;
  
  doc["Calibrtaions"]["Active"] = GS.ActiveCalibration;  

  JsonArray cals = doc["Calibrtaions"]["List"].to<JsonArray>();
  for(auto cal : GS.Calibrations){
    JsonDocument jcal;

    jcal["Name"] = cal.Name;
    jcal["A"] = cal.FactorA;
    jcal["B"] = cal.FactorB;
    
    cals.add(jcal);
  };

  doc["Timesets"]["Active"] = GS.ActiveTimeset;
  
  JsonArray tsets = doc["Timesets"]["List"].to<JsonArray>();
  for(auto ts : GS.Timesets){
    tsets.add(ts);
  }; 

  doc["Measurements"]["MaxMeasurementCount"] = GS.MaxMeasurementsCount;
  doc["Measurements"]["MinMeasureTime"] = GS.MinMeasureTime;
  doc["Measurements"]["CpsRsdThreshold"] = GS.CpsRsdThreshold;  

  JsonArray ml = doc["Measurements"]["List"].to<JsonArray>();
  for(auto mes : GS.Measurements){
    JsonDocument jm;   
            
    jm["ProbesCount"] = mes.ProbesCount;
    jm["IntegrationTime"] = mes.IntegrationTime;
    jm["IntegratedCps"] = mes.IntegratedCps;
    jm["CpsRsd"] = mes.CpsRsd;
    jm["Ash"] = mes.Ash;

    jm["Calibration"]["A"] = mes.Calibration.FactorA;
    jm["Calibration"]["B"] = mes.Calibration.FactorB;
    
    ml.add(jm);
  };

  //serializeJsonPretty(doc, Serial);

  /*
  String str;
  serializeJsonPretty(doc, str);

  xTaskCreateUniversal( 
    core0FileWrite, 
    "core0FileWrite", 
     4*configMINIMAL_STACK_SIZE, 
     ( void * ) str.c_str(), 
     configMAX_PRIORITIES-10, 
     NULL, 
     0
  );
  */

  serializeJsonPretty(doc, settingsFile);
  settingsFile.close();

  return true;
}