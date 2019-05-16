
SRC += tap_tog.c
SRC += issmirnov.c

# https://www.reddit.com/r/olkb/comments/bmpgjm/programming_help/
# Should shave 2000 bytes
LINK_TIME_OPTIMIZATION_ENABLE = yes

# Enable debugging only when needed.
CONSOLE_ENABLE = yes # +400 bytes (hid_listen support)

# Enable combo keys for vim usage.
# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
COMBO_ENABLE = yes

# Disable unused features to save on space
# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
MOUSEKEY_ENABLE = no # 2000 bytes
BOOTMAGIC_ENABLE = no
COMMAND_ENABLE = no # https://beta.docs.qmk.fm/features/feature_command