#include "ui_custom.h"
#include "ui.h"
#include "ui_functions.h"

lv_obj_t * ui_tblMeasurements = NULL;
lv_obj_t * ui_settingsMenu = NULL;
lv_obj_t * ui_menuRootPage = NULL;
lv_obj_t * ui_menuCalibrationsPage = NULL;
lv_obj_t * ui_menuCalibrationEditPage = NULL;
lv_obj_t * ui_menuTimesetsPage = NULL;

lv_obj_t * ui_spinboxFactorA = NULL;
lv_obj_t * ui_spinboxFactorB = NULL;

void ui_initMeasurmentsTable(){
    ui_tblMeasurements = lv_table_create(ui_Measurments);

    lv_obj_set_height(ui_tblMeasurements, 160);
    lv_obj_set_width(ui_tblMeasurements, 400);
    lv_obj_set_y(ui_tblMeasurements, -20);
    lv_obj_set_align(ui_tblMeasurements, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_tblMeasurements, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
};

void ui_init_custom(void){
    ui_initMeasurmentsTable(); 
};

void ui_init_all(void){
    ui_init();
    ui_init_custom();
}