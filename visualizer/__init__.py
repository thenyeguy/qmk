from .keymap import KeyMap


def visualize(user_dir, keyboard_dir):
    KeyMap.load(user_dir, keyboard_dir).visualize()
