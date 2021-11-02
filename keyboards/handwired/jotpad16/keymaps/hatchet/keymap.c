// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include QMK_KEYBOARD_H
#include "keymap_uk.h"


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum hatchet_layers {
    _BASE,
    _NUM,
    _NAV,
    _FUN,
};

#define _______ KC_TRNS
#define ___x___ KC_NO
#define GO_NUM  TO(_NUM)
#define GO_HOME TO(_BASE)
#define GO_NAV  TO(_NAV)

#define OS_CTL OSM(MOD_LCTL)
#define OS_SFT OSM(MOD_LSFT)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)
#define OS_RAL OSM(MOD_RALT)

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_ortho_4x4(
       KC_T,    KC_S,    KC_R,  KC_DOT,
       KC_N,    KC_E,    KC_I,    KC_A,
     OS_CTL,  OS_ALT,  OS_GUI,    KC_O,
     KC_SPC, KC_BSPC,  GO_NUM,  GO_NAV
),

[_NUM] = LAYOUT_ortho_4x4(
     KC_7,    KC_8,    KC_9, KC_MINS,
     KC_1,    KC_2,    KC_3, KC_PENT,
     KC_4,    KC_5,    KC_6, KC_PLUS,
     KC_0,  KC_DOT, GO_HOME, KC_ASTR
),

[_NAV] = LAYOUT_ortho_4x4(
  KC_HOME,   KC_UP,  KC_END, KC_PGUP,
  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
  C(KC_V), C(KC_C), C(KC_X), C(KC_Z),
  KC_LCTL, KC_DOT, GO_HOME, KC_ASTR
),

[_FUN] = LAYOUT_ortho_4x4(
     KC_F7,   KC_F8,   KC_F9,  KC_F13,
     KC_F1,   KC_F2,   KC_F3,  KC_F11,
     KC_F4,   KC_F5,   KC_F6,  KC_F12,
    KC_F10,   RESET, GO_HOME,  KC_F14
),
};
