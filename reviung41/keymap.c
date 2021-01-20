#include QMK_KEYBOARD_H

enum layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOCK LGUI(LCTL(KC_Q))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = EXPAND(LAYOUT_reviung41,
    __COLEMAK_ROW1_LEFT__, __COLEMAK_ROW1_RIGHT__,
    __COLEMAK_ROW2_LEFT__, __COLEMAK_ROW2_RIGHT__,
    __COLEMAK_ROW3_LEFT__, __COLEMAK_ROW3_RIGHT__,
    KC_MPLY, MO(_LOWER), KC_SPC, MO(_RAISE), LOCK
),

[_LOWER] = EXPAND(LAYOUT_reviung41,
    __LOWER_ROW1_LEFT__, __LOWER_ROW1_RIGHT__,
    __LOWER_ROW2_LEFT__, __LOWER_ROW2_RIGHT__,
    __LOWER_ROW3_LEFT__, __LOWER_ROW3_RIGHT__,
    _______, _______, _______, _______, _______
),

[_RAISE] = EXPAND(LAYOUT_reviung41,
    __RAISE_ROW1_LEFT__, __RAISE_ROW1_RIGHT__,
    __RAISE_ROW2_LEFT__, __RAISE_ROW2_RIGHT__,
    __RAISE_ROW3_LEFT__, __RAISE_ROW3_RIGHT__,
    _______, _______, _______, _______, _______
),

[_ADJUST] = EXPAND(LAYOUT_reviung41,
    __ADJUST_ROW1_LEFT__, __ADJUST_ROW1_RIGHT__,
    __ADJUST_ROW2_LEFT__, __ADJUST_ROW2_RIGHT__,
    __ADJUST_ROW3_LEFT__, __ADJUST_ROW3_RIGHT__,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
      return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
