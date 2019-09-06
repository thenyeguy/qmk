# Ivan's QMK Keyboard Layouts

[![Build Status](https://travis-ci.org/issmirnov/qmk-keebs.svg?branch=master)](https://travis-ci.org/issmirnov/qmk-keebs)

Forked from https://github.com/thenyeguy/qmk - thank you to @thenyeguy for the structure and template setup.

Supported Keyboards:

- Ergodox EZ
- Levinson
- Planck

## Commands

- `init.sh` for initial setup of repo after cloning. Will run [qmk_install.sh](https://github.com/qmk/qmk_firmware/blob/master/util/qmk_install.sh)
- `update.sh` will pull upstream changes to QMK. Note: Currently there is no sanity checking for breakages, so run a build to test.
- `qmk` is a util script that is used to interact with this repo. Available subcommands:
  - `build` - compiles layout into hex file
  - `push` - flashes firmware to keyboard
  - `show` - displays layout in visualizer
- `cd qmk_firmware && make clean` - clear stale builds, solves odd bugs

## Caveats

- `OSM` key has to be tapped withing the `TAPPING_TERM` timeout, otherwise it will be ignored. The current timeout is `50ms`, since otherwise the `TAP_TOG` key becomes useless.
