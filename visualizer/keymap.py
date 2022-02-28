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
        return cls(layers)

    def __init__(self, layers):
        self.layers = layers


class _Rows(object):
    def __init__(self, rows):
        self.rows = rows

    def expand(self, line):
        for (name, keys) in self.rows.items():
            line = line.replace(name, keys)
        return line


class _Layer(object):
    def __init__(self, name, codes):
        self.name = name
        self.codes = codes

    def key_codes(self):
        for code in self.codes:
            yield KeyCode(code)


def _load_rows(row_lines):
    row_re = re.compile(r"#define (\w+) +(.*)")

    rows = dict()
    for line in row_lines:
        match = row_re.match(line)
        if match:
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
