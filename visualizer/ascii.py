import os
import re


class AsciiTemplate(object):

    @classmethod
    def load(cls, keyboard_dir):
        with open(os.path.join(keyboard_dir, "template.txt")) as f:
            return cls(f.read())

    def __init__(self, template):
        self.width = max(len(line) for line in template.split("\n"))
        self.template = template

    def render(self, keymap):
        for layer in keymap.layers:
            rendered = self.template
            for i, key in enumerate(layer.key_names()):
                match = re.search(
                    r" *(?<!\d)_{}(?!\d) *".format(i), rendered).group()
                label = "{:^{width}.{width}}".format(key, width=len(match))
                rendered = rendered.replace(match, label)
            print("{:^{}}".format(layer.name.title(), self.width))
            print(rendered)
