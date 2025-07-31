#include "WebSettings.h"

#include <GyverPortal.h>
#include <lvgl.h>
#include <LittleFS.h>
#include "RTC_PCF85063.h"
#include "Constants.h"

GyverPortal ui;

IPAddress apIP(192, 168, 1, 1);

lv_timer_t * portalLoopTimer = NULL;

void portalLoop(lv_timer_t * timer) {
  ui.tick();
}

GPdate valDate;
GPtime valTime;

void build() {
  GP.BUILD_BEGIN();
  GP.THEME(GP_DARK);

  GP.TITLE("Zolar", "t1");
  GP.HR();

  GP.NAV_TABS_LINKS("/,/logfile,/fwupdate", "Settings,Log file,Firmware update");
  GP.HR();

  if (ui.uri("/")) {
    String concat;
    for(uint16_t i=0; i < GScopyForMenu.Timesets.size(); i++){
        concat = concat + String(GScopyForMenu.Timesets[i]) + String((i < GScopyForMenu.Timesets.size() - 1) ? "," : "");
    }

    GP.BLOCK_TAB_BEGIN("Measure settings");
    M_BOX(GP.LABEL("Timeset");   GP.SELECT("tsSelect", concat.c_str(), GScopyForMenu.ActiveCalibration); );

    GP.LABEL("Calibrations");
    for(uint16_t i=0; i < GScopyForMenu.Calibrations.size(); i++){
        M_BOX( GP.RADIO("calRadio", i, GScopyForMenu.ActiveCalibration); GP.LABEL("Name:"); GP.TEXT(String("calNameText/")+i, "", GScopyForMenu.Calibrations[i].Name); )
        M_BOX( GP.LABEL("A:"); GP.NUMBER_F(String("calFactorA/")+i, "", GScopyForMenu.Calibrations[i].FactorA); GP.LABEL("B:"); GP.NUMBER_F(String("calFactorB/")+i, "", GScopyForMenu.Calibrations[i].FactorB); )
    }

    M_BOX( GP.LABEL("Max measurements:"); GP.NUMBER("maxMesurementsNum", "", GScopyForMenu.MaxMeasurementsCount); )

    M_BOX( GP.LABEL("Min time:"); GP.NUMBER("minMesurementTimeNum", "", GScopyForMenu.MinMeasureTime); GP.LABEL("sec"); )

    M_BOX( GP.LABEL("Max CPS RSD < :"); GP.NUMBER_F("cpsRsdFloat", "", GScopyForMenu.CpsRsdThreshold); GP.LABEL("%"); )

    GP.BLOCK_END();

    GP.HR();

    datetime_t currentTime;
    PCF85063_Read_Time(&currentTime);
    valDate.set(currentTime.day, currentTime.month, currentTime.year);
    valTime.set(currentTime.hour, currentTime.minute, currentTime.second);

    M_BLOCK_TAB(
        "Others",
        GP.LABEL("Others");
        M_BOX( GP.LABEL("Date:"); GP.DATE("date", valDate); );
        M_BOX( GP.LABEL("Time:"); GP.TIME("time", valTime); );
    );
  }
  else if(ui.uri("/logfile")){
    GP.BLOCK_TAB_BEGIN("Log file content");
    GP.EMBED(LogFilePath);
    M_BOX( GP.BUTTON_DOWNLOAD(LogFilePath, "Download"); GP.CONFIRM("cfmT", "Are you sure truncate log file?"); GP.BUTTON("btnTruncate","Truncate"); GP.UPDATE_CLICK("cfmT", "btnTruncate"); );
    GP.BLOCK_END();
  }
  
  GP.BUILD_END();
}

void action() {
  if (ui.click()) {
    if (ui.clickInt("tsSelect", GScopyForMenu.ActiveTimeset)) {
    }

    if (ui.clickInt("calRadio", GScopyForMenu.ActiveCalibration)) {
    }

    String sub = ui.clickNameSub(1);
    uint16_t subIndex;
    if(sub!=""){
      subIndex = sub.toInt();
    }

    if (ui.clickSub("calNameText")) { 
      GScopyForMenu.Calibrations[subIndex].Name = ui.getString();        
    }

    if (ui.clickSub("calFactorA")) { 
      GScopyForMenu.Calibrations[subIndex].FactorA = ui.getFloat();        
    }

    if (ui.clickSub("calFactorB")) { 
      GScopyForMenu.Calibrations[subIndex].FactorB = ui.getFloat();        
    }

    if (ui.clickInt("maxMesurementsNum", GScopyForMenu.MaxMeasurementsCount)) {
    }

    if (ui.clickInt("minMesurementTimeNum", GScopyForMenu.MinMeasureTime)) {
    }

    if (ui.clickFloat("cpsRsdFloat", GScopyForMenu.CpsRsdThreshold)) {        
    }

    if (ui.clickDate("date", valDate)) {
      datetime_t dt;
      
      dt.day = valDate.day;
      dt.month = valDate.month;
      dt.year = valDate.year;

      PCF85063_Set_Date(dt);
    }

    if (ui.clickTime("time", valTime)) {
      datetime_t dt;
      
      dt.hour = valTime.hour;
      dt.minute = valTime.minute;
      dt.second = valTime.second;

      PCF85063_Set_Time(dt);
    }

    if (ui.click("cfmT") && ui.getBool()) {
      File f = LittleFS.open(LogFilePath, FILE_WRITE);
      f.close();
    }            
  } 

  if (ui.update("cfmT")) {
      ui.answer(1);
  }

  if (ui.download()) {
    ui.sendFile(LittleFS.open(ui.uri(), FILE_READ));
  }
}

void startWebSettings(){
  WiFi.mode(WIFI_MODE_AP);

  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(GScopyForMenu.apSSID, GScopyForMenu.apPassword);

  ui.attachBuild(build);
  ui.attach(action);
  ui.start(GScopyForMenu.apHostname.c_str());

  ui.downloadAuto(0);  

  portalLoopTimer = lv_timer_create(portalLoop, 1, NULL);
};

void stopWebSettings(){
    lv_timer_del(portalLoopTimer);
    ui.stop();
    WiFi.softAPdisconnect(true);
};