import os
import subprocess
import sys

from .ascii import AsciiTemplate
from .keymap import KeyMap
from .svg import SvgLayout


def abs_path(*paths):
    dirname = os.path.abspath(os.path.dirname(os.path.dirname(__file__)))
    return os.path.join(dirname, *paths)


def render_ascii(keyboard):
    user_dir = abs_path("users/mnye")
    keyboard_dir = abs_path("keyboards", keyboard, "keymaps/mnye")
    keymap = KeyMap.load(user_dir, keyboard_dir)
    AsciiTemplate.load(keyboard_dir).render(keymap)


def render_svg(keyboard):
    user_dir = abs_path("users/mnye")
    keyboard_dir = abs_path("keyboards", keyboard, "keymaps/mnye")
    keymap = KeyMap.load(user_dir, keyboard_dir)

    output_file = abs_path(keyboard.replace("/", "_") + "_mnye.svg")
    SvgLayout.load(keyboard_dir).render(keymap, output_file)
    print("Wrote svg:", os.path.relpath(output_file))
    _maybe_open_file(output_file)


def _maybe_open_file(f):
    if sys.platform == "darwin":
        subprocess.run(["open", f], check=True)
