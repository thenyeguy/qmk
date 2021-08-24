#include QMK_KEYBOARD_H

enum layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum keycodes {
    ADJUST = SAFE_RANGE,
};

#define LOCK_SCR LCA(KC_L)
#define TERMINAL LCA(KC_T)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = EXPAND(LAYOUT_ergodox,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F5,
  __COLEMAK_ROW1_LEFT__,                                _______,
  __COLEMAK_ROW2_LEFT__,
  __COLEMAK_ROW3_LEFT__,                                _______,
  KC_LGUI, KC_LCTL, KC_LALT, ADJUST, MO(_LOWER),
                                               TERMINAL,LOCK_SCR,
                                                        KC_HOME,
                                     KC_SPC,   KC_DEL,  KC_END,

  RESET,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, __COLEMAK_ROW1_RIGHT__,
           __COLEMAK_ROW2_RIGHT__,
  _______, __COLEMAK_ROW3_RIGHT__,
                  MO(_RAISE),KC_DOWN,KC_UP,   KC_LEFT, KC_RGHT,
  KC_MPLY, _______,
  KC_PGUP,
  KC_PGDN, KC_BSPC,  KC_SPC
),

[_LOWER] = EXPAND(LAYOUT_ergodox,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
  __LOWER_ROW1_LEFT__,                                  _______,
  __LOWER_ROW2_LEFT__,
  __LOWER_ROW3_LEFT__,                                  _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, __LOWER_ROW1_RIGHT__,
           __LOWER_ROW2_RIGHT__,
  _______, __LOWER_ROW3_RIGHT__,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

[_RAISE] = EXPAND(LAYOUT_ergodox,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  __RAISE_ROW1_LEFT__,                                  _______,
  __RAISE_ROW2_LEFT__,
  __RAISE_ROW3_LEFT__,                                  _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, __RAISE_ROW1_RIGHT__,
           __RAISE_ROW2_RIGHT__,
  _______, __RAISE_ROW3_RIGHT__,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

[_ADJUST] = EXPAND(LAYOUT_ergodox,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  __ADJUST_ROW1_LEFT__,                                 _______,
  __ADJUST_ROW2_LEFT__,
  __ADJUST_ROW3_LEFT__,                                 _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, __ADJUST_ROW1_RIGHT__,
           __ADJUST_ROW2_RIGHT__,
  _______, __ADJUST_ROW3_RIGHT__,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

};

void led_set_user(uint8_t usb_led) {
  ergodox_right_led_3_set(LED_BRIGHTNESS_LO);
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    ergodox_right_led_3_on();
  } else {
    ergodox_right_led_3_off();
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_1_set(LED_BRIGHTNESS_LO);
  ergodox_right_led_2_set(LED_BRIGHTNESS_LO);

  uint8_t layer = biton32(state);
  switch (layer) {
      case _LOWER:
        ergodox_right_led_1_on();
        break;
      case _RAISE:
        ergodox_right_led_2_on();
        break;
      case _ADJUST:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      default:
        break;
    }

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
