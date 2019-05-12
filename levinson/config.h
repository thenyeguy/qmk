#pragma once

#undef TAPPING_TERM
#define TAPPING_TERM 150

#define PERMISSIVE_HOLD
#define RETRO_TAPPING

// how many taps before triggering the toggle
#undef ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2

// Enable animations. +5500 bytes
#define RGBLIGHT_ANIMATIONS

#ifdef RGBLIGHT_ENABLE
#   undef RGBLED_NUM
#   define RGBLED_NUM 16     // Number of LEDs
/* #   undef RGBLED_SPLIT */
/* #   define RGBLED_SPLIT { 6, 6 } */
#endif

#define QMK_SPEAKER C6
#define C6_AUDIO

// Save 200 bytes on unused keycodes
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
