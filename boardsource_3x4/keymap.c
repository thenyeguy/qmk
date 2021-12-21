#include QMK_KEYBOARD_H

enum layers {
    _MAIN,
    _RAISE,
    _LOWER,
};

// Readability keycodes
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// TODO: figure out toggle of LGUI/LCTL for cross platform usage
/*
Zoom: Audio, video, screenshare, fullscreen
Meet: Audio, video, chat, minimize video
Raise(arrows), , , quit zoom meeting
 */


[_MAIN] = LAYOUT(
  LGUI(LSFT(KC_A)) , LGUI(LSFT(KC_V)) , LGUI(LSFT(KC_S)) , LGUI(LSFT(KC_F)) ,
  LGUI(KC_D)       , LGUI(KC_E)       , LGUI(LSFT(KC_C)) , LGUI(LSFT(KC_M)) ,
  RAISE            , _______          , _______          , LGUI(KC_W)
),
[_RAISE] = LAYOUT(
    RESET   , KC_DELETE , KC_UP   , KC_ENTER ,
    _______ , KC_LEFT   , KC_DOWN , KC_RIGHT ,
    _______ , _______   , _______ , _______
  )
};
