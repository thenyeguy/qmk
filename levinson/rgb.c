#include "rgb.h"

uint32_t layer_state_set_rgb(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
    if (userspace_config.rgb_layer_change) {
        switch (biton32(state)) {
            case _QWERTY:
              rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
              rgblight_sethsv_noeeprom(RGB_CLEAR);
                rgblight_sethsv_noeeprom_chartreuse();
                break;
            case _SYMB:
                rgblight_sethsv_noeeprom_orange();
                rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 2);
                break;
            case _NUMP:
                rgblight_sethsv_noeeprom_goldenrod();
                rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 1);
                break;
            case _OVERWATCH:
                rgblight_sethsv_noeeprom_cyan();
                rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
                break;
            default: //  for any other layers, or the default layer
                switch (biton32(default_layer_state)) {
                    case _MALTRON:
                        rgblight_sethsv_noeeprom_yellow(); break;
                    case _EUCALYN:
                        rgblight_sethsv_noeeprom_pink(); break;
                    case _CARPLAX:
                        rgblight_sethsv_noeeprom_blue(); break;
                    default:
                        rgblight_sethsv_noeeprom_cyan(); break;
                }
                biton32(state) == _MODS ? rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING) : rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // if _MODS layer is on, then breath to denote it
                break;
        }
    }
#endif // RGBLIGHT_ENABLE

    return state;
}
