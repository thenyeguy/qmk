#include QMK_KEYBOARD_H

enum layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum keycodes {
    ADJUST = SAFE_RANGE,
    ENC_LEFT_RIGHT,
    ENC_UP_DOWN,
};


#define LOCK LGUI(LCTL(KC_Q))
#define SLEEP LCTL(LSFT(KC_POWER))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = EXPAND(LAYOUT,
    __COLEMAK_ROW1_LEFT__,                                                __COLEMAK_ROW1_RIGHT__,
    __COLEMAK_ROW2_LEFT__,                                                __COLEMAK_ROW2_RIGHT__,
    __COLEMAK_ROW3_LEFT__,              SLEEP,  LOCK,   KC_MPLY, XXXXXXX, __COLEMAK_ROW3_RIGHT__,
    ENC_LEFT_RIGHT, ADJUST, MO(_LOWER), KC_SPC, KC_DEL, KC_BSPC, KC_SPC,  MO(_RAISE), KC_RCTL, ENC_UP_DOWN
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

bool ENCODER_HELD = false;

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (ENCODER_HELD) {
            tap_code(clockwise ? KC_END : KC_HOME);
        } else {
            tap_code(clockwise ? KC_RIGHT : KC_LEFT);
        }
    } else if (index == 1) {
        if (ENCODER_HELD) {
            tap_code(clockwise ? KC_PGDN : KC_PGUP);
        } else {
            tap_code(clockwise ? KC_DOWN : KC_UP);
        }
    }
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
    case ENC_LEFT_RIGHT:
    case ENC_UP_DOWN:
      ENCODER_HELD = record->event.pressed;
      return false;
  }
  return true;
}
