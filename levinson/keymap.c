#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

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
    KC_ESC  , KC_Q   , KC_W    , KC_E    , KC_R  , KC_T    , KC_Y      , KC_U  , KC_I   , KC_O    , KC_P    , APPS    ,
    KC_TAB  , KC_A   , KC_S    , KC_D    , KC_F  , KC_G    , KC_H      , KC_J  , KC_K   , KC_L    , KC_SCLN , KC_ENTER ,
    OSMSFT  , KC_Z   , KC_X    , KC_C    , KC_V  , KC_B    , KC_N      , KC_M  , KC_DOT , KC_COMM , KC_SLSH , KC_DQT  ,
    KC_LCTL , MODSFT , KC_LALT , KC_LGUI , LOWER , KC_SPC  , KC_BSPACE , RAISE , KC_ESC , KC_COLN , KC_PERC , LOCK

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
[_LOWER] = LAYOUT_ortho_4x12(
        _______ , KC_MINS , KC_AT   , KC_LCBR     , KC_RCBR     , KC_GRV   , KC_ASTR , KC_EXLM , KC_PIPE  , KC_PERC   , KC_PLUS  , RESET   ,
    _______ , KC_CIRC , KC_UNDS , KC_LPRN     , KC_RPRN     , KC_DLR   , KC_HASH , KC_EQL  , KC_COLN  , KC_SCLN   , KC_TILD  , KC_DQT  ,
    _______ , KC_LABK , KC_RABK , KC_LBRACKET , KC_RBRACKET , KC_SLASH , KC_AMPR , KC_QUES , KC_SLASH , KC_BSLASH , KC_QUOTE , _______ ,
    _______ , _______ , _______ , _______     , _______     , _______  , _______ , _______ , KC_UP    , KC_DOWN   , KC_LEFT  , KC_RGHT

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
[_RAISE] = LAYOUT_ortho_4x12(
    _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_0    , KC_4    , KC_5    , KC_6    , KC_COMM , _______ ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_DOT  , KC_1    , KC_2    , KC_3    , XXXXXXX , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
), // Note: visualizer expects this closing parens to be right at the start of the line.

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

/* void persistent_default_layer_set(uint16_t default_layer) { */
/*   eeconfig_update_default_layer(default_layer); */
/*   default_layer_set(default_layer); */
/* } */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*     case QWERTY: */
/*       if (record->event.pressed) { */
/*         #ifdef AUDIO_ENABLE */
/*           PLAY_SONG(tone_qwerty); */
/*         #endif */
/*         persistent_default_layer_set(1UL<<_QWERTY); */
/*       } */
/*       return false; */
/*       break; */
/*     case COLEMAK: */
/*       if (record->event.pressed) { */
/*         #ifdef AUDIO_ENABLE */
/*           PLAY_SONG(tone_colemak); */
/*         #endif */
/*         persistent_default_layer_set(1UL<<_COLEMAK); */
/*       } */
/*       return false; */
/*       break; */
/*     case DVORAK: */
/*       if (record->event.pressed) { */
/*         #ifdef AUDIO_ENABLE */
/*           PLAY_SONG(tone_dvorak); */
/*         #endif */
/*         persistent_default_layer_set(1UL<<_DVORAK); */
/*       } */
/*       return false; */
/*       break; */
/*     case LOWER: */
/*       if (record->event.pressed) { */
/*         layer_on(_LOWER); */
/*         update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*       } else { */
/*         layer_off(_LOWER); */
/*         update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*       } */
/*       return false; */
/*       break; */
/*     case RAISE: */
/*       if (record->event.pressed) { */
/*         layer_on(_RAISE); */
/*         update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*       } else { */
/*         layer_off(_RAISE); */
/*         update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*       } */
/*       return false; */
/*       break; */
/*     case ADJUST: */
/*       if (record->event.pressed) { */
/*         layer_on(_ADJUST); */
/*       } else { */
/*         layer_off(_ADJUST); */
/*       } */
/*       return false; */
/*       break; */
/*   } */
/*   return true; */
/* } */
