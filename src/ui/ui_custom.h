#ifndef UI_CUSTOM_H
#define UI_CUSTOM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

enum {
    LV_MENU_ITEM_BUILDER_VARIANT_1,
    LV_MENU_ITEM_BUILDER_VARIANT_2
};
typedef uint8_t lv_menu_builder_variant_t;

extern lv_obj_t * ui_tblMeasurements;

void ui_init_custom(void);
void ui_init_all(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif