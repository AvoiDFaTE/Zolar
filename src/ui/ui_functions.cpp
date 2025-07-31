#include "ui_functions.h"

typedef struct calibration_edit_data_t {
    uint16_t index;
    calibration_t * calibration;
} calibration_edit_data_t;


void uiBuzzerBeep(){
  lv_timer_create([](lv_timer_t * timer) {
                                          lv_timer_del(timer);
                                          Set_EXIO(PinBuzzerEXIO, LOW);   
                                         }
                  ,300, NULL); 
  Set_EXIO(PinBuzzerEXIO, HIGH);  
}

void uiUpdateOnGetCPS(cps_t cps){
    lv_label_set_text_fmt(ui_lbCurrentCPSval, "%d", cps.AvgCps);

    lv_chart_set_next_value(ui_chtCpsHistory, lv_chart_get_series_next(ui_chtCpsHistory, NULL), cps.AvgCps);
}

void setUIbattery(lv_timer_t * timer){
  uint16_t xOffset,
           yOffset;
  switch(BAT_Get_State()){
		case ESPBATTERY_CHARGING:
      xOffset = 30;
      yOffset = 32;    
		case ESPBATTERY_FULL:
      xOffset = 30;
      yOffset = 0;
		case ESPBATTERY_LOW:
      xOffset = 0;
      yOffset = 16;    
		case ESPBATTERY_CRITICAL:
      xOffset = 0;
      yOffset = 0;    
    default: // ESPBATTERY_OK
      xOffset = 30;
      yOffset = 16;   
  }  

  lv_img_set_offset_x(ui_imgBattery, xOffset);
  lv_img_set_offset_y(ui_imgBattery, yOffset);
}

void setUIdatetime(lv_timer_t * timer){
  lv_label_set_text_fmt(ui_lbDate, "%02d.%02d.%u", datetime.day, datetime.month, datetime.year);
  lv_label_set_text_fmt(ui_lbClock, "%02d:%02d", datetime.hour, datetime.minute);
}

void setUIstandByData(lv_timer_t * timer){
  if(!Calc.canBeginMeasure()){
    lv_obj_add_state(ui_btnStart, LV_STATE_DISABLED);  
  } else {
    lv_obj_clear_state(ui_btnStart, LV_STATE_DISABLED);
  }  
}

void setUImeasureProgressData(lv_timer_t * timer){
  if(!Calc.canEndMeasure()){
    lv_obj_add_flag(ui_pnStop, LV_OBJ_FLAG_HIDDEN);      
  } else {
    lv_obj_clear_flag(ui_pnStop, LV_OBJ_FLAG_HIDDEN);
  }  

  if(Calc.getState() != MeasureState::Measure){
    lv_obj_add_flag(ui_lbMeasurementRemaingTime, LV_OBJ_FLAG_HIDDEN);      
  } else {
    lv_obj_clear_flag(ui_lbMeasurementRemaingTime, LV_OBJ_FLAG_HIDDEN);      
    lv_label_set_text_fmt(ui_lbMeasurementRemaingTime, "%d", Calc.getMeasurementRemainingSeconds());
    
    lv_label_set_text_fmt(ui_lbAvgCPSvalue, "%.2f", Calc.getCurrentMeasurment().IntegratedCps);
    lv_label_set_text_fmt(ui_lbCPSrsdValue, "%.2f%%", Calc.getCurrentMeasurment().CpsRsd);    
  }
}

void uiUpdateOnTimer(lv_timer_t * timer){
  setUIdatetime(timer);
  setUIbattery(timer);

  if(lv_scr_act() == ui_StandBy){
    setUIstandByData(timer);
  }
  else if(lv_scr_act() == ui_MeasureProgress){
    setUImeasureProgressData(timer);
  }
}

void uiFillScreenStandBy(){
  lv_label_set_text(ui_lbCalName, GS.Calibrations[GS.ActiveCalibration].Name.c_str());
  lv_label_set_text_fmt(ui_lbFactorAvalue, "%.2f", GS.Calibrations[GS.ActiveCalibration].FactorA);
  lv_label_set_text_fmt(ui_lbFactorBvalue, "%.1f", GS.Calibrations[GS.ActiveCalibration].FactorB);
  lv_label_set_text_fmt(ui_lbTimeValue, "%d", GS.Timesets[GS.ActiveTimeset]);
}

void uiFillScreenMeasurements(){
  lv_table_set_row_cnt(ui_tblMeasurements, GS.Measurements.size() / 3 + GS.Measurements.size() % 3); 
  lv_table_set_col_cnt(ui_tblMeasurements, 3); 

  uint16_t row = 0, col = 0, i = 0;
  for (auto measurement : GS.Measurements){
    i++;

    if(col > 2){
      row++;
      col = 0;
    }

    lv_table_set_cell_value_fmt(ui_tblMeasurements, row, col, "%d: %.2f %%Ad", i, measurement.Ash);            
    col++;
  };

  lv_label_set_text_fmt(ui_lbAvgAshValue, "%.2f%%", Calc.getAveraged().AvgAsh);
	lv_label_set_text_fmt(ui_lbRsdValue, "%.2f%%", Calc.getAveraged().RelativeStdDeviation);

  if(GS.Measurements.size()>0){
    lv_obj_clear_flag(ui_pnClear, LV_OBJ_FLAG_HIDDEN);      
  } else {
    lv_obj_add_flag(ui_pnClear, LV_OBJ_FLAG_HIDDEN);      
  }
}

void uiBeginMeasure(){
  if(Calc.canBeginMeasure()){
    lv_obj_add_flag(ui_pnNext, LV_OBJ_FLAG_HIDDEN);		
    lv_obj_add_flag(ui_pnStop, LV_OBJ_FLAG_HIDDEN);		
    lv_obj_add_flag(ui_pnMP2Measurements, LV_OBJ_FLAG_HIDDEN);		

    lv_obj_add_flag(ui_lbMeasurementAsh, LV_OBJ_FLAG_HIDDEN);		
    lv_obj_add_flag(ui_lbMeasurementAshValue, LV_OBJ_FLAG_HIDDEN);		
    lv_obj_add_flag(ui_lbMeasurementCount, LV_OBJ_FLAG_HIDDEN);		
    lv_obj_add_flag(ui_lbMeasurementCountValue, LV_OBJ_FLAG_HIDDEN);		

    beginMeasure();

    _ui_screen_change(&ui_MeasureProgress, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_MeasureProgress_screen_init);
  }
}

void uiStopMeasure(){
	stopMeasure();
}

void uiMeasureEnded(){
    if(Calc.canBeginMeasure()){
		  lv_obj_clear_flag(ui_pnNext, LV_OBJ_FLAG_HIDDEN);		
    } else {
      lv_obj_add_flag(ui_pnNext, LV_OBJ_FLAG_HIDDEN);		      
    }
    lv_obj_clear_flag(ui_pnMP2Measurements, LV_OBJ_FLAG_HIDDEN);		

		lv_label_set_text_fmt(ui_lbMeasurementAshValue, "%.2f %%Ad", Calc.getCurrentMeasurment().Ash);
		lv_label_set_text_fmt(ui_lbMeasurementCountValue, "%d/%d", Calc.getMeasurements().size(), GS.MaxMeasurementsCount);

		lv_obj_clear_flag(ui_lbMeasurementAsh, LV_OBJ_FLAG_HIDDEN);		
		lv_obj_clear_flag(ui_lbMeasurementAshValue, LV_OBJ_FLAG_HIDDEN);		
		lv_obj_clear_flag(ui_lbMeasurementCount, LV_OBJ_FLAG_HIDDEN);		
		lv_obj_clear_flag(ui_lbMeasurementCountValue, LV_OBJ_FLAG_HIDDEN);		
}

void uiClearMeasurements(){
  clearMeasurements();
}

void uiFillScreenSettings(){
  lv_dropdown_clear_options(ui_ddSettingsCalibration);
  for(auto cal : GScopyForMenu.Calibrations ){
    lv_dropdown_add_option(ui_ddSettingsCalibration, cal.Name.c_str(), LV_DROPDOWN_POS_LAST);    
  }
  lv_dropdown_set_selected(ui_ddSettingsCalibration, GScopyForMenu.ActiveCalibration);

  lv_dropdown_clear_options(ui_ddSettingsTimeset);
  char buf[16];
  for(auto ts : GScopyForMenu.Timesets ){    
    lv_snprintf(buf,sizeof(buf), "%d sec", ts);
    lv_dropdown_add_option(ui_ddSettingsTimeset, buf, LV_DROPDOWN_POS_LAST);    
  }
  lv_dropdown_set_selected(ui_ddSettingsTimeset, GScopyForMenu.ActiveTimeset);  
}

void uiEnterSettingsMenu(){
  GScopyForMenu = GS;

  uiFillScreenSettings();

  _ui_screen_change(&ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Settings_screen_init);   
}

void uiLeaveSettingsMenu(){
  GS = GScopyForMenu;

  saveSettings();

  _ui_screen_change(&ui_StandBy, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_StandBy_screen_init);   
}

void uiEnterCalibrationEdit(){
  uint16_t idx = lv_dropdown_get_selected(ui_ddSettingsCalibration);
  lv_textarea_set_text(ui_taName, GScopyForMenu.Calibrations[idx].Name.c_str());
  lv_spinbox_set_value(ui_sbFactorA, GScopyForMenu.Calibrations[idx].FactorA * FactorAtoSpinboxMultiplier);
  lv_spinbox_set_value(ui_sbFactorB, GScopyForMenu.Calibrations[idx].FactorB * FactorBtoSpinboxMultiplier);

  _ui_screen_change(&ui_CalibrationEdit, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_CalibrationEdit_screen_init);   
}

void uiLeaveCalibrationEdit(bool save){
  if(save){
    uint16_t idx = lv_dropdown_get_selected(ui_ddSettingsCalibration);

    GScopyForMenu.Calibrations[idx].Name = lv_textarea_get_text(ui_taName);
    GScopyForMenu.Calibrations[idx].FactorA = (float) lv_spinbox_get_value(ui_sbFactorA) / FactorAtoSpinboxMultiplier;
    GScopyForMenu.Calibrations[idx].FactorB = (float) lv_spinbox_get_value(ui_sbFactorB) / FactorBtoSpinboxMultiplier;

    uiFillScreenSettings();
  }

  _ui_screen_change(&ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Settings_screen_init);     
}

void uiEnterWebSettings(){
  char msg[256];
  lv_snprintf(msg,sizeof(msg), "SSID: %s\nPassword: %s\nHost: %s", GScopyForMenu.apSSID.c_str(), GScopyForMenu.apPassword.c_str(), GScopyForMenu.apHostname.c_str());
  static const char * btns[] = {"Close", ""};

  lv_obj_t * mbox = lv_msgbox_create(ui_Settings, "Web settings page started over Wifi AP", msg, btns, false);
  lv_obj_add_event_cb(mbox, 
                      [](lv_event_t * e) {
                                           lv_obj_t * obj = lv_event_get_current_target(e);
                                           if(strcmp(lv_msgbox_get_active_btn_text(obj), "Close") == 0){
                                             stopWebSettings();
                                             uiFillScreenSettings();
                                             lv_msgbox_close(obj);                                              
                                           }
                                         },
                      LV_EVENT_VALUE_CHANGED,
                      NULL);
  lv_obj_center(mbox);

  startWebSettings();
}

void uiChangeCalibration(){
  GScopyForMenu.ActiveCalibration = lv_dropdown_get_selected(ui_ddSettingsCalibration);   
}

void uiChangeTimeset(){
  GScopyForMenu.ActiveTimeset = lv_dropdown_get_selected(ui_ddSettingsTimeset);  
}