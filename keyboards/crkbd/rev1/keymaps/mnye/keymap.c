#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = EXPAND(LAYOUT,
    KC_TAB,  __BASE_ROW1_LEFT__, __BASE_ROW1_RIGHT__, KC_BSPC,
    KC_ESC,  __BASE_ROW2_LEFT__, __BASE_ROW2_RIGHT__, KC_ENT,
    KC_LSFT, __BASE_ROW3_LEFT__, __BASE_ROW3_RIGHT__, KC_RSFT,
    MO(_ADJUST), TL_LOWR, KC_SPC, KC_SPC, TL_UPPR, MO(_ADJUST)
),

[_LOWER] = EXPAND(LAYOUT,
    _______, __LOWER_ROW1_LEFT__, __LOWER_ROW1_RIGHT__, _______,
    _______, __LOWER_ROW2_LEFT__, __LOWER_ROW2_RIGHT__, _______,
    _______, __LOWER_ROW3_LEFT__, __LOWER_ROW3_RIGHT__, _______,
       _______, _______, _______, _______, _______, _______
),

[_RAISE] = EXPAND(LAYOUT,
    _______, __RAISE_ROW1_LEFT__, __RAISE_ROW1_RIGHT__, _______,
    _______, __RAISE_ROW2_LEFT__, __RAISE_ROW2_RIGHT__, _______,
    _______, __RAISE_ROW3_LEFT__, __RAISE_ROW3_RIGHT__, _______,
       _______, _______, _______, _______, _______, _______
),

[_ADJUST] = EXPAND(LAYOUT,
    _______, __ADJUST_ROW1_LEFT__, __ADJUST_ROW1_RIGHT__, KC_DEL,
    _______, __ADJUST_ROW2_LEFT__, __ADJUST_ROW2_RIGHT__, _______,
    _______, __ADJUST_ROW3_LEFT__, __ADJUST_ROW3_RIGHT__, _______,
        QK_BOOT, KC_LOCK, XXXXXXX, XXXXXXX, KC_MPLY, CG_TOGG
),

};
