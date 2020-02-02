#pragma once

#ifdef AUDIO_ENABLE
    #undef OVERWATCH_THEME
    #define OVERWATCH_THEME                        \
        WD_NOTE(_A6),  Q__NOTE(_E6), Q__NOTE(_A6), \
        WD_NOTE(_B6),  Q__NOTE(_E6), Q__NOTE(_B6), \
        B__NOTE(_CS7),

    #define STARTUP_SONG SONG(PLANCK_SOUND)

    #define DEFAULT_LAYER_SONGS { \
        SONG(QWERTY_SOUND),       \
        SONG(OVERWATCH_THEME)     \
    }
#endif
