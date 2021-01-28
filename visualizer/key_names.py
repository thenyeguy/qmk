# source: https://graphemica.com/
_KEY_NAMES = {
    "_______": "",
    "XXXXXXX": "",

    "KC_COMM": ",",
    "KC_DOT": ".",
    "KC_SLSH": "/",
    "KC_SCLN": ";",
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

    "KC_LABK": '<',
    "KC_RABK": '>',
    "KC_LBRACKET": '[',
    "KC_RBRACKET": ']',
    "KC_SLASH": '/',
    "KC_QUES": '?',
    "KC_BSLASH": '\\',
    "KC_QUOTE": '\'',
    "KC_UP": '↑',
    "KC_DOWN": '↓',
    "KC_LEFT": '←',
    "KC_RGHT": '→',

    "KC_COLN": ":",

    "KC_LALT": "⎇",
    "KC_LGUI": "⌘",
    "KC_SCOLON": ";",
    "KC_BSPACE": "⌫",
    "KC_SPACE": "⎵",

    "LOCK": "🔒",
    "OSMSFT": "⇧(1)",
    "MODSFT": "⌘⇧",
    "APPS": "⌘ + d",
    # "KC_LALT": "Alt",
    # "KC_LGUI": "Mod",
    "KC_LSFT": "Shift",
    "KC_RSFT": "Shift",
    "KC_LCTL": "Ctrl",
    "KC_LALT": "Alt",
    "KC_LGUI": "Mod",
    "KC_ENT": "Enter",
    "KC_SFTENT": "Enter",

    "KC_PGDN": "PgDn",
    "KC_PGUp": "PgUp",
    "KC_MPLY": "Play",
    "KC_MPRV": "Prev",
    "KC_MNXT": "Next",
    "KC_VOLD": "Vol-",
    "KC_VOLU": "Vol+",

    "AG_NORM": "Linux",
    "AG_SWAP": "Mac",
}


def get_key_name(code):
    if code in _KEY_NAMES:
        return _KEY_NAMES[code]
    else:
        return code.replace("KC_", "").title().replace("_", "")
