#!/usr/bin/env bash

echo "updating .git/config with hook folder"
git config core.hooksPath hooks

echo "setting up qmk git submodule"
git submodule init
git submodule update
git submodule sync --recursive

echo "Running QMK installer"
cd qmk_firmware
./util/qmk_install.sh
make git-submodule
cd ..

echo "Verifying udev rules, patching if needed"
# set up udev rules
if [[ $OSTYPE == linux-* ]]; then

    if [[ ! -f /etc/udev/rules.d/49-teensy.rules ]];then
        echo "Creating udev rules for flashing teensy"
        cat <<EOF | sudo tee /etc/udev/rules.d/49-teensy.rules
ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="04[789B]?", ENV{ID_MM_DEVICE_IGNORE}="1"
ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="04[789A]?", ENV{MTP_NO_PROBE}="1"
SUBSYSTEMS=="usb", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="04[789ABCD]?", MODE:="0666"
KERNEL=="ttyACM*", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="04[789B]?", MODE:="0666"
EOF
    fi

    if [[ ! -f /etc/udev/rules.d/51-atmel-dfu.rules ]];then
        echo "Creating udev rules for flashing dfu."
        cat <<EOF | sudo tee /etc/udev/rules.d/51-atmel-dfu.rules
# Atmel ATMega32U4
SUBSYSTEMS=="usb", ATTRS{idVendor}=="03eb", ATTRS{idProduct}=="2ff4", MODE:="0666"
# Atmel USBKEY AT90USB1287
SUBSYSTEMS=="usb", ATTRS{idVendor}=="03eb", ATTRS{idProduct}=="2ffb", MODE:="0666"
# Atmel ATMega32U2
SUBSYSTEMS=="usb", ATTRS{idVendor}=="03eb", ATTRS{idProduct}=="2ff0", MODE:="0666"
EOF
    fi
fi
