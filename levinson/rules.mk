# Enable RGB underglow
# https://beta.docs.qmk.fm/features/feature_rgblight
RGBLIGHT_ENABLE = yes # +5500 bytes

# Disable backlight, since I use RGB underglow.
# https://beta.docs.qmk.fm/features/feature_backlight
BACKLIGHT_ENABLE = no

# Control piezo speaker on C6
AUDIO_ENABLE = yes # +4000 bytes

# Disable unused features to save on space
# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
MOUSEKEY_ENABLE = no # 2000 bytes
CONSOLE_ENABLE = yes # +400 bytes (hid_listen support)
BOOTMAGIC_ENABLE = no

# Include custom files
SRC += issmirnov.c

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  # Include my fancy rgb functions source here
  SRC	 += rgb.c
endif
