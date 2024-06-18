import os
import re


_COMBO_BATCH_SIZE = 4


class AsciiTemplate(object):
    @classmethod
    def load(cls, keyboard_dir):
        with open(os.path.join(keyboard_dir, "template.txt")) as f:
            return cls(f.read())

    def __init__(self, template):
        self.width = max(len(line) for line in template.split("\n"))
        self.template = template.rstrip()

    def render(self, keymap):
        print("{:^{}}".format("Combos", self.width))
        combos = [_render_combo(combo) for combo in keymap.combos]
        for i in range(0, len(combos), _COMBO_BATCH_SIZE):
            batch = combos[i : i + _COMBO_BATCH_SIZE]
            print("{:^{}}".format("    ".join(batch), self.width))

        for layer in keymap.layers:
            rendered = self.template
            for i, key in enumerate(layer.key_codes()):
                match = re.search(r" *(?<!\d)_{}(?!\d) *".format(i), rendered).group()
                label = _render_key(key, len(match))
                rendered = rendered.replace(match, label)
            print()
            print("{:^{}}".format(layer.name.title(), self.width))
            print(rendered)


def _render_key(key, width):
    label = "╱".join(l for l in [key.tap, key.hold] if l)
    return "{:^{width}.{width}}".format(label, width=width)


def _render_combo(combo):
    def _label(k):
        return k.tap.split(" ")[0]

    return "+".join(_label(c) for c in combo.triggers) + " -> " + combo.code.tap
