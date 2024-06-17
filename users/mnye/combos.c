#include QMK_KEYBOARD_H

const uint16_t PROGMEM combo_rs[] = {LCTL_T(KC_R), LALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM combo_st[] = {LALT_T(KC_S), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM combo_ne[] = {RSFT_T(KC_N), RALT_T(KC_E), COMBO_END};
const uint16_t PROGMEM combo_ei[] = {RALT_T(KC_E), RCTL_T(KC_I), COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_rs, KC_ESC),
    COMBO(combo_st, KC_TAB),
    COMBO(combo_ne, KC_BSPC),
    COMBO(combo_ei, KC_ENT),
};
