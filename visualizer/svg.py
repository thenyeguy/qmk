import json
import os
from xml.etree import ElementTree


_KEY_SIZE = 80
_KEY_SIZE_RADIUS = 8
_KEY_MARGIN = 5
_KEY_PADDING = 8

_SVG_STYLE = """
text {
    font-family: sans-serif;
    font-size: 12px;
    stroke: none;
}
text.colemak {
    dominant-baseline: central;
    text-anchor: middle;
    fill: rgb(50, 50, 50);
}
text.lower {
    dominant-baseline: hanging;
    text-anchor: start;
    fill: rgb(123, 174, 232);
}
text.raise {
    dominant-baseline: hanging;
    text-anchor: end;
    fill: rgb(242, 165, 78);
}
text.adjust {
    dominant-baseline: alphabetic;
    text-anchor: middle;
    fill: rgb(180, 180, 180);
}
rect {
    fill: rgb(250, 250, 250);
    stroke: rgb(180, 180, 180);
    stroke-width: 0.5;
}
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
        # Compute viewbox
        width = max(key.x + key.width + _KEY_MARGIN for key in self.keys)
        height = max(key.y + key.height + _KEY_MARGIN for key in self.keys)

        # Create svg root
        svg = ElementTree.Element("svg", {
            "xmlns": "http://www.w3.org/2000/svg",
            "viewBox": f"0 0 {width} {height}"
        })
        style = ElementTree.SubElement(svg, "style")
        style.text = _SVG_STYLE

        # Render key borders
        for key in self.keys:
            key.draw_border(svg)

        # Render key labels
        for layer in keymap.layers:
            for key, code in zip(self.keys, layer.key_codes()):
                key.draw_label(svg, code.as_ascii(), layer.name.lower())

        # Write out rendered svg.
        with open(self.output_file, "wb") as f:
            tree = ElementTree.ElementTree(svg)
            ElementTree.indent(tree)
            tree.write(f)
        return self.output_file


class _Key(object):

    def __init__(self, x, y, **kwargs):
        self.x = x * _KEY_SIZE + _KEY_MARGIN
        self.y = y * _KEY_SIZE + _KEY_MARGIN
        self.width = kwargs.get("w", 1) * _KEY_SIZE - 2 * _KEY_MARGIN
        self.height = kwargs.get("h", 1) * _KEY_SIZE - 2 * _KEY_MARGIN

    def draw_border(self, svg):
        ElementTree.SubElement(svg, "rect", {
            "x": str(self.x),
            "y": str(self.y),
            "width": str(self.width),
            "height": str(self.height),
            "rx": str(_KEY_SIZE_RADIUS),
        })

    def draw_label(self, svg, label, layer):
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
            raise Exception(f"Unknown layer: {layer}")

        text = ElementTree.SubElement(svg, "text", {
            "x": str(self.x + dx),
            "y": str(self.y + dy),
            "class": layer,
        })
        text.text = label
