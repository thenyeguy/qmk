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

    "KC_LSFT": "Shift",
    "KC_RSFT": "Shift",
    "KC_LCTL": "Ctl",
    "KC_RCTL": "Ctl",
    "KC_LALT": "Alt",
    "KC_RALT": "Alt",
    "KC_LGUI": "Mod",
    "KC_RGUI": "Mod",

    "KC_SPC": "⎵",
    "KC_SPACE": "⎵",
    "KC_ENT": "Enter",
    "KC_BSPC": "BckSp",
    "KC_SFTENT": "Enter",

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


    "KC_SCOLON": ";",
    "KC_MINUS": "-",
    "KC_LBRACKET": "[",
    "KC_RBRACKET": "]",
    "KC_AUDIO_VOL_DOWN": "Vol-",
    "KC_AUDIO_VOL_UP": "Vol+",
    "KC_MEDIA_PLAY_PAUSE": "Play",
    "KC_MEDIA_NEXT_TRACK": "Next",
    "KC_ESCAPE": "Esc",
    "KC_BSLASH": "\\",
    "KC_EQUAL": "=",
    "KC_QUOTE": "'",
    "KC_COMMA": ",",
    "KC_SLASH": "/",
    "KC_KP_DOT": ".",

    # "KC_LEAD": "Lead",
    "E_NUMBERS": "E|LT3",
    "R_MOUSE": "R|LT4",
    # "LT(MOUSE,KC_R)": "R LT mouse",
    "TG(BEAKL)": "TG Beakl",
    "TG(WORKMAN)": "TG Workman",
    "KC_NONUS_BSLASH": "`",
    "KC_AUDIO_MUTE": "Mute",
    "LCTL(KC_B)": "Ctrl + B",
    "ALT_TAB": "⎇ + Tab",
}


def get_key_name(code):
    if code in _KEY_NAMES:
        return _KEY_NAMES[code]
    if re.match(r"[LR]SFT_T\(", code):
        res = re.search(r"\((.+)\)", code)
        return get_key_name(res.group(1)) + " | ⇧"
    if re.match(r"[LR]CTL_T\(", code):
        res = re.search(r"\((.+)\)", code)
        return get_key_name(res.group(1)) + " | ⌃"
    if re.match(r"[LR]ALT_T\(", code):
        res = re.search(r"\((.+)\)", code)
        return get_key_name(res.group(1)) + " | ⌥"
    if re.match(r"[LR]GUI_T\(", code):
        res = re.search(r"\((.+)\)", code)
        return get_key_name(res.group(1)) + " | ⌘"
    return replace(code)

def replace(code):
    return code.replace("KC_", "").title().replace("_", "")
