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
    return achordion_opposite_hands(tap_hold_record, other_record);
}

bool achordion_eager_mod(uint8_t mod) {
    // Apply all mods immediately at TAPPING_TERM
    return true;
}
