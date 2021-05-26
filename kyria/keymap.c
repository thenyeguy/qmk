#include QMK_KEYBOARD_H

enum layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOCK LGUI(LCTL(KC_Q))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = EXPAND(LAYOUT,
    __COLEMAK_ROW1_LEFT__,                                            __COLEMAK_ROW1_RIGHT__,
    __COLEMAK_ROW2_LEFT__,                                            __COLEMAK_ROW2_RIGHT__,
    __COLEMAK_ROW3_LEFT__,        XXXXXXX, KC_MPLY, LOCK,    XXXXXXX, __COLEMAK_ROW3_RIGHT__,
    XXXXXXX, KC_LALT, MO(_LOWER), KC_SPC,  KC_DEL,  KC_BSPC, KC_SPC,  MO(_RAISE),   KC_RCTL, XXXXXXX
),

[_LOWER] = EXPAND(LAYOUT,
    __LOWER_ROW1_LEFT__,                                           __LOWER_ROW1_RIGHT__,
    __LOWER_ROW2_LEFT__,                                           __LOWER_ROW2_RIGHT__,
    __LOWER_ROW3_LEFT__,       _______, _______, _______, _______, __LOWER_ROW3_RIGHT__,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = EXPAND(LAYOUT,
    __RAISE_ROW1_LEFT__,                                           __RAISE_ROW1_RIGHT__,
    __RAISE_ROW2_LEFT__,                                           __RAISE_ROW2_RIGHT__,
    __RAISE_ROW3_LEFT__,       _______, _______, _______, _______, __RAISE_ROW3_RIGHT__,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = EXPAND(LAYOUT,
    __ADJUST_ROW1_LEFT__,                                          __ADJUST_ROW1_RIGHT__,
    __ADJUST_ROW2_LEFT__,                                          __ADJUST_ROW2_RIGHT__,
    __ADJUST_ROW3_LEFT__,      _______, _______, _______, _______, __ADJUST_ROW3_RIGHT__,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
      return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        tap_code(clockwise ? KC_RIGHT : KC_LEFT);
    } else if (index == 1) {
        tap_code(clockwise ? KC_DOWN : KC_UP);
    }
}
