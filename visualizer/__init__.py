from .ascii import AsciiTemplate
from .keymap import KeyMap
from .svg import SvgLayout


def render_ascii(user_dir, keyboard_dir):
    keymap = KeyMap.load(user_dir, keyboard_dir)
    AsciiTemplate.load(keyboard_dir).render(keymap)

def render_svg(user_dir, keyboard_dir):
    keymap = KeyMap.load(user_dir, keyboard_dir)
    SvgLayout.load(keyboard_dir).render(keymap)
