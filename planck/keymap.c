#include QMK_KEYBOARD_H

enum layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum keycodes {
    ADJUST = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = EXPAND(LAYOUT_planck_grid,
    __COLEMAK_ROW1_LEFT__, __COLEMAK_ROW1_RIGHT__,
    __COLEMAK_ROW2_LEFT__, __COLEMAK_ROW2_RIGHT__,
    __COLEMAK_ROW3_LEFT__, __COLEMAK_ROW3_RIGHT__,

    KC_LGUI, KC_LCTL,    KC_LALT, ADJUST, MO(_LOWER), KC_SPC,
    KC_SPC,  MO(_RAISE), KC_DOWN, KC_UP,  KC_LEFT,    KC_RGHT
),

[_LOWER] = EXPAND(LAYOUT_planck_grid,
    __LOWER_ROW1_LEFT__, __LOWER_ROW1_RIGHT__,
    __LOWER_ROW2_LEFT__, __LOWER_ROW2_RIGHT__,
    __LOWER_ROW3_LEFT__, __LOWER_ROW3_RIGHT__,
    __BLANK_HALF__,      __BLANK_HALF__
),

[_RAISE] = EXPAND(LAYOUT_planck_grid,
    __RAISE_ROW1_LEFT__, __RAISE_ROW1_RIGHT__,
    __RAISE_ROW2_LEFT__, __RAISE_ROW2_RIGHT__,
    __RAISE_ROW3_LEFT__, __RAISE_ROW3_RIGHT__,
    __BLANK_HALF__,      __BLANK_HALF__
),

[_ADJUST] = EXPAND(LAYOUT_planck_grid,
    __ADJUST_ROW1_LEFT__, __ADJUST_ROW1_RIGHT__,
    __ADJUST_ROW2_LEFT__, __ADJUST_ROW2_RIGHT__,
    __ADJUST_ROW3_LEFT__, __ADJUST_ROW3_RIGHT__,
    MAGIC_TOGGLE_CTL_GUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    __XXXXX_HALF__
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
      return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_LOWER);
        layer_on(_RAISE);
      } else {
        layer_off(_LOWER);
        layer_off(_RAISE);
      }
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      return false;
  }
  return true;
}
