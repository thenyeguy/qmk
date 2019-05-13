#include "rgb.h"

// TODO gate this debugging header
#include <print.h>

/* animation_status_t animation_status = {}; */

uint32_t layer_state_set_rgb(uint32_t state) {
    switch (biton32(state)) {
        case _QWERTY:
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(RGB_CLEAR);
             //rgblight_setrgb_gold_at(shift_led);
            break;
        case _SYMB:
            rgblight_sethsv_noeeprom_red();
            break;
        case _NUMP:
            rgblight_sethsv_noeeprom_green();
            break;
        case _OVERWATCH:
            rgblight_sethsv_noeeprom_blue();
            // TODO set up animated rainbow swirl with overwatch colors.
            // rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
            // rgblight_effect_breathing(&animation_status);
            // rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
            break;
        case _NAVI:
            rgblight_sethsv_noeeprom(HSV_AZURE);
            break;
        default: //  for any other layers, or the default layer
            break;
    }
    return state;
}

void keyboard_post_init_rgb(void) {
    rgblight_enable();
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_setrgb(RGB_CLEAR);
    uprintf("Reset RGB colors");
}

void matrix_scan_rgb(void) {
    set_rgb_indicators(get_mods(), get_oneshot_mods());
}

void set_rgb_indicators(uint8_t this_mod, uint8_t this_osm) {
    if (biton32(layer_state) == _QWERTY) {
        /* uprintf("MOD_MASK_SHIFT: %d\n", MOD_MASK_SHIFT); */
        /* uprintf("this_mod: %d, this_led: %d, this_osm: %d\n" ,this_mod, this_led, this_osm); */
        /* uprintf("MOD_BIT(KC_LSHIFT) %d\n", MOD_BIT(KC_LSHIFT)); */
        /* uprintf("this_mod %d\n"); */
        if ((this_mod | this_osm) & MOD_MASK_SHIFT) {
            /* rgblight_sethsv_at(120, 255, 255, SHFT_LED1); */
            rgblight_setrgb_gold_at(SHFT_LED1);
        } else {
            // TODO do intelligent clearing to current layer color
            rgblight_setrgb_at(RGB_CLEAR, SHFT_LED1);
        }

        if ((this_mod | this_osm) & MOD_MASK_GUI) {
            //rgblight_sethsv_at(255, 55, 255, GUI_LED1);
            rgblight_setrgb_purple_at(GUI_LED1);
            /* rgblight_setrgb_red_at(9); */
            /* rgblight_setrgb_yellow_at(10); */
            /* rgblight_setrgb_green_at(11); */
            /* rgblight_setrgb_blue_at(15); */
        } else {
            // TODO do intelligent clearing to current layer color
            rgblight_setrgb_at(RGB_CLEAR, GUI_LED1);
        }

    }
}
