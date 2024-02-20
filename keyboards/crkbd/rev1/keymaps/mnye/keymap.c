#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum keycodes {
    ADJUST = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = EXPAND(LAYOUT,
    __BASE_ROW1_LEFT__, __BASE_ROW1_RIGHT__,
    __BASE_ROW2_LEFT__, __BASE_ROW2_RIGHT__,
    __BASE_ROW3_LEFT__, __BASE_ROW3_RIGHT__,
    ADJUST, MO(_LOWER), KC_SPC, KC_SPC, MO(_RAISE), ADJUST
),

[_LOWER] = EXPAND(LAYOUT,
    __LOWER_ROW1_LEFT__,       __LOWER_ROW1_RIGHT__,
    __LOWER_ROW2_LEFT__,       __LOWER_ROW2_RIGHT__,
    __LOWER_ROW3_LEFT__,       __LOWER_ROW3_RIGHT__,
    _______, _______, _______, _______, _______, _______
),

[_RAISE] = EXPAND(LAYOUT,
    __RAISE_ROW1_LEFT__,        __RAISE_ROW1_RIGHT__,
    __RAISE_ROW2_LEFT__,        __RAISE_ROW2_RIGHT__,
    __RAISE_ROW3_LEFT__,        __RAISE_ROW3_RIGHT__,
    _______, _______, _______, _______, _______, _______
),

[_ADJUST] = EXPAND(LAYOUT,
    __ADJUST_ROW1_LEFT__,      __ADJUST_ROW1_RIGHT__,
    __ADJUST_ROW2_LEFT__,      __ADJUST_ROW2_RIGHT__,
    __ADJUST_ROW3_LEFT__,      __ADJUST_ROW3_RIGHT__,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAGIC_TOGGLE_CTL_GUI
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
