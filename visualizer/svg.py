import json
import os
from xml.etree import ElementTree

_KEY_SIZE = 80
_KEY_SIZE_RADIUS = 10
_KEY_MARGIN = 4
_KEY_PADDING = 10

_SVG_PADDING = 40
_SVG_STYLE = """
text {
    font-family: sans-serif;
    font-size: 12px;
    stroke: none;
}

text.top { dominant-baseline: hanging; }
text.bottom { dominant-baseline: alphabetic; }
text.left { text-anchor: start; }
text.right { text-anchor: end; }

text.colemak { fill: rgb(50, 50, 50); }
text.hold { fill: rgb(180, 180, 180); }
text.lower { fill: rgb(115, 162, 217); }
text.raise { fill: rgb(217, 148, 69); }
text.adjust { fill: rgb(180, 180, 180); }

rect {
    fill: rgb(250, 250, 250);
    stroke: rgb(180, 180, 180);
    stroke-width: 0.5;
}
rect.lower {
    fill: rgb(213, 229, 247);
    stroke: rgb(115, 162, 217);
}
rect.raise {
    fill: rgb(247, 231, 213);
    stroke: rgb(217, 148, 69);
}
rect.adjust {
    fill: rgb(230, 230, 230);
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
        # Attach keymap to keys.
        for layer in keymap.layers:
            for key, code in zip(self.keys, layer.key_codes()):
                key.add_key_code(layer.name.lower(), code)

        # Compute viewbox
        top = -_SVG_PADDING
        left = -_SVG_PADDING
        width = max(key.x + key.width + _KEY_MARGIN
                    for key in self.keys) + 2 * _SVG_PADDING
        height = max(key.y + key.height + _KEY_MARGIN
                     for key in self.keys) + 2 * _SVG_PADDING

        # Create svg file
        svg = ElementTree.Element("svg", {
            "xmlns": "http://www.w3.org/2000/svg",
            "viewBox": f"{top} {left} {width} {height}"
        })
        style = ElementTree.SubElement(svg, "style")
        style.text = _SVG_STYLE
        for key in self.keys:
            key.render(svg)

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
        self.key_codes = {}

    def add_key_code(self, layer, key_code):
        self.key_codes[layer] = key_code

    def render(self, svg):
        class_ = None
        for key_code in self.key_codes.values():
            if key_code.layer:
                class_ = key_code.layer.lower()

        self._draw_border(svg, class_)
        for layer, key_code in self.key_codes.items():
            if key_code.tap:
                self._draw_label(svg, key_code.tap, layer)
            if key_code.hold:
                self._draw_label(svg, key_code.hold, "hold", class_)

    def _draw_border(self, svg, class_=None):
        rect = ElementTree.SubElement(svg, "rect", {
            "x": str(self.x),
            "y": str(self.y),
            "width": str(self.width),
            "height": str(self.height),
            "rx": str(_KEY_SIZE_RADIUS),
        })
        if class_:
            rect.set("class", class_)

    def _draw_label(self, svg, label, layer, class_=None):
        classes = [class_ or layer]
        if layer == "colemak":
            dx = _KEY_PADDING
            dy = _KEY_PADDING
            classes.extend(["top", "left"])
        elif layer == "hold":
            dx = _KEY_PADDING
            dy = self.height - _KEY_PADDING
            classes.extend(["bottom", "left"])
        elif layer in ("lower", "raise"):
            dx = self.width - _KEY_PADDING
            dy = _KEY_PADDING
            classes.extend(["top", "right"])
        elif layer == "adjust":
            dx = self.width - _KEY_PADDING
            dy = self.height - _KEY_PADDING
            classes.extend(["bottom", "right"])
        else:
            raise Exception(f"Unknown layer: {layer}")

        text = ElementTree.SubElement(svg, "text", {
            "x": str(self.x + dx),
            "y": str(self.y + dy),
            "class": " ".join(classes),
        })
        text.text = label
