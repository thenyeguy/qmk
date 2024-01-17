import os
import subprocess
import sys

from .ascii import AsciiTemplate
from .keymap import KeyMap
from .svg import SvgLayout


def render_ascii(user_dir, keyboard_dir):
    keymap = KeyMap.load(user_dir, keyboard_dir)
    AsciiTemplate.load(keyboard_dir).render(keymap)


def render_svg(user_dir, keyboard_dir):
    keymap = KeyMap.load(user_dir, keyboard_dir)
    output_file = SvgLayout.load(keyboard_dir).render(keymap)
    print("Wrote svg:", os.path.relpath(output_file))
    _open_file(output_file)


def _open_file(f):
    if sys.platform == "darwin":
        subprocess.run(["open", f], check=True)
