#include QMK_KEYBOARD_H

const uint16_t PROGMEM combo_wf[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_uy[] = {KC_U, KC_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_wf, KC_TAB),
    COMBO(combo_uy, KC_BSPC),
};
