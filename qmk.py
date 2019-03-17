#!/usr/bin/env python3


import argparse
import os
import shutil
import subprocess
import sys


def abs_path(*paths):
    dirname = os.path.abspath(os.path.dirname(__file__))
    return os.path.join(dirname, *paths)


def call(cmd, cwd):
    """ Calls the provided shell command. """
    proc = subprocess.Popen(cmd, cwd=cwd, stdout=subprocess.PIPE,
                            stderr=subprocess.PIPE)
    for line in proc.stdout:
        print(line.rstrip().decode("utf-8"))


def build(keyboard, push=False):
    print("Building {}...".format(keyboard))

    config_dir = abs_path(keyboard)
    if push:
        build_script = os.path.join(config_dir, "push.sh")
    else:
        build_script = os.path.join(config_dir, "build.sh")

    qmk_root = abs_path("qmk_firmware")
    qmk_dir = os.path.join(qmk_root, "keyboards",
                           keyboard, "keymaps", "mnye")

    if os.path.exists(qmk_dir):
        shutil.rmtree(qmk_dir)
    shutil.copytree(config_dir, qmk_dir)
    call(build_script, qmk_root)
    shutil.rmtree(qmk_dir)


def main(argv):
    parser = argparse.ArgumentParser(description="Build util for QMK")
    parser.add_argument("keyboard", nargs=1, help="the keyboard config")
    parser.add_argument("--push", action="store_true",
                        help="push the config to the keyboard")
    args = parser.parse_args()

    keyboard = args.keyboard[0].strip("/")
    if not os.path.isdir(abs_path(keyboard)):
        print("Invalid keyboard: {}".format(keyboard))
        return 1

    build(keyboard, args.push)


if __name__ == "__main__":
    sys.exit(main(sys.argv))
