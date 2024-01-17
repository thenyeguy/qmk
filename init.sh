#!/bin/sh

qmk setup ~/.local/share/qmk_firmware
qmk config user.overlay_dir="$(realpath .)"
qmk config user.keymap="mnye"
