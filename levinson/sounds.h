// ................................................................ Audio Sounds
#ifdef AUDIO_ENABLE
#pragma message "Enabling audio songs"
float song_startup  [][2] = SONG(STARTUP_SOUND);
float song_qwerty   [][2] = SONG(QWERTY_SOUND);
float song_caps_on  [][2] = SONG(CAPS_LOCK_ON_SOUND);
float song_caps_off [][2] = SONG(CAPS_LOCK_OFF_SOUND);
float music_scale   [][2] = SONG(MUSIC_SCALE_SOUND);
float song_goodbye  [][2] = SONG(GOODBYE_SOUND);
float song_overwatch[][2] = SONG(OVERWATCH_THEME);

#undef OVERWATCH_THEME
#define OVERWATCH_THEME                        \
    WD_NOTE(_A6),  Q__NOTE(_E6), Q__NOTE(_A6), \
    WD_NOTE(_B6),  Q__NOTE(_E6), Q__NOTE(_B6), \
    B__NOTE(_CS7),

#endif
