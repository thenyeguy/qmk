# Ivan's QMK Keyboard Layouts

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

## TODO

- Refactor configs to be more modular, gated by DEFS
- Create unified user config - it's copied in with the QMK script
- Use drashna's tricks to share layouts across ergodox and levinson
- fix 'update.sh' script to pull qmk repo properly, send patch upstream

### levinson

- wrap up LED indicators + sound stuff

### ergodox

- copy over NAVI layer from levinson
