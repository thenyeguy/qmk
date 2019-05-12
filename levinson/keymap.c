#include QMK_KEYBOARD_H

#include "quantum_keycodes.h"
//#include "rgblight_list.h"
//#include "rgblight.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
  #include "sounds.h"
#endif

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers
enum {
  _QWERTY = 0,
  _SYMB,
  _NUMP,
  _OVERWATCH,
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,
  TAP_TOG_LAYER,
};


#define LOWER MO(_SYMB)
#define RAISE MO(_NUMP)

#define CTL_SPC MT(MOD_LCTL, KC_SPC)
#define OSMSFT OSM(MOD_LSFT)
#define LOCK LGUI(KC_L)
#define MODSFT LSFT(KC_LGUI)
#define APPS LGUI(KC_D)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
KC_ESC  , KC_Q   , KC_W    , KC_E    , KC_R   , KC_T      , KC_Y   , KC_U     , KC_I   , KC_O    , KC_P          , APPS     ,
KC_TAB  , KC_A   , KC_S    , KC_D    , KC_F   , KC_G      , KC_H   , KC_J     , KC_K   , KC_L    , TAP_TOG_LAYER , KC_DQT   ,
OSMSFT  , KC_Z   , KC_X    , KC_C    , KC_V   , KC_B      , KC_N   , KC_M     , KC_DOT , KC_COMM , TG(_NUMP)     , KC_QUOTE ,
KC_LCTL , MODSFT , KC_LALT , KC_LGUI , KC_BSPACE , KC_SPC , KC_ENTER , KC_TAB , KC_UP    , KC_DOWN   , KC_LEFT   , KC_RGHT

), // Note: visualizer expects this closing parens to be right at the start of the line.

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMB] = LAYOUT_ortho_4x12(
_______ , KC_MINS , KC_AT   , KC_LCBR     , KC_RCBR     , KC_GRV   , KC_ASTR , KC_EXLM , KC_PIPE  , KC_PERC   , KC_PLUS   , RESET    ,
_______ , KC_CIRC , KC_UNDS , KC_LPRN     , KC_RPRN     , KC_DLR   , KC_HASH , KC_EQL  , KC_COLN  , KC_SCLN   , TAP_TOG_LAYER  , KC_DQT   ,
_______ , KC_LABK , KC_RABK , KC_LBRACKET , KC_RBRACKET , KC_TILD , KC_AMPR , KC_QUES , KC_SLASH , KC_BSLASH , TG(_NUMP) , KC_QUOTE ,
_______ , _______ , _______ , _______     , _______     , _______  , _______ , _______ ,KC_ESC , KC_COLN , KC_PERC       , LOCK

), // Note: visualizer expects this closing parens to be right at the start of the line.

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMP] = LAYOUT_ortho_4x12(
    _______ , KC_NO   , KC_NO         , LGUI(KC_UP)   , KC_MEDIA_PREV_TRACK , KC_MEDIA_NEXT_TRACK , KC_COMM , KC_7    , KC_8    , KC_9    , XXXXXXX        , _______ ,
    _______ , XXXXXXX , LGUI(KC_LEFT) , LGUI(KC_DOWN) , LGUI(KC_RIGHT)      , KC_MEDIA_PLAY_PAUSE , KC_0    , KC_4    , KC_5    , KC_6    , TO(_SYMB)      , _______ ,
    _______ , XXXXXXX , XXXXXXX       , XXXXXXX       , KC_AUDIO_VOL_DOWN   , KC_AUDIO_VOL_UP     , KC_DOT  , KC_1    , KC_2    , KC_3    , TO(_QWERTY)    , _______ ,
    _______ , _______ , _______       , _______       , _______             , _______             , _______ , _______ , _______ , _______ , TO(_OVERWATCH) , _______
), // Note: visualizer expects this closing parens to be right at the start of the line.

[_OVERWATCH] = LAYOUT_ortho_4x12(
KC_TAB    , KC_Q  , KC_W       , KC_E , KC_R , KC_T     , TO(0)            , XXXXXXX          , XXXXXXX          , XXXXXXX        , XXXXXXX          , RGB_TOG           ,
KC_LCTL   , KC_A  , KC_S       , KC_D , KC_F , KC_P     , RGB_MODE_FORWARD , RGB_MODE_REVERSE , RGB_VAI          , RGB_VAD        , XXXXXXX                 , XXXXXXX           ,
KC_LSHIFT , KC_Z  , KC_X       , KC_C , KC_V , KC_GRAVE , RGB_MODE_PLAIN   , RGB_MODE_BREATHE , RGB_MODE_RAINBOW , RGB_MODE_SWIRL , RGB_MODE_SNAKE   , RGB_MODE_XMAS     ,
KC_LCTL   , KC_F9 , KC_PSCREEN , KC_H , KC_R , KC_SPACE , RGB_HUI          , RGB_HUD          , RGB_SAI          , RGB_SAD        , RGB_MODE_RGBTEST , RGB_MODE_GRADIENT
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
      return false;
      break;
    case RESET:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(song_goodbye);
        #endif
      }
      return false;
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
  uint8_t layer = biton32(layer_state);
  if (layer == 0) {

      // Set up LED indicators for stuck modifier keys.
      // https://github.com/qmk/qmk_firmware/blob/master/tmk_core/common/report.h#L118
      switch (keyboard_report->mods) {
          case MOD_BIT(KC_LSFT): // LSHIFT
              // TODO set single LED on inner half (or top right) to yellow or smth
              // rgblight_setrgb_at(50, 50, 50, 0);
              // rgblight_setrgb_master(90, 100, 3);
              /* rgblight_setrgb_at(0xFF, 0xD9, 0x00, 7); */
              rgblight_setrgb_gold_at(7);
              /* rgblight_setrgb_turquoise_at(7); */
              /* rgblight_setrgb_pink_at(8); */
              /* rgblight_setrgb_green_at(9); */

              break;

          case MOD_BIT(KC_LGUI): // LGUI
              //rgblight_setrgb_slave(50, 60, 70)
              rgblight_setrgb_turquoise_at(8);
              break;

          case MOD_BIT(KC_LSFT) ^ MOD_BIT(KC_LGUI):
              break;

          default: // reset leds
            rgblight_setrgb_white_at(7);
            break;
      }
  }
}


// only runs when when the layer is changed, good for updating LED's and clearing sticky state
// RGB modes: https://github.com/qmk/qmk_firmware/blob/master/quantum/rgblight.h
uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    switch (layer) {
      case 0:
        // rgblight_mode(RGBLIGHT_MODE_KNIGHT);
        //rgblight_mode(RGBLIGHT_MODE_RGB_TEST);
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb(0,0,0);
        break;
      case 1:
        clear_mods();
        rgblight_setrgb(RGB_RED);
        break;
      case 2:
        clear_mods();
        rgblight_setrgb(RGB_GREEN);
        break;
      case 3:
        clear_mods();
        rgblight_setrgb(0,0,255);
        #ifdef AUDIO_ENABLE
          PLAY_SONG(song_overwatch);
        #endif
        break;
      case 4:
        break;
      default:
        break;
    }
    return state;
};

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}
void startup_user() {
  #ifdef AUDIO_ENABLE
  _delay_ms(20); // gets rid of tick
  PLAY_SONG(song_startup);
  #endif
}

void shutdown_user() {
  #ifdef AUDIO_ENABLE
  PLAY_SONG(song_goodbye);
    _delay_ms(150);
    stop_all_notes();
  #endif
}
