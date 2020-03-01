#include QMK_KEYBOARD_H

enum corne_layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
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

[_COLEMAK] = EXPAND(LAYOUT,
    __COLEMAK_ROW1_LEFT__, __COLEMAK_ROW1_RIGHT__,
    __COLEMAK_ROW2_LEFT__, __COLEMAK_ROW2_RIGHT__,
    __COLEMAK_ROW3_LEFT__, __COLEMAK_ROW3_RIGHT__,
    KC_LALT, LOWER,   MOD_SPC, KC_SPC,  RAISE,   KC_LCTL
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
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SWAP_MOD
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
    }
  return true;
}
