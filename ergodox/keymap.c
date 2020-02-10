#include QMK_KEYBOARD_H

enum ergodox_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define CTL_SPC MT(MOD_LCTL, KC_SPC)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

#define LOCK_SCR LCA(KC_L)
#define TERMINAL LCA(KC_T)

#define BR_BACK LALT(KC_LEFT)
#define BR_FWD LALT(KC_RIGHT)

#define WKSP_LFT LGUI(KC_LEFT)
#define WKSP_RGT LGUI(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ergodox(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F5,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,
  ADJUST,  KC_LGUI, KC_LCTL, KC_LALT, LOWER,
                                               KC_DEL,  KC_MPLY,
                                                        KC_HOME,
                                      CTL_SPC, KC_LALT, KC_END,

  RESET,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
                    RAISE,   KC_DOWN, KC_UP,   KC_LEFT, KC_RGHT,
  LOCK_SCR,TERMINAL,
  KC_PGUP,
  KC_PGDN, KC_ENT,  KC_SPC
),

[_LOWER] = LAYOUT_ergodox(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  XXXXXXX, _______,
  _______, KC_GRV , KC_TILD, KC_PLUS, KC_EQL,  KC_PERC,
  _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX, _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, XXXXXXX, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, _______,
           KC_CIRC, KC_UNDS, KC_MINS, KC_LPRN, KC_RPRN, KC_DQT,
  _______, XXXXXXX, KC_PIPE, KC_LT,   KC_GT,   _______, _______,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

[_RAISE] = LAYOUT_ergodox(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
  _______, XXXXXXX, KC_EQL,  KC_MINS, KC_PLUS, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, KC_ASTR, KC_SLSH, XXXXXXX, _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
           XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
  _______, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
                    _______, KC_PGDN, KC_PGUP, KC_HOME, KC_END,
  _______, _______,
  _______,
  _______, _______, _______
),

[_ADJUST] = LAYOUT_ergodox(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, BR_BACK, BR_FWD,  XXXXXXX, XXXXXXX,
  KC_CAPS, XXXXXXX, WKSP_LFT,WKSP_RGT,XXXXXXX, XXXXXXX, _______,
  _______, _______, _______, _______, _______,
                                               KC_MPRV, KC_MNXT,
                                                        KC_VOLU,
                                      _______, _______, KC_VOLD,

  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,
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

uint32_t layer_state_set_user(uint32_t state) {
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

  return state;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      return false;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
    }
  return true;
}
