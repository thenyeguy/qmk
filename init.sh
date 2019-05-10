#!/bin/bash
git submodule init
git submodule sync --recursive
qmk_firmware/util/qmk_install.sh
