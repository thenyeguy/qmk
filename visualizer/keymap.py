import os
import re

from .key_codes import KeyCode


class KeyMap(object):
    @classmethod
    def load(cls, user_dir, keyboard_dir):
        with open(os.path.join(user_dir, "rows.h")) as f:
            rows = _load_rows(f)
        with open(os.path.join(keyboard_dir, "keymap.c")) as f:
            layers = _load_layers(f, rows)
        with open(os.path.join(user_dir, "combos.c")) as f:
            combos = _load_combos(f)
        return cls(layers, combos)

    def __init__(self, layers, combos):
        self.layers = layers
        self.combos = combos

    def get_keycode_index(self, keycode):
        for layer in self.layers:
            for i, k in enumerate(layer.codes):
                if keycode == k:
                    return i
        raise ValueError("keycode {} not found".format(keycode))


class _Rows(object):
    def __init__(self, rows):
        self.rows = rows

    def expand(self, line):
        for name, keys in self.rows.items():
            line = line.replace(name, keys)
        return line


class _Layer(object):
    def __init__(self, name, codes):
        self.name = name
        self.codes = codes

    def key_codes(self):
        for code in self.codes:
            yield KeyCode(code)


class _Combo(object):
    def __init__(self, triggers, code):
        self.triggers = [KeyCode(t) for t in triggers]
        self.code = KeyCode(code)


def _load_rows(row_lines):
    row_re = re.compile(r"#define (\w+) +(.*)")

    rows = dict()
    for line in row_lines:
        if match := row_re.match(line):
            # Don't expand custom keycode macros.
            if not match.group(1).startswith("KC_"):
                rows[match.group(1)] = match.group(2)
    return _Rows(rows)


def _load_layers(keymap_lines, rows):
    start_re = re.compile(r"^\[_(\w+)\] =")
    end_re = re.compile(r"^\),")

    layers = []
    layer_name = None
    codes = None
    for line in keymap_lines:
        line = rows.expand(line)
        start = start_re.match(line)
        if layer_name:
            if end_re.match(line):
                layers.append(_Layer(layer_name, codes))
                layer_name = None
                codes = None
            else:
                codes += filter(None, (code.strip() for code in line.split(",")))
        elif start:
            layer_name = start.group(1)
            codes = []
    return layers


def _load_combos(combo_lines):
    trigger_re = re.compile(r"(\w+)\[\] = {(.+), (.+), COMBO_END}")
    combo_re = re.compile(r"COMBO\((\w+), (\w+)\)")

    triggers = dict()
    combos = []
    for line in combo_lines:
        if trigger := trigger_re.search(line):
            triggers[trigger.group(1)] = (trigger.group(2), trigger.group(3))
        elif combo := combo_re.search(line):
            combos.append(_Combo(triggers[combo.group(1)], combo.group(2)))
    return combos
