#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define CTL_SPC MT(MOD_LCTL, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = EXPAND(LAYOUT_planck_grid,
    __QWERTY_ROW1_LEFT__, __QWERTY_ROW1_RIGHT__,
    __QWERTY_ROW2_LEFT__, __QWERTY_ROW2_RIGHT__,
    __QWERTY_ROW3_LEFT__, __QWERTY_ROW3_RIGHT__,

    KC_LCTL, KC_LGUI, _______, KC_LALT, LOWER,   CTL_SPC,
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
    __XXXXX_HALF__,       __XXXXX_HALF__,
    __XXXXX_HALF__,       __XXXXX_HALF__,
    __XXXXX_HALF__,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_SWAP, AG_NORM 
),

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
