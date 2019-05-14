
# ifeq ($(strip $(TAP_TOG_ENABLE)), yes)
	SRC += tap_tog.c
# endif

# https://www.reddit.com/r/olkb/comments/bmpgjm/programming_help/
# Should shave 2000 bytes
LINK_TIME_OPTIMIZATION_ENABLE = yes

# Enable debugging only when needed.
CONSOLE_ENABLE = yes # +400 bytes (hid_listen support)

# Disable unused features to save on space
# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
MOUSEKEY_ENABLE = no # 2000 bytes
BOOTMAGIC_ENABLE = no
COMMAND_ENABLE = no # https://beta.docs.qmk.fm/features/feature_command
