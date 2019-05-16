#pragma once

#include QMK_KEYBOARD_H

#include "quantum_keycodes.h"

// This wrapper is required in order to expand the row macro inside the keymap configs.
#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)

// Share common config. We'll skip the mod rows and func rows.
// Note, it's also really neat the way the scoping works. Since we perform the expansion in the keymap.c file
// so we can use our enums for custom keycodes
#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    TAP_TOG_LAYER
#define _________________QWERTY_R3_________________        KC_N    , KC_M    , KC_DOT  , KC_COMMA      , TG(2)

#define ___________________BLANK___________________        _______, _______, _______, _______, _______

#define _________________SYMB_R1___________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________SYMB_R2___________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________SYMB_R3___________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC

#define _________________SYMB_L1___________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________SYMB_L2___________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________SYMB_L3___________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
