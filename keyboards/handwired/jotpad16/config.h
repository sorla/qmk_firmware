#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 4

/* pro_micro pin-out */
#define MATRIX_ROW_PINS { E6, D7, B3, B1 }
#define MATRIX_COL_PINS { D3, D2, B2, B6 }
#define UNUSED_PINS

/* leds */
#define JOTPAD16_LEDS
#define JOTPAD16_LED1 B5
#define JOTPAD16_LED2 B4
#define QMK_LED B5

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 0

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
