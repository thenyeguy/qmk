import json
import os


_KEY_SIZE = 80
_KEY_SIZE_RADIUS = 8
_KEY_MARGIN = 5
_KEY_PADDING = 8

_SVG_TEMPLATE = """
<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 {width} {height}">
<style>
    text {{
        font-family: sans-serif;
        font-size: 12px;
        stroke: none;
    }}
    text.colemak {{
        dominant-baseline: central;
        text-anchor: middle;
        fill: rgb(50, 50, 50);
    }}
    text.lower {{
        dominant-baseline: hanging;
        text-anchor: start;
        fill: rgb(123, 174, 232);
    }}
    text.raise {{
        dominant-baseline: hanging;
        text-anchor: end;
        fill: rgb(242, 165, 78);
    }}
    text.adjust {{
        dominant-baseline: alphabetic;
        text-anchor: middle;
        fill: rgb(180, 180, 180);
    }}
    rect {{
        fill: rgb(250, 250, 250);
        stroke: rgb(180, 180, 180);
        stroke-width: 0.5;
    }}
</style>

{shapes}
</svg>
"""


class SvgLayout(object):

    @classmethod
    def load(cls, keyboard_dir):
        output_file = os.path.join(keyboard_dir, "keymap.svg")
        with open(os.path.join(keyboard_dir, "svg_layout.json")) as f:
            keys = []
            for key in json.load(f):
                keys.append(_Key(**key))
            return cls(keys, output_file)

    def __init__(self, keys, output_file):
        self.keys = keys
        self.output_file = output_file

    def render(self, keymap):
        shapes = []

        # Render key borders
        for key in self.keys:
            shapes.append(key.draw_border())

        # Render key labels
        for layer in keymap.layers:
            for i, name in enumerate(layer.key_names()):
                shapes.append(
                    self.keys[i].draw_label(
                        name, layer.name.lower()))

        # Compute viewbox.
        width = 0
        height = 0
        for key in self.keys:
            width = max(width, key.x + key.width + _KEY_MARGIN)
            height = max(height, key.y + key.height + _KEY_MARGIN)

        # Write out rendered svg.
        with open(self.output_file, "w") as f:
            f.write(
                _SVG_TEMPLATE.format(
                    width=width,
                    height=height,
                    shapes="\n".join(shapes)))
        return self.output_file


class _Key(object):

    def __init__(self, x, y, **kwargs):
        self.x = x * _KEY_SIZE + _KEY_MARGIN
        self.y = y * _KEY_SIZE + _KEY_MARGIN
        self.width = kwargs.get("w", 1) * _KEY_SIZE - 2 * _KEY_MARGIN
        self.height = kwargs.get("h", 1) * _KEY_SIZE - 2 * _KEY_MARGIN

    def draw_border(self):
        return """<rect x="{x}" y="{y}"
                   width="{w}" height="{h}" rx="{r}" />""".format(
            x=self.x, y=self.y, r=_KEY_SIZE_RADIUS, w=self.width, h=self.height)

    def draw_label(self, label, layer):
        label = label.replace("&", "&amp;")
        label = label.replace("<", "&lt;").replace(">", "&gt;")

        if layer == "colemak":
            dx = self.width / 2
            dy = self.height / 2
        elif layer == "lower":
            dx = _KEY_PADDING
            dy = _KEY_PADDING
        elif layer == "raise":
            dx = self.width - _KEY_PADDING
            dy = _KEY_PADDING
        elif layer == "adjust":
            dx = self.width / 2
            dy = self.height - _KEY_PADDING
        else:
            raise Exception("Unknown layer: {}".format(layer))

        return """<text x="{x}" y="{y}" class="{layer}">{label}</text>""".format(
            x=self.x + dx, y=self.y + dy, label=label, layer=layer)
