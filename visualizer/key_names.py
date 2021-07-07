import re


_KEY_NAMES = {
    "_______": "",
    "XXXXXXX": "",

    "KC_1": "1 !",
    "KC_2": "2 @",
    "KC_3": "3 #",
    "KC_4": "4 $",
    "KC_5": "5 %",
    "KC_6": "6 ^",
    "KC_7": "7 &",
    "KC_8": "8 *",
    "KC_9": "9 (",
    "KC_0": "0 )",

    "KC_COMM": ", <",
    "KC_DOT": ". >",
    "KC_SLSH": "/ ?",
    "KC_SCLN": "; :",
    "KC_COLN": ":",
    "KC_TILD": "~",
    "KC_GRV": "` ~",
    "KC_BSLS": "\\ |",
    "KC_PIPE": "|",
    "KC_EXLM": "!",
    "KC_AT": "@",
    "KC_HASH": "#",
    "KC_DLR": "$",
    "KC_PERC": "%",
    "KC_CIRC": "^",
    "KC_AMPR": "&",
    "KC_ASTR": "*",
    "KC_UNDS": "_",
    "KC_MINS": "- _",
    "KC_PLUS": "+",
    "KC_EQL": "= +",
    "KC_QUOT": "' \"",
    "KC_DQT": '"',

    "KC_LPRN": "(",
    "KC_RPRN": ")",
    "KC_LBRC": "[",
    "KC_RBRC": "]",
    "KC_LCBR": "{",
    "KC_RCBR": "}",
    "KC_LT": "<",
    "KC_GT": ">",

    "KC_LSFT": "⇑",
    "KC_RSFT": "⇑",
    "KC_LCTL": "⌃",
    "KC_RCTL": "⌃",
    "KC_LALT": "⎇",
    "KC_RALT": "⎇",
    "KC_LGUI": "◇",
    "KC_RGUI": "◇",

    "_LOWER": "⇊",
    "_RAISE": "⇈",
    "ADJUST": "⇅",

    "KC_SPC": "␣",
    "KC_ENT": "↵",
    "KC_TAB": "↹",
    "KC_ESC": "⎋",
    "KC_BSPC": "⌫",
    "KC_DEL": "⌦",

    "KC_UP": "↑",
    "KC_DOWN": "↓",
    "KC_LEFT": "←",
    "KC_RGHT": "→",

    "KC_PGDN": "PgDn",
    "KC_PGUP": "PgUp",
    "KC_MPLY": "Play",
    "KC_MPRV": "Prev",
    "KC_MNXT": "Next",
    "KC_VOLD": "Vol-",
    "KC_VOLU": "Vol+",

    "MAGIC_TOGGLE_CTL_GUI": "𝝙OS",
}

_MOD_NAMES = {
    # Hold modifiers:
    "LGUI_T": "◇",
    "RGUI_T": "◇",
    "LCTL_T": "⌃",
    "RCTL_T": "⌃",
    "LALT_T": "⎇",
    "RALT_T": "⎇",
    "LSFT_T": "⇑",
    "RSFT_T": "⇑",
}


def default_name(code):
    return code.replace("KC_", "").title().replace("_", "")


def get_key_name(code):
    mod = ""
    match = re.match(r"(\w+)\((\w+)\)", code)
    if match:
        code = match.group(2)
        mod = match.group(1)

    name = _KEY_NAMES.get(code, default_name(code))
    mod = _MOD_NAMES.get(mod, "")
    if mod:
        name += "╱" + mod
    return name
