#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
};

#define MOD_SPC MT(MOD_RGUI, KC_SPC)
#define SWAP_MOD MAGIC_TOGGLE_CTL_GUI

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

#define BR_BACK LGUI(KC_LBRC)
#define BR_FWD LGUI(KC_RBRC)

#define WKSP_LFT LALT(KC_LEFT)
#define WKSP_RGT LALT(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = EXPAND(LAYOUT_planck_grid,
    __QWERTY_ROW1_LEFT__, __QWERTY_ROW1_RIGHT__,
    __QWERTY_ROW2_LEFT__, __QWERTY_ROW2_RIGHT__,
    __QWERTY_ROW3_LEFT__, __QWERTY_ROW3_RIGHT__,

    ADJUST,  KC_LGUI, KC_LCTL, KC_LALT, LOWER,   MOD_SPC,
    KC_SPC,  RAISE,   KC_DOWN, KC_UP,   KC_LEFT, KC_RGHT
),

[_COLEMAK] = EXPAND(LAYOUT_planck_grid,
    __COLEMAK_ROW1_LEFT__, __COLEMAK_ROW1_RIGHT__,
    __COLEMAK_ROW2_LEFT__, __COLEMAK_ROW2_RIGHT__,
    __COLEMAK_ROW3_LEFT__, __COLEMAK_ROW3_RIGHT__,

    ADJUST,  KC_LGUI, KC_LCTL, KC_LALT, LOWER,   MOD_SPC,
    KC_SPC,  RAISE,   KC_DOWN, KC_UP,   KC_LEFT, KC_RGHT
),

[_LOWER] = EXPAND(LAYOUT_planck_grid,
    __LOWER_ROW1_LEFT__, __LOWER_ROW1_RIGHT__,
    __LOWER_ROW2_LEFT__, __LOWER_ROW2_RIGHT__,
    __LOWER_ROW3_LEFT__, __LOWER_ROW3_RIGHT__,
    __BLANK_HALF__,      _______, _______, KC_PGDN, KC_PGUP, KC_HOME, KC_END
),

[_RAISE] = EXPAND(LAYOUT_planck_grid,
    __RAISE_ROW1_LEFT__, __RAISE_ROW1_RIGHT__,
    __RAISE_ROW2_LEFT__, __RAISE_ROW2_RIGHT__,
    __RAISE_ROW3_LEFT__, __RAISE_ROW3_RIGHT__,
    __BLANK_HALF__,      _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_ADJUST] = EXPAND(LAYOUT_planck_grid,
    __ADJUST_ROW1_LEFT__, __ADJUST_ROW1_RIGHT__,
    __ADJUST_ROW2_LEFT__, __ADJUST_ROW2_RIGHT__,
    __ADJUST_ROW3_LEFT__, __ADJUST_ROW3_RIGHT__,
    __XXXXX_HALF__,       XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, QWERTY, SWAP_MOD
),

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
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
  }
  return true;
}
