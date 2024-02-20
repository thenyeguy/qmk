import json
import os
from xml.etree import ElementTree

_KEY_SIZE = 80
_KEY_SIZE_RADIUS = 10
_KEY_MARGIN = 4
_KEY_PADDING = 10

_COMBO_RADIUS = 12

_SVG_PADDING = 40
_SVG_STYLE = """
text {
    font-family: sans-serif;
    font-size: 11px;
    fill: rgb(50, 50, 50);

    dominant-baseline: central;
    text-anchor: middle;
}

text.top { dominant-baseline: hanging; }
text.bottom { dominant-baseline: alphabetic; }
text.left { text-anchor: start; }
text.right { text-anchor: end; }

text.base { font-size: 13px; font-weight: 700; }
text.lower { fill: rgb(115, 162, 217); }
text.raise { fill: rgb(217, 148, 69); }
text.adjust { fill: rgb(124, 171, 125); }
text.hold { fill: rgb(150, 150, 150); }

rect, ellipse { fill: rgb(245, 245, 245); }
rect.home { stroke: rgb(225, 225, 225); stroke-width: 1.5px; }

rect.lower { fill: rgb(213, 229, 247); }
rect.raise { fill: rgb(247, 231, 213); }
rect.adjust { fill: rgb(224, 240, 224); }
rect.hold { fill: rgb(225, 225, 225); }

circle.combo {
    stroke: rgb(200, 200, 200);
    fill: rgb(225, 225, 225);
}
text.combo { font-size: 10px; }
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
        width = (
            max(key.x + key.width + _KEY_MARGIN for key in self.keys) + 2 * _SVG_PADDING
        )
        height = (
            max(key.y + key.height + _KEY_MARGIN for key in self.keys)
            + 2 * _SVG_PADDING
        )

        # Create svg file
        svg = ElementTree.Element(
            "svg",
            {
                "xmlns": "http://www.w3.org/2000/svg",
                "viewBox": f"{top} {left} {width} {height}",
            },
        )
        style = ElementTree.SubElement(svg, "style")
        style.text = _SVG_STYLE

        # Render keys.
        for key in self.keys:
            key.render(svg)

        # Render combos.
        for combo in keymap.combos:
            i1 = keymap.get_keycode_index(combo.triggers[0].raw)
            i2 = keymap.get_keycode_index(combo.triggers[1].raw)
            assert i1 + 1 == i2  # only support adjacent keys
            _Combo(self.keys[i1], self.keys[i2], combo.code).render(svg)

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
        self.home = kwargs.get("home", False)
        self.key_codes = {}

    def add_key_code(self, layer, key_code):
        self.key_codes[layer] = key_code

    def render(self, svg):
        for key_code in self.key_codes.values():
            if key_code.encoder:
                self._draw_encoder(svg, key_code)
                return

        self._draw_border(svg)
        for layer, key_code in self.key_codes.items():
            # Tap:
            if key_code.tap:
                self._draw_label(svg, key_code.tap, layer)
            # Hold:
            if key_code.layer:
                self._draw_hold(svg, key_code.hold, key_code.layer.lower())
            elif key_code.hold:
                self._draw_hold(svg, key_code.hold, "hold")

    def _draw_border(self, svg):
        classes = "home" if self.home else ""
        ElementTree.SubElement(
            svg,
            "rect",
            {
                "x": str(self.x),
                "y": str(self.y),
                "width": str(self.width),
                "height": str(self.height),
                "rx": str(_KEY_SIZE_RADIUS),
                "class": classes,
            },
        )

    def _draw_hold(self, svg, label, layer="hold"):
        ElementTree.SubElement(
            svg,
            "rect",
            {
                "x": str(self.x),
                "y": str(self.y + self.height - 2 * _KEY_SIZE_RADIUS),
                "width": str(self.width),
                "height": str(2 * _KEY_SIZE_RADIUS),
                "rx": str(_KEY_SIZE_RADIUS),
                "class": layer,
            },
        )
        ElementTree.SubElement(
            svg,
            "text",
            {
                "x": str(self.x + self.width / 2),
                "y": str(self.y + self.height - _KEY_SIZE_RADIUS),
                "class": layer,
            },
        ).text = label

    def _draw_label(self, svg, label, layer, class_=None):
        classes = [class_ or layer]
        if layer == "base":
            dx = self.width / 2
            dy = self.height / 2
        elif layer in ("lower", "raise"):
            dx = self.width - _KEY_PADDING
            dy = _KEY_PADDING
            classes.extend(["top", "right"])
        elif layer == "adjust":
            dx = _KEY_PADDING
            dy = _KEY_PADDING
            classes.extend(["top", "left"])
        else:
            raise Exception(f"Unknown layer: {layer}")

        ElementTree.SubElement(
            svg,
            "text",
            {
                "x": str(self.x + dx),
                "y": str(self.y + dy),
                "class": " ".join(classes),
            },
        ).text = label

    def _draw_encoder(self, svg, key_code):
        cx = self.x + self.width / 2
        cy = self.y + self.height / 2
        ElementTree.SubElement(
            svg,
            "ellipse",
            {
                "cx": str(cx),
                "cy": str(cy),
                "rx": str(self.width / 2),
                "ry": str(self.height / 2),
            },
        )
        ElementTree.SubElement(
            svg,
            "text",
            {
                "x": str(cx),
                "y": str(cy),
                "class": "center",
            },
        ).text = key_code.encoder


class _Combo(object):
    def __init__(self, k1, k2, keycode):
        self.k1 = k1
        self.k2 = k2
        self.keycode = keycode

    def render(self, svg):
        cx = (self.k1.x + self.k2.x) / 2 + _KEY_SIZE / 2 - _KEY_MARGIN
        cy = (self.k1.y + self.k2.y) / 2 + _KEY_SIZE / 2 - _KEY_MARGIN
        ElementTree.SubElement(
            svg,
            "circle",
            {
                "cx": str(cx),
                "cy": str(cy),
                "r": str(_COMBO_RADIUS),
                "class": "combo",
            },
        )
        ElementTree.SubElement(
            svg,
            "text",
            {
                "x": str(cx),
                "y": str(cy),
                "class": "combo",
            },
        ).text = self.keycode.tap
