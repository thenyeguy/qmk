#include QMK_KEYBOARD_H

#include "issmirnov.h"
#include "quantum_keycodes.h"

#ifdef AUDIO_ENABLE
  #include "audio.h"
  #include "sounds.h"
#endif


#ifdef RGBLIGHT_ENABLE
  #include "rgb.h"
#endif

extern keymap_config_t keymap_config;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Run `./qmk show levinson` from parent dir to see this layer.
[_QWERTY] = LAYOUT_ortho_4x12(
KC_ESC  , KC_Q   , KC_W    , KC_E    , KC_R      , KC_T   , KC_Y     , KC_U   , KC_I   , KC_O    , KC_P          , APPS      ,
KC_TAB  , KC_A   , KC_S    , KC_D    , KC_F      , KC_G   , KC_H     , KC_J   , KC_K   , KC_L    , TAP_TOG_LAYER , MO(_NAVI) ,
OSMSFT  , KC_Z   , KC_X    , KC_C    , KC_V      , KC_B   , KC_N     , KC_M   , KC_DOT , KC_COMM , TG(_NUMP)     , KC_QUOTE  ,
KC_LCTL , MODSFT , KC_LALT , KC_LGUI , KC_BSPACE , KC_SPC , KC_ENTER , KC_TAB , KC_UP  , KC_DOWN , KC_LEFT       , KC_RGHT
), // Note: visualizer expects this closing parens to be right at the start of the line.

// Run `./qmk show levinson` from parent dir to see this layer.
[_SYMB] = LAYOUT_ortho_4x12(
_______ , KC_MINS , KC_AT   , KC_LCBR     , KC_RCBR     , KC_GRV  , KC_ASTR , KC_EXLM , KC_PIPE  , KC_PERC   , KC_PLUS       , KC_ESC   ,
_______ , KC_CIRC , KC_UNDS , KC_LPRN     , KC_RPRN     , KC_DLR  , KC_HASH , KC_EQL  , KC_COLN  , KC_SCLN   , TAP_TOG_LAYER , KC_DQT   ,
_______ , KC_LABK , KC_RABK , KC_LBRACKET , KC_RBRACKET , KC_TILD , KC_AMPR , KC_QUES , KC_SLASH , KC_BSLASH , TG(_NUMP)     , KC_QUOTE ,
_______ , _______ , _______ , _______     , _______     , _______ , _______ , _______ , KC_ESC   , KC_COLN   , KC_PERC       , LOCK
), // Note: visualizer expects this closing parens to be right at the start of the line.

// Run `./qmk show levinson` from parent dir to see this layer.
[_NUMP] = LAYOUT_ortho_4x12(
    _______ , KC_NO   , KC_NO         , LGUI(KC_UP)   , KC_MEDIA_PREV_TRACK , KC_MEDIA_NEXT_TRACK , KC_COMM , KC_7    , KC_8    , KC_9    , XXXXXXX        , RESET ,
    _______ , XXXXXXX , LGUI(KC_LEFT) , LGUI(KC_DOWN) , LGUI(KC_RIGHT)      , KC_MEDIA_PLAY_PAUSE , KC_0    , KC_4    , KC_5    , KC_6    , TO(_SYMB)      , _______ ,
    _______ , XXXXXXX , XXXXXXX       , XXXXXXX       , KC_AUDIO_VOL_DOWN   , KC_AUDIO_VOL_UP     , KC_DOT  , KC_1    , KC_2    , KC_3    , TO(_QWERTY)    , _______ ,
    _______ , _______ , _______       , _______       , _______             , _______             , _______ , _______ , _______ , _______ , TO(_OVERWATCH) , _______
), // Note: visualizer expects this closing parens to be right at the start of the line.

// Run `./qmk show levinson` from parent dir to see this layer.
[_OVERWATCH] = LAYOUT_ortho_4x12(
KC_TAB    , KC_Q  , KC_W       , KC_E , KC_R , KC_T     , TO(0)            , XXXXXXX          , XXXXXXX          , XXXXXXX        , XXXXXXX          , CLEAR_EEPROM      ,
KC_LCTL   , KC_A  , KC_S       , KC_D , KC_F , KC_P     , RGB_MODE_FORWARD , RGB_MODE_REVERSE , RGB_VAI          , RGB_VAD        , XXXXXXX          , RGB_TOG           ,
KC_LSHIFT , KC_Z  , KC_X       , KC_C , KC_V , KC_GRAVE , RGB_MODE_PLAIN   , RGB_MODE_BREATHE , RGB_MODE_RAINBOW , RGB_MODE_SWIRL , RGB_MODE_SNAKE   , RGB_MODE_XMAS     ,
KC_LCTL   , KC_F9 , KC_PSCREEN , KC_H , KC_R , KC_SPACE , RGB_HUI          , RGB_HUD          , RGB_SAI          , RGB_SAD        , RGB_MODE_RGBTEST , RGB_MODE_GRADIENT
), // Note: visualizer expects this closing parens to be right at the start of the line.

// Run `./qmk show levinson` from parent dir to see this layer.
[_NAVI] = LAYOUT_ortho_4x12(
XXXXXXX , XXXXXXX , XXXXXXX , KC_UP   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
XXXXXXX , XXXXXXX , KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXX , XXXXXXX , KC_LCTL , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , APPS    , KC_LGUI , MODSFT  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
), // Note: visualizer expects this closing parens to be right at the start of the line.

};

/* void persistent_default_layer_set(uint16_t default_layer) { */
/*   eeconfig_update_default_layer(default_layer); */
/*   default_layer_set(default_layer); */
/* } */

// TAP_TOG_LAYER magic
bool tap_tog_layer_other_key_pressed = false; // set to true if any key pressed while TAP_TOG_LAYER held down
bool tap_tog_layer_toggled_on = false; // will become true if no keys are pressed while TTL held down
uint32_t tap_tog_count = 0; // number of presses on TAP_TOG_LAYER button.

// called by QMK during key processing before the actual key event is handled. Useful for macros.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

    case LOCK:
      if (record->event.pressed) {
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
      }
      return true; // Let QMK send the enter press/release events
      break;
    case RESET:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(song_goodbye);
        #endif
      }
      return true; // Let QMK send the enter press/release events
      break;

    case CLEAR_EEPROM:
      eeconfig_init();
      #ifdef AUDIO_ENABLE
        PLAY_SONG(song_goodbye); // TODO write custom song if firmware has space
      #endif

      return false; // QMK doesn't know about this keycode
      break;
    case TAP_TOG_LAYER:
      tap_tog_count++;
      // press
      if (record->event.pressed) {

        // TTL has already been pressed and we are toggled into that layer
        // so now we need to leave
        if(tap_tog_layer_toggled_on) {
          layer_clear();
          tap_tog_layer_toggled_on = false;
        }

        // this means we're in our default layer
        // so switch the layer immediately
        // whether we'll switch back when it's released depends on if a button gets pressed while this is held down
        else {
          // switch layer
          layer_on(_SYMB);
          tap_tog_layer_other_key_pressed = false; // if this becomes true before it gets released, it will act as a held modifier
        }
      }

      // release
      else {
        // if it was used as a held modifier (like traditional shift)
        if(tap_tog_layer_other_key_pressed) {
          // switch layer back
          layer_clear();
        }
        // if it was used as a toggle button
        else {
          // next time, it will turn layer off
          tap_tog_layer_toggled_on = true;

          // If it's been tapped twice, reset the toggle flag.
          // Otherwise, we get stuck oscillating between this code block and the
          // pressed && TTL_toggled_on block.
          if (tap_tog_count >= 4 ) {
            tap_tog_count = 0;
            tap_tog_layer_toggled_on = false;
          }
        }

      }
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
  uint8_t layer = biton32(layer_state);
  if (layer == 0) {
  }
}
/* // Runs constantly in the background, in a loop every 100ms or so. */
/* // Best used for LED status output triggered when user isn't actively typing. */
/* void matrix_scan_user(void) { */
/*   uint8_t layer = biton32(layer_state); */
/*   if (layer == 0) { */

/*       // Set up LED indicators for stuck modifier keys. */
/*       // https://github.com/qmk/qmk_firmware/blob/master/tmk_core/common/report.h#L118 */
/*       switch (keyboard_report->mods) { */
/*         case MOD_BIT(KC_LSHIFT): // LSHIFT */
/*           rgblight_setrgb_gold_at(shift_led); */
/*           rgblight_setrgb_at(RGB_CLEAR, gui_led); */
/*           break; */

/*         case MOD_BIT(KC_LGUI): // LGUI */
/*           rgblight_setrgb_at(RGB_CLEAR, shift_led); */
/*           rgblight_setrgb_teal_at(gui_led); */
/*           break; */

/*         case MOD_BIT(KC_LSHIFT) ^ MOD_BIT(KC_LGUI): */
/*           rgblight_setrgb_gold_at(shift_led); */
/*           rgblight_setrgb_teal_at(gui_led); */
/*           break; */

/*         default: // reset leds */
/*           rgblight_setrgb_at(RGB_CLEAR, shift_led); */
/*           rgblight_setrgb_at(RGB_CLEAR, gui_led); */
/*           break; */
/*       } */
/*   } */
/* } */


// only runs when when the layer is changed, good for updating LED's and clearing sticky state
// RGB modes: https://github.com/qmk/qmk_firmware/blob/master/quantum/rgblight.h
uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
  layer_state_set_rgb(state);
#endif
  uint8_t layer = biton32(state);
    switch (layer) {
      case 0:
        break;
      case 1:
        clear_mods();
        break;
      case 2:
        clear_mods();
        break;
      case 3:
        clear_mods();
        #ifdef AUDIO_ENABLE
          // PLAY_SONG(song_overwatch);
        #endif
        break;
      default:
        break;
    }
    return state;
};

void keyboard_post_init_user(void) {
  startup_user();
}
void startup_user() {
  #ifdef AUDIO_ENABLE
    _delay_ms(20); // gets rid of tick
    PLAY_SONG(song_startup);
  #endif
  #ifdef RGBLIGHT_ENABLE
    // Clear lights from bootloader colors
    /* rgblight_enable(); // NOTE: WE NEED this line here, otherwise the commands are ignored. */
    keyboard_post_init_rgb();

    /* rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); */
    /* rgblight_setrgb(RGB_CLEAR); */
  #endif

}

void shutdown_user() {
  #ifdef AUDIO_ENABLE
  PLAY_SONG(song_goodbye);
    _delay_ms(150);
    stop_all_notes();
  #endif
}

void suspend_power_down_user(void) {
    /* rgb_matrix_set_suspend_state(true); */
}

void suspend_wakeup_init_user(void) {
    /* rgb_matrix_set_suspend_state(false); */
}
