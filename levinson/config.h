#pragma once

#undef TAPPING_TERM
#define TAPPING_TERM 100

#define PERMISSIVE_HOLD
#define RETRO_TAPPING

// how many taps before triggering the toggle
#undef ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2

// #include "config_common.h"

#define USE_SERIAL
// #define USE_I2C

#ifdef RGBLIGHT_ENABLE
   // Enable animations. +5500 bytes
#   define RGBLIGHT_ANIMATIONS
#   undef RGBLED_NUM
#   define RGBLED_NUM 16     // Number of LEDs
/* #   undef RGBLIGHT_LED_MAP */
/* #   define RGBLIGHT_LED_MAP { 0, 1, 2, 3, 4, 5, 6, 7, 15, 8, 13, 12, 11, 10, 9, 14 } */
/* #   undef RGBLED_SPLIT */
/* #   define RGBLED_SPLIT { 8, 8 } */
//#   define RGBLIGHT_SLEEP // Turn off RGB when computer sleeps
#  define RGB_CLEAR 0x00, 0x00, 0x00
#endif

#ifdef AUDIO_ENABLE
#   define QMK_SPEAKER C6
#   define C6_AUDIO
#endif

// Save 200 bytes on unused keycodes
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
