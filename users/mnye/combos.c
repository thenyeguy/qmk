#include QMK_KEYBOARD_H

const uint16_t PROGMEM combo_rs[] = {LCTL_T(KC_R), LALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM combo_st[] = {LALT_T(KC_S), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM combo_ne[] = {RSFT_T(KC_N), RALT_T(KC_E), COMBO_END};
const uint16_t PROGMEM combo_ei[] = {RALT_T(KC_E), RCTL_T(KC_I), COMBO_END};
const uint16_t PROGMEM combo_kh[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM combo_hcomma[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_commadot[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_dotslsh[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_zx[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_xc[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_rs, KC_ESC),
    COMBO(combo_st, KC_BSPC),
    COMBO(combo_ne, KC_TAB),
    COMBO(combo_ei, KC_ENT),
    COMBO(combo_kh, KC_LEFT),
    COMBO(combo_hcomma, KC_DOWN),
    COMBO(combo_commadot, KC_UP),
    COMBO(combo_dotslsh, KC_RGHT),
    COMBO(combo_zx, LCTL(KC_LEFT)),
    COMBO(combo_xc, LCTL(KC_RGHT)),
};
