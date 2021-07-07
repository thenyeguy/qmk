import os
import re

from .key_names import get_key_name


class KeyMap(object):

    @classmethod
    def load(cls, user_dir, keyboard_dir):
        with open(os.path.join(user_dir, "rows.h")) as f:
            rows = _load_rows(f)
        with open(os.path.join(keyboard_dir, "keymap.c")) as f:
            layers = _load_layers(f, rows)
        with open(os.path.join(keyboard_dir, "template.txt")) as f:
            template = _Template(f.read())
        return cls(template, layers)

    def __init__(self, template, layers):
        self.template = template
        self.layers = layers

    def visualize(self):
        for layer in self.layers:
            print(self.template.render(layer))


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

    def key_names(self):
        for code in self.codes:
            yield get_key_name(code)


class _Template(object):

    def __init__(self, template):
        self.width = max(len(line) for line in template.split("\n"))
        self.template = template

    def render(self, layer):
        rendered = self.template
        for i, key in enumerate(layer.key_names()):
            match = re.search(" *(?<!\d)_{}(?!\d) *".format(i), rendered).group()
            label = "{:^{width}.{width}}".format(key, width=len(match))
            rendered = rendered.replace(match, label)
        return "{:^{}}\n".format(layer.name.title(), self.width) + rendered


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
                codes += filter(None,
                                (code.strip() for code in line.split(",")))
        elif start:
            layer_name = start.group(1)
            codes = []
    return layers
