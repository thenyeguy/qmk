import re


_KEY_NAMES = {
    "_______": "",
    "XXXXXXX": "",

    "KC_COMM": ",",
    "KC_DOT": ".",
    "KC_SLSH": "/",
    "KC_SCLN": ";",
    "KC_COLN": ":",
    "KC_TILD": "~",
    "KC_GRV": "`",
    "KC_BSLS": "\\",
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
    "KC_MINS": "-",
    "KC_PLUS": "+",
    "KC_EQL": "=",
    "KC_QUOT": "'",
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

    "AG_NORM": "Linux",
    "AG_SWAP": "Mac",
}


def default_name(code):
    return code.replace("KC_", "").title().replace("_", "")


def get_key_name(code):
    match = re.match(r"(\w+)\((\w+)\)", code)
    if match:
        code = match.group(2)
    return _KEY_NAMES.get(code, default_name(code))
