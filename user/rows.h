#pragma once

// This macro is needed to ensure row macros get expanded properly.
#define EXPAND(layout, ...) layout(__VA_ARGS__)


// -------------
// Generic rows:
#define __BLANK_HALF__ _______, _______, _______, _______, _______, _______
#define __XXXXX_HALF__ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX


// --------------------
// Colemak (DHm) layer:
#define __COLEMAK_ROW1_LEFT__  KC_TAB,  KC_Q,  KC_W,    KC_F,   KC_P,    KC_B
#define __COLEMAK_ROW1_RIGHT__ KC_J,    KC_L,  KC_U,    KC_Y,   KC_QUOT, KC_BSPC

#define __COLEMAK_ROW2_LEFT__  KC_ESC, LGUI_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_G
#define __COLEMAK_ROW2_RIGHT__ KC_M,   RSFT_T(KC_N), RALT_T(KC_E), RCTL_T(KC_I), RGUI_T(KC_O), KC_ENT

#define __COLEMAK_ROW3_LEFT__  KC_LSFT, KC_Z,  KC_X,    KC_C,   KC_D,    KC_V
#define __COLEMAK_ROW3_RIGHT__ KC_K,    KC_H,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT


// ------------
// Lower layer:
#define __LOWER_ROW1_LEFT__  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define __LOWER_ROW1_RIGHT__ KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_DQT,  _______

#define __LOWER_ROW2_LEFT__  _______, KC_GRV , KC_TILD, KC_PLUS, KC_EQL,  KC_LCBR
#define __LOWER_ROW2_RIGHT__ KC_RCBR, KC_UNDS, KC_MINS, KC_COLN, KC_SCLN, _______

#define __LOWER_ROW3_LEFT__  _______, XXXXXXX, KC_LT,   KC_LBRC, KC_LPRN, XXXXXXX
#define __LOWER_ROW3_RIGHT__ XXXXXXX, KC_RPRN, KC_RBRC, KC_GT,   KC_BSLS, _______


// ------------
// Raise layer:
#define __RAISE_ROW1_LEFT__  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __RAISE_ROW1_RIGHT__ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______

#define __RAISE_ROW2_LEFT__  _______, KC_DOT,  KC_MINS, KC_PLUS, KC_EQL,  XXXXXXX
#define __RAISE_ROW2_RIGHT__ XXXXXXX, KC_1,    KC_2,    KC_3,    KC_0,    _______

#define __RAISE_ROW3_LEFT__  _______, KC_COMM, KC_SLSH, KC_ASTR, XXXXXXX, XXXXXXX
#define __RAISE_ROW3_RIGHT__ XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, _______


// -------------
// Adjust layer:
#define __ADJUST_ROW1_LEFT__  RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define __ADJUST_ROW1_RIGHT__ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL

#define __ADJUST_ROW2_LEFT__  _______, KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, KC_VOLU
#define __ADJUST_ROW3_LEFT__  _______, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY, KC_VOLD

#define __ADJUST_ROW2_RIGHT__ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______
#define __ADJUST_ROW3_RIGHT__ KC_END,  KC_PGDN, KC_PGUP, KC_HOME, XXXXXXX, KC_CAPS
