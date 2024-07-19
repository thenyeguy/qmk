#include "features/achordion.h"

void matrix_scan_user(void) {
    achordion_task();
}

// Define a weak per-keymap handler to allow keymap files to add more custom keycodes.
__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }
    return process_record_keymap(keycode, record);
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    // Always allow chording with space:
    if (other_keycode == KC_SPC) {
        return true;
    }

    // Allow specific shortcuts with left hand.
    switch (tap_hold_keycode) {
        case LGUI_T(KC_A): {
            switch (other_keycode) {
                case KC_X:
                case KC_C:
                case KC_V:
                case KC_W: return true;
                default: break;
            }
        }
        case LCTL_T(KC_R): {
            switch (other_keycode) {
                case KC_C: return true;
                case KC_D: return true;
                default: break;
            }
        }
        default: break;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

bool achordion_eager_mod(uint8_t mod) {
    // Apply all mods immediately at TAPPING_TERM
    return true;
}
