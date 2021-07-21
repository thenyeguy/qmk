#pragma once

// This macro is needed to ensure row macros get expanded properly.
#define EXPAND(layout, ...) layout(__VA_ARGS__)


// -------------
// Generic rows:
#define __BLANK_HALF__ _______, _______, _______, _______, _______, _______
#define __XXXXX_HALF__ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX


// --------------------
// Colemak (DHm) layer:
#define __COLEMAK_ROW1_LEFT__  KC_TAB,  KC_Q,         KC_W,         KC_F,         KC_P,         KC_B
#define __COLEMAK_ROW2_LEFT__  KC_ESC,  LGUI_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_G
#define __COLEMAK_ROW3_LEFT__  KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_D,         KC_V

#define __COLEMAK_ROW1_RIGHT__ KC_J, KC_L,         KC_U,         KC_Y,         KC_QUOT,      KC_BSPC
#define __COLEMAK_ROW2_RIGHT__ KC_M, RSFT_T(KC_N), RALT_T(KC_E), RCTL_T(KC_I), RGUI_T(KC_O), KC_ENT
#define __COLEMAK_ROW3_RIGHT__ KC_K, KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_RSFT


// ------------
// Lower layer:
#define __LOWER_ROW1_LEFT__  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __LOWER_ROW2_LEFT__  _______, KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX
#define __LOWER_ROW3_LEFT__  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define __LOWER_ROW1_RIGHT__ KC_MINS, KC_7,    KC_8,    KC_9,    KC_DQT,  _______
#define __LOWER_ROW2_RIGHT__ KC_EQL,  KC_1,    KC_2,    KC_3,    KC_0,    _______
#define __LOWER_ROW3_RIGHT__ KC_DOT,  KC_4,    KC_5,    KC_6,    KC_SLSH, _______


// ------------
// Raise layer:
#define __RAISE_ROW1_LEFT__  _______, KC_GRV,  KC_BSLS, KC_LCBR, KC_RCBR, XXXXXXX
#define __RAISE_ROW2_LEFT__  _______, KC_UNDS, KC_MINS, KC_LPRN, KC_RPRN, KC_SCLN
#define __RAISE_ROW3_LEFT__  _______, KC_LBRC, KC_RBRC, KC_LT,   KC_GT,   XXXXXXX

#define __RAISE_ROW1_RIGHT__ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
#define __RAISE_ROW2_RIGHT__ XXXXXXX, KC_RSFT, KC_RALT, KC_RCTL, KC_RGUI, _______
#define __RAISE_ROW3_RIGHT__ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______


// -------------
// Adjust layer:
#define __ADJUST_ROW1_LEFT__  RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define __ADJUST_ROW2_LEFT__  _______, KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, KC_VOLU
#define __ADJUST_ROW3_LEFT__  _______, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY, KC_VOLD

#define __ADJUST_ROW1_RIGHT__ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL
#define __ADJUST_ROW2_RIGHT__ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______
#define __ADJUST_ROW3_RIGHT__ KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, KC_CAPS
