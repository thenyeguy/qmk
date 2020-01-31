#!/bin/bash

git submodule sync
git submodule update --init --remote --progress

pushd qmk_firmware
make git-submodule
