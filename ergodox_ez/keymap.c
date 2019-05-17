#include "ergodox_ez.h"

// Custom user includes
#include "issmirnov.h"
#include "tap_tog.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ergodox_wrapper(
KC_ESCAPE,      KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_EXLM,
KC_SLASH,       _________________QWERTY_L1_________________,   KC_ASTR,
KC_TAB,         _________________QWERTY_L2_________________,
OSM(MOD_LSFT),  _________________QWERTY_L3_________________,   KC_SLASH,
KC_LCTL, LSFT(KC_LGUI), LSFT(KC_LALT),  KC_LALT,   KC_LGUI,
                                        XXXXXXX,  XXXXXXX,
                                                XXXXXXX,
                        KC_SPACE,   KC_BSPACE,  KC_DEL,

KC_EQL    , KC_6    , KC_7    , KC_8    , KC_9          , KC_0    , KC_ESCAPE      ,
KC_PLUS   , _________________QWERTY_R1_________________  , LGUI(KC_SPACE) ,
            _________________QWERTY_R2_________________  , KC_DQT ,
KC_MINS   , _________________QWERTY_R3_________________  , KC_QUOTE       ,
KC_ESCAPE , KC_COLN , KC_PERC , XXXXXXX , LGUI(KC_L)    ,

KC_LEFT,  KC_RGHT,
KC_UP,
KC_DOWN,  KC_TAB, KC_ENTER
),

  // layer 1
[_SYMB] = LAYOUT_ergodox(
KC_ESCAPE , KC_F1         , KC_F2         , KC_F3       , KC_F4            , KC_F5    , KC_F6    ,
XXXXXXX   , KC_MINS      , KC_AT         , KC_LCBR     , KC_RCBR          , KC_GRV , KC_ASTR  ,
KC_TAB    , KC_CIRC       , KC_UNDS       , KC_LPRN     , KC_RPRN          , KC_DLR   ,
KC_LSHIFT , KC_LABK       , KC_RABK       , KC_LBRACKET , KC_RBRACKET      , KC_TILD  , KC_SLASH ,
KC_LCTL   , LSFT(KC_LGUI) , LSFT(KC_LALT) , KC_LALT     , WKSP_LEFT  ,

                                              XXXXXXX,        XXXXXXX,
                                                            XXXXXXX,
                                    WKSP_RIGHT, KC_BSPACE,    KC_DEL,

KC_F7     , KC_F8    , KC_F9   , KC_F10    , KC_F11    , KC_F12  , XXXXXXX  ,
KC_PLUS   , KC_ASTR  , KC_EXLM , KC_PIPE   , KC_PERC   , KC_PLUS , XXXXXXX  ,
            KC_HASH  , KC_EQL , KC_COLN , KC_SCOLON , _______   , KC_DQUO ,
KC_MINS  , KC_AMPR  , KC_QUES , KC_SLASH  , KC_BSLASH , TG(2)   , KC_QUOTE ,
KC_ESCAPE , KC_COLN  , KC_PERC , XXXXXXX   , XXXXXXX   ,

KC_LEFT,  KC_RGHT,
KC_UP,
KC_DOWN,  KC_TAB, KC_ENTER
),

  // layer 2
[_NUMP] = LAYOUT_ergodox(
XXXXXXX , XXXXXXX , XXXXXXX       , XXXXXXX       , XXXXXXX             , XXXXXXX             , XXXXXXX  ,
XXXXXXX , XXXXXXX , XXXXXXX       , LGUI(KC_UP)   , KC_MEDIA_PREV_TRACK , KC_MEDIA_NEXT_TRACK , KC_ASTR  ,
KC_TAB  , XXXXXXX , LGUI(KC_LEFT) , LGUI(KC_DOWN) , LGUI(KC_RIGHT)      , KC_MEDIA_PLAY_PAUSE ,
XXXXXXX , XXXXXXX , XXXXXXX       , XXXXXXX       , KC_AUDIO_VOL_DOWN   , KC_AUDIO_VOL_UP     , KC_SLASH ,
TO(0)   , XXXXXXX , XXXXXXX       , XXXXXXX       , XXXXXXX             ,

                                                                          XXXXXXX  ,  XXXXXXX  ,
                                                                                      XXXXXXX  ,
                                                                          KC_SPACE , KC_BSPACE , KC_DEL ,

KC_EQL , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , RESET   ,
KC_PLUS  , KC_COMM , KC_7    , KC_8    , KC_9    , XXXXXXX ,
XXXXXXX  , KC_0     , KC_4    , KC_5    , KC_6    , TO(1)   , XXXXXXX ,
KC_MINS , KC_DOT   , KC_1    , KC_2    , KC_3    , TO(0)   , XXXXXXX ,
                      KC_0    , XXXXXXX , XXXXXXX , TO(3)   , XXXXXXX ,

KC_LEFT,  KC_RGHT,
KC_UP,
KC_DOWN,  KC_LALT, KC_LSFT
),

  // layer 3
[_OVERWATCH] = LAYOUT_ergodox(
KC_ESCAPE , KC_1  , KC_2       , KC_3 , KC_4 , KC_5     , TO(0)    ,
KC_TAB    , KC_Q  , KC_W       , KC_E , KC_R , KC_T     , XXXXXXX    ,
KC_LCTL   , KC_A  , KC_S       , KC_D , KC_F , KC_P     ,
KC_LSFT , KC_Z  , KC_X       , KC_C , KC_V , KC_GRV , XXXXXXX ,
KC_LCTL   , KC_F9 , KC_PSCREEN , KC_H , KC_R ,

XXXXXXX  , XXXXXXX ,
XXXXXXX  ,
KC_SPACE , XXXXXXX , XXXXXXX ,


_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______,

_______, _______,
_______,
_______, _______, _______

),
};


// called by QMK during key processing before the actual key event is handled. Useful for macros.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TAP_TOG_LAYER:
      process_tap_tog(_SYMB,record);
      return false;
      break;

    case WKSP_LEFT:
      // Only if TAP_TOG_LAYER is being held right now do we want to do actions.
      if (record->event.pressed && !tap_tog_layer_toggled_on) {
        register_code(KC_LGUI);
        register_code(KC_LSHIFT);
        register_code(KC_Z);
        unregister_code(KC_Z);
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LGUI);
      }
      break;
    case WKSP_RIGHT:
      // Only if TAP_TOG_LAYER is being held right now do we want to do actions.
      if (record->event.pressed && !tap_tog_layer_toggled_on) {
        register_code(KC_LGUI);
        register_code(KC_LSHIFT);
        register_code(KC_X);
        unregister_code(KC_X);
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LGUI);
      }
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
              ergodox_right_led_1_set (LED_BRIGHTNESS_LO);
              ergodox_right_led_1_on ();
              ergodox_right_led_2_set (LED_BRIGHTNESS_LO);
              ergodox_right_led_2_on ();
              ergodox_right_led_3_set (LED_BRIGHTNESS_HI);
              ergodox_right_led_3_off ();
              break;

          case MOD_BIT(KC_LGUI): // LGUI
              ergodox_right_led_1_set (LED_BRIGHTNESS_HI);
              ergodox_right_led_1_off ();
              ergodox_right_led_2_set (LED_BRIGHTNESS_LO);
              ergodox_right_led_2_on ();
              ergodox_right_led_3_set (LED_BRIGHTNESS_LO);
              ergodox_right_led_3_on ();
              break;

          case MOD_BIT(KC_LSFT) ^ MOD_BIT(KC_LGUI):
              ergodox_right_led_1_set (70);
              ergodox_right_led_1_on ();
              ergodox_right_led_2_set (70);
              ergodox_right_led_2_on ();
              ergodox_right_led_3_set (70);
              ergodox_right_led_3_on ();
              break;

          default: // reset leds
              ergodox_right_led_1_set (LED_BRIGHTNESS_HI);
              ergodox_right_led_1_off ();
              ergodox_right_led_2_set (LED_BRIGHTNESS_HI);
              ergodox_right_led_2_off ();
              ergodox_right_led_3_set (LED_BRIGHTNESS_HI);
              ergodox_right_led_3_off ();
      }
  }
}

// only runs when when the layer is changed, good for updating LED's and clearing sticky state
uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (layer) {
      case 0:
        break;
      case 1:
      clear_mods();
        ergodox_right_led_1_on();
        break;
      case 2:
      clear_mods();
        ergodox_right_led_2_on();
        break;
      case 3:
      clear_mods();
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;
};
