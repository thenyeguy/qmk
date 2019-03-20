#!/usr/bin/env python3


import argparse
import os
import shutil
import subprocess
import sys
import time


def abs_path(*paths):
    dirname = os.path.abspath(os.path.dirname(__file__))
    return os.path.join(dirname, *paths)


class QmkBuilder(object):
    def __init__(self, keyboard):
        self.qmk_root = abs_path("qmk_firmware")
        self.local_config_dir = abs_path(keyboard)
        self.qmk_config_dir = os.path.join(self.qmk_root, "keyboards",
                                           keyboard, "keymaps", "mnye")

    def __enter__(self):
        if os.path.exists(self.qmk_config_dir):
            shutil.rmtree(self.qmk_config_dir)
        shutil.copytree(self.local_config_dir, self.qmk_config_dir)
        return self

    def execute(self, script):
        cmd = os.path.join(self.local_config_dir, script)
        subprocess.check_call(cmd, cwd=self.qmk_root)

    def __exit__(self, *_):
        shutil.rmtree(self.qmk_config_dir)


def build(keyboard, push=False):
    with QmkBuilder(keyboard) as builder:
        print("Building {}...".format(keyboard))
        builder.execute("build.sh")


def push(keyboard):
    with QmkBuilder(keyboard) as builder:
        print("Put your {} into bootlader mode".format(keyboard), end="")
        for _ in range(0, 5):
            print(".", end="")
            sys.stdout.flush()
            time.sleep(1)
        print()

        print("Updating {}...".format(keyboard))
        builder.execute("push.sh")


def main(argv):
    parser = argparse.ArgumentParser(description="Build util for QMK")
    parser.add_argument("command", nargs=1, choices=["build", "push"])
    parser.add_argument("keyboard", nargs=1)
    args = parser.parse_args()

    keyboard = args.keyboard[0].strip("/")
    if not os.path.isdir(abs_path(keyboard)):
        print("Invalid keyboard: {}".format(keyboard))
        return 1

    try:
        command = args.command[0]
        if command == "build":
            build(keyboard)
        elif command == "push":
            push(keyboard)
    except KeyboardInterrupt:
        print()
        print("Aborting.")


if __name__ == "__main__":
    sys.exit(main(sys.argv))
