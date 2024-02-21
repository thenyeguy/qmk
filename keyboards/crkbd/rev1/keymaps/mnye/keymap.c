#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = EXPAND(LAYOUT,
    __BASE_ROW1_LEFT__, __BASE_ROW1_RIGHT__,
    __BASE_ROW2_LEFT__, __BASE_ROW2_RIGHT__,
    __BASE_ROW3_LEFT__, __BASE_ROW3_RIGHT__,
    MO(_ADJUST), TL_LOWR, KC_SPC, KC_SPC, TL_UPPR, MO(_ADJUST)
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
