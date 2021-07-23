from .ascii import AsciiTemplate
from .keymap import KeyMap


def render_ascii(user_dir, keyboard_dir):
    keymap = KeyMap.load(user_dir, keyboard_dir)
    AsciiTemplate.load(keyboard_dir).render(keymap)
