#pragma once

// This macro is needed to ensure row macros get expanded properly.
#define EXPAND(layout, ...) layout(__VA_ARGS__)


// ----------------
// Shared keycodes.
#define KC_LOCK LGUI(LCTL(KC_Q))


// --------------------
// Colemak (DHm) layer:
#define __BASE_ROW1_LEFT__  KC_Q,         KC_W,         KC_F,         KC_P,         KC_B
#define __BASE_ROW2_LEFT__  LGUI_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_G
#define __BASE_ROW3_LEFT__  KC_Z,         KC_X,         KC_C,         KC_D,         KC_V

#define __BASE_ROW1_RIGHT__ KC_J, KC_L,         KC_U,         KC_Y,         KC_QUOT
#define __BASE_ROW2_RIGHT__ KC_M, RSFT_T(KC_N), RALT_T(KC_E), RCTL_T(KC_I), RGUI_T(KC_O)
#define __BASE_ROW3_RIGHT__ KC_K, KC_H,         KC_COMM,      KC_DOT,       KC_SLSH


// ------------
// Lower layer:
#define __LOWER_ROW1_LEFT__  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __LOWER_ROW2_LEFT__  KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX
#define __LOWER_ROW3_LEFT__  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define __LOWER_ROW1_RIGHT__ KC_SLSH, KC_7,    KC_8,    KC_9,    KC_DQT
#define __LOWER_ROW2_RIGHT__ KC_EQL,  KC_1,    KC_2,    KC_3,    KC_0
#define __LOWER_ROW3_RIGHT__ KC_MINS, KC_4,    KC_5,    KC_6,    KC_DOT


// ------------
// Raise layer:
#define __RAISE_ROW1_LEFT__  KC_GRV,  KC_LCBR, KC_RCBR, KC_BSLS, XXXXXXX
#define __RAISE_ROW2_LEFT__  KC_UNDS, KC_MINS, KC_LPRN, KC_RPRN, KC_SCLN
#define __RAISE_ROW3_LEFT__  KC_LBRC, KC_RBRC, KC_LT,   KC_GT,   KC_EQL

#define __RAISE_ROW1_RIGHT__ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __RAISE_ROW2_RIGHT__ XXXXXXX, KC_RSFT, KC_RALT, KC_RCTL, KC_RGUI
#define __RAISE_ROW3_RIGHT__ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX


// -------------
// Adjust layer:
#define __ADJUST_ROW1_LEFT__  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define __ADJUST_ROW2_LEFT__  KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, KC_VOLU
#define __ADJUST_ROW3_LEFT__  KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY, KC_VOLD

#define __ADJUST_ROW1_RIGHT__ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define __ADJUST_ROW2_RIGHT__ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX
#define __ADJUST_ROW3_RIGHT__ KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX
