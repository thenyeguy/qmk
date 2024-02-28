#!/bin/sh

qmk setup --home ~/.local/share/qmk_firmware
qmk config user.overlay_dir="$(realpath .)"
qmk config user.keymap="mnye"
