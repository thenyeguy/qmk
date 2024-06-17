import re


_TAP_CODES = {
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
    "KC_SPC": "␣",
    "KC_ENT": "↵",
    "KC_TAB": "↹",
    "KC_ESC": "⎋",
    "KC_BSPC": "⌫",
    "KC_DEL": "⌦",
    "KC_CAPS": "⇪",
    "CW_TOGG": "⇪",
    "KC_UP": "↑",
    "KC_DOWN": "↓",
    "KC_LEFT": "←",
    "KC_RGHT": "→",
    "KC_PGDN": "↧",
    "KC_PGUP": "↥",
    "KC_HOME": "⇱",
    "KC_END": "⇲",
    "KC_MPLY": "⏯",
    "KC_MPRV": "⏮",
    "KC_MNXT": "⏭",
    "KC_VOLD": "Vol-",
    "KC_VOLU": "Vol+",
    "MAGIC_TOGGLE_CTL_GUI": "𝝙OS",
    "QK_BOOT": "Flash",
}

_GUI_SYMBOL = "⌘"
_CTL_SYMBOL = "⌃"
_ALT_SYMBOL = "⌥"
_SFT_SYMBOL = "⇧"

_HOLD_CODES = {
    "KC_LGUI": _GUI_SYMBOL,
    "KC_RGUI": _GUI_SYMBOL,
    "KC_LCTL": _CTL_SYMBOL,
    "KC_RCTL": _CTL_SYMBOL,
    "KC_LALT": _ALT_SYMBOL,
    "KC_RALT": _ALT_SYMBOL,
    "KC_LSFT": _SFT_SYMBOL,
    "KC_RSFT": _SFT_SYMBOL,
}

_MODIFIER_CODES = {
    "LGUI_T": _GUI_SYMBOL,
    "RGUI_T": _GUI_SYMBOL,
    "LCTL_T": _CTL_SYMBOL,
    "RCTL_T": _CTL_SYMBOL,
    "LALT_T": _ALT_SYMBOL,
    "RALT_T": _ALT_SYMBOL,
    "LSFT_T": _SFT_SYMBOL,
    "RSFT_T": _SFT_SYMBOL,
}

_LAYER_CODES = {
    "LOWER": "⇊",
    "RAISE": "⇈",
    "ADJUST": "⇅",
}

_TRILAYERS = {
    "TL_LOWR": "LOWER",
    "TL_UPPR": "RAISE",
}

_ENCODER_CODES = {
    "ENC_NAV": "↤ ⏾ ↦",
    "ENC_MEDIA": "⇣ ⏯ ⇡",
}


class KeyCode(object):
    def __init__(self, code):
        mod = None
        if match := re.match(r"(\w+)\((\w+)\)", code):
            code = match.group(2)
            mod = match.group(1)

        self.raw = code
        self.tap = None
        self.hold = None
        self.layer = None
        self.encoder = None

        if mod in _MODIFIER_CODES:
            self.hold = _MODIFIER_CODES[mod]

        if code in _TRILAYERS:
            code = _TRILAYERS[code]

        if mod == "MO" or code in _LAYER_CODES:
            self.layer = code.removeprefix("_")
            self.hold = _LAYER_CODES.get(self.layer, self.layer)
        elif code in _HOLD_CODES:
            self.hold = _HOLD_CODES[code]
        elif code in _ENCODER_CODES:
            self.tap = _ENCODER_CODES[code]
        else:
            if code in _TAP_CODES:
                self.tap = _TAP_CODES[code]
            else:
                self.tap = code.replace("KC_", "").title().replace("_", "")
