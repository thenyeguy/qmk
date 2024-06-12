#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum keycodes {
    ENC_NAV = SAFE_RANGE,
    ENC_MEDIA,
};


#define LOCK LGUI(LCTL(KC_Q))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = EXPAND(LAYOUT,
    __BASE_ROW1_LEFT__,                                               __BASE_ROW1_RIGHT__,
    __BASE_ROW2_LEFT__,                                               __BASE_ROW2_RIGHT__,
    __BASE_ROW3_LEFT__,            KC_BSPC, KC_RGHT, KC_UP,   KC_ENT, __BASE_ROW3_RIGHT__,
    ENC_NAV, MO(_ADJUST), TL_LOWR, KC_SPC,  KC_LEFT, KC_DOWN, KC_SPC, TL_UPPR, MO(_ADJUST), ENC_MEDIA
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
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        tap_code16(clockwise ? LCTL(KC_RIGHT) : LCTL(KC_LEFT));
        return false;
    } else if (index == 1) {
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
