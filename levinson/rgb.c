#include "rgb.h"

uint32_t shift_led = 7; // LED index for shift indicator
uint32_t gui_led = 15; // LED index for gui indicator


uint32_t layer_state_set_rgb(uint32_t state) {
    switch (biton32(state)) {
        case _QWERTY:
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(RGB_CLEAR);
    rgblight_setrgb_gold_at(shift_led);
            break;
        case _SYMB:
            rgblight_sethsv_noeeprom_red();
            break;
        case _NUMP:
            rgblight_sethsv_noeeprom_green();
            break;
        case _OVERWATCH:
            rgblight_sethsv_noeeprom_blue();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
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
    rgblight_setrgb_gold_at(shift_led);
}
