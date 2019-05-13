// ................................................................ Audio Sounds
#ifdef AUDIO_ENABLE

#undef OVERWATCH_THEME
#define OVERWATCH_THEME                        \
    WD_NOTE(_A6),  Q__NOTE(_E6), Q__NOTE(_A6), \
    WD_NOTE(_B6),  Q__NOTE(_E6), Q__NOTE(_B6), \
    B__NOTE(_CS7),

// Songs come from quantum/audio/song_list.h
float song_startup  [][2] = SONG(STARTUP_SOUND);
float song_goodbye  [][2] = SONG(GOODBYE_SOUND);
float song_overwatch[][2] = SONG(OVERWATCH_THEME);

#endif
