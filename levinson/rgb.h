#pragma once
#include "quantum.h"
#include "issmirnov.h"

// Welcome animation when keyboard boots
void keyboard_post_init_rgb(void);

// If rgb enabled, set underglow for layer
uint32_t layer_state_set_rgb(uint32_t state);
