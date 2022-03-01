#include QMK_KEYBOARD_H

enum layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum keycodes {
    ADJUST = SAFE_RANGE,
    ENC_NAV,
    ENC_MEDIA,
};


#define LOCK LGUI(KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = EXPAND(LAYOUT,
    __COLEMAK_ROW1_LEFT__,                                          __COLEMAK_ROW1_RIGHT__,
    __COLEMAK_ROW2_LEFT__,                                          __COLEMAK_ROW2_RIGHT__,
    __COLEMAK_ROW3_LEFT__,       KC_BSPC, KC_RGHT, KC_UP,   KC_ENT, __COLEMAK_ROW3_RIGHT__,
    ENC_NAV, ADJUST, MO(_LOWER), KC_SPC,  KC_LEFT, KC_DOWN, KC_SPC, MO(_RAISE), KC_RCTL, ENC_MEDIA
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
    __ADJUST_ROW1_LEFT__,                                              __ADJUST_ROW1_RIGHT__,
    __ADJUST_ROW2_LEFT__,                                              __ADJUST_ROW2_RIGHT__,
    __ADJUST_ROW3_LEFT__,          _______, _______, _______, _______, __ADJUST_ROW3_RIGHT__,
    MAGIC_TOGGLE_CTL_GUI, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
      return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        tap_code16(clockwise ? LGUI(KC_RIGHT) : LGUI(KC_LEFT));
        return false;
    } else if (index == 1) {
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
        return false;
    }
    return true;
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
    case ENC_NAV:
      if (record->event.pressed) {
        tap_code16(LOCK);
      }
      return false;
    case ENC_MEDIA:
      if (record->event.pressed) {
        tap_code(KC_MPLY);
      }
      return false;
  }
  return true;
}
