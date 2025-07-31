SET(SOURCES screens/ui_Splash.c
    screens/ui_StandBy.c
    screens/ui_Measurments.c
    screens/ui_MeasureProgress.c
    screens/ui_Settings.c
    screens/ui_CalibrationEdit.c
    ui_theme_manager.cpp
    ui_themes.cpp
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.cpp
    images/ui_img_zolar_logo_png.c
    images/ui_img_battery_icons_png.c
    fonts/ui_font_fntDigital32.c
    fonts/ui_font_fntDigital64.c
    fonts/ui_font_fntSamsungSharpSans14.c
    fonts/ui_font_fntSamsungSharpSans32.c
    fonts/ui_font_fntSamsungSharpSans72.c
    fonts/ui_font_fntSamsungSharpSans96.c)

add_library(ui ${SOURCES})
