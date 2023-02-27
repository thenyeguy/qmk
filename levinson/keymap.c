#include "tap_tog.h"

#ifdef AUDIO_ENABLE
  #include "audio.h"
  #include "sounds.h"
#endif


#ifdef RGBLIGHT_ENABLE
  #include "rgb.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Run `./qmk show levinson` from parent dir to see this layer.
[_QWERTY] = LAYOUT_ortho_4x12_wrapper(
KC_ESC  , _________________QWERTY_L1_________________, _________________QWERTY_R1_________________ , APPS      ,
KC_TAB  , _________________QWERTY_L2_________________, _________________QWERTY_R2_________________ , MO(_NAVI) ,
OSMSFT  , _________________QWERTY_L3_________________, _________________QWERTY_R3_________________ , KC_QUOTE  ,
KC_LCTL , MODSFT , KC_LALT , KC_LGUI , KC_BACKSPACE , KC_SPC , KC_ENTER , KC_TAB , LCTL(KC_S) , LCTL(LSFT(KC_R)) , KC_PSCR , LGUI(KC_L)
), // Note: visualizer expects this closing parens to be right at the start of the line.

// Run `./qmk show levinson` from parent dir to see this layer.
[_SYMB] = LAYOUT_ortho_4x12_wrapper(
_______ , _________________SYMB_L1___________________, _________________SYMB_R1___________________ , LCTL(LSFT(LGUI(KC_D))),
_______ , _________________SYMB_L2___________________, _________________SYMB_R2___________________ , MO(_NAVI) ,
_______ , _________________SYMB_L3___________________, _________________SYMB_R3___________________ , KC_QUOTE  ,
_______ , _______, _______, KC_F1, KC_F2, KC_DEL,      _______ , _______ , KC_ESC   , KC_COLN   , KC_PERC      , LOCK
), // Note: visualizer expects this closing parens to be right at the start of the line.

// Run `./qmk show levinson` from parent dir to see this layer.
[_NUMP] = LAYOUT_ortho_4x12_wrapper(
_______ , _________________NUMP_L1___________________ , _________________NUMP_R1___________________ , QK_REBOOT     ,
_______ , _________________NUMP_L2___________________ , _________________NUMP_R2___________________ , MO(_NAVI) ,
_______ , _________________NUMP_L3___________________ , _________________NUMP_R3___________________ , _______   ,
_______ , ___________________BLANK___________________ , _______ , _______ , _______ , _______ , TO(_OVERWATCH)  , _______
), // Note: visualizer expects this closing parens to be right at the start of the line.

// Run `./qmk show levinson` from parent dir to see this layer.
[_OVERWATCH] = LAYOUT_ortho_4x12_wrapper(
______________OVERWATCH_L1_________________ , TO(0)           , XXXXXXX          , XXXXXXX          , XXXXXXX        , XXXXXXX        , EEP_RST ,
______________OVERWATCH_L2_________________ , RGB_MODE_FORWARD, RGB_MODE_REVERSE , XXXXXXX          , XXXXXXX        , XXXXXXX        , RGB_TOG ,
______________OVERWATCH_L3_________________ , RGB_MODE_PLAIN  , RGB_MODE_BREATHE , RGB_MODE_RAINBOW , RGB_MODE_SWIRL , RGB_MODE_SNAKE , XXXXXXX ,
______________OVERWATCH_L4_________________ , KC_SPACE         , XXXXXXX          , XXXXXXX          , XXXXXXX        , XXXXXXX        , XXXXXXX, RGB_MODE_GRADIENT
), // Note: visualizer expects this closing parens to be right at the start of the line.

// Run `./qmk show levinson` from parent dir to see this layer.
[_NAVI] = LAYOUT_ortho_4x12_wrapper(
XXXXXXX , _________________NAVI_L1___________________ , _________________NAVI_R1___________________ , XXXXXXX ,
XXXXXXX , _________________NAVI_L2___________________ , _________________NAVI_R2___________________ , XXXXXXX ,
XXXXXXX , _________________NAVI_L3___________________ , _________________NAVI_R3___________________ , XXXXXXX ,
XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , APPS    , KC_LGUI , MODSFT  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
), // Note: visualizer expects this closing parens to be right at the start of the line.

};

// called by QMK during key processing before the actual key event is handled. Useful for macros.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOCK:
      if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
#endif
      }
      return true; // Let QMK send the press/release events
      break;

    case TAP_TOG_LAYER:
      process_tap_tog(_SYMB,record);
      return false;
      break;
    default:
      tap_tog_count = 0; // reset counter.
      tap_tog_layer_other_key_pressed = true; // always set this to true, TAP_TOG_LAYER handlers will handle interpreting this
      break;
  }
  return true;
}


// Runs constantly in the background, in a loop every 100ms or so.
// Best used for LED status output triggered when user isn't actively typing.
void matrix_scan_user(void) {
  #ifdef RGBLIGHT_ENABLE
    matrix_scan_rgb();
  #endif // RGBLIGHT_ENABLE
}

// only runs when when the layer is changed, good for updating LED's and clearing sticky state
// RGB modes: https://github.com/qmk/qmk_firmware/blob/master/quantum/rgblight.h
uint32_t layer_state_set_user(uint32_t state) {
  #ifdef RGBLIGHT_ENABLE
    layer_state_set_rgb(state);
  #endif
  uint8_t layer = biton32(state);
  combo_enable(); // by default, enable combos.
  switch (layer) {
    case 0:
      break;
    case 1:
      clear_mods();
      break;
    case 2:
      clear_mods();
      break;
    case _OVERWATCH:
      clear_mods();
      combo_disable(); // We don't want combos in overwatch
      #ifdef AUDIO_ENABLE
        // PLAY_SONG(song_overwatch);
      #endif
      break;
    default:
      break;
  }
  return state;
};

// Runs boot tasks for keyboard.
// Plays a welcome song and clears RGB state.
void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    keyboard_post_init_rgb();
  #endif
}
