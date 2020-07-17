#pragma once

// This macro is needed to ensure row macros get expanded properly.
#define EXPAND(layout, ...) layout(__VA_ARGS__)


// -------------
// Generic rows:
#define __BLANK_HALF__ _______, _______, _______, _______, _______, _______
#define __XXXXX_HALF__ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX


// -------------
// Qwerty layer:
#define __QWERTY_ROW1_LEFT__   KC_TAB,  KC_Q,  KC_W,    KC_E,   KC_R,    KC_T
#define __QWERTY_ROW1_RIGHT__  KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,    KC_BSPC
#define __QWERTY_ROW2_LEFT__   KC_ESC,  KC_A,  KC_S,    KC_D,   KC_F,    KC_G
#define __QWERTY_ROW2_RIGHT__  KC_H,    KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT
#define __QWERTY_ROW3_LEFT__   KC_LSFT, KC_Z,  KC_X,    KC_C,   KC_V,    KC_B
#define __QWERTY_ROW3_RIGHT__  KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT


// --------------------
// Colemak (DHm) layer:
#define __COLEMAK_ROW1_LEFT__   KC_TAB,  KC_Q,  KC_W,    KC_F,   KC_P,    KC_B
#define __COLEMAK_ROW1_RIGHT__  KC_J,    KC_L,  KC_U,    KC_Y,   KC_SCLN, KC_BSPC
#define __COLEMAK_ROW2_LEFT__   KC_ESC,  KC_A,  KC_R,    KC_S,   KC_T,    KC_G
#define __COLEMAK_ROW2_RIGHT__  KC_M,    KC_N,  KC_E,    KC_I,   KC_O,    KC_QUOT
#define __COLEMAK_ROW3_LEFT__   KC_LSFT, KC_Z,  KC_X,    KC_C,   KC_D,    KC_V
#define __COLEMAK_ROW3_RIGHT__  KC_K,    KC_H,  KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT


// ------------
// Lower layer:
#define __LOWER_ROW1_LEFT__  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  XXXXXXX
#define __LOWER_ROW1_RIGHT__ XXXXXXX, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, _______

#define __LOWER_ROW2_LEFT__  _______, KC_GRV , KC_TILD, KC_PLUS, KC_EQL,  KC_PERC
#define __LOWER_ROW2_RIGHT__ KC_CIRC, KC_UNDS, KC_MINS, KC_LPRN, KC_RPRN, KC_DQT

#define __LOWER_ROW3_LEFT__  _______, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX
#define __LOWER_ROW3_RIGHT__ XXXXXXX, KC_PIPE, KC_LT,   KC_GT,   XXXXXXX, _______


// ------------
// Raise layer:
#define __RAISE_ROW1_LEFT__  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __RAISE_ROW1_RIGHT__ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______

#define __RAISE_ROW2_LEFT__  _______, KC_DOT,  KC_MINS, KC_PLUS, KC_EQL,  XXXXXXX
#define __RAISE_ROW2_RIGHT__ XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, _______

#define __RAISE_ROW3_LEFT__  _______, KC_COMM, KC_ASTR, KC_SLSH, XXXXXXX, XXXXXXX
#define __RAISE_ROW3_RIGHT__ XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX,  _______


// -------------
// Adjust layer:
#define __ADJUST_ROW1_LEFT__  RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define __ADJUST_ROW1_RIGHT__ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11

#define __ADJUST_ROW2_LEFT__ KC_MPRV, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT
#define __ADJUST_ROW3_LEFT__ _______, BR_BACK, WKSP_LFT,WKSP_RGT,BR_FWD,  XXXXXXX

#define __ADJUST_ROW2_RIGHT__ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______
#define __ADJUST_ROW3_RIGHT__ KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, KC_CAPS
