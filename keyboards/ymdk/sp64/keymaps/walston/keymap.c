#include QMK_KEYBOARD_H
enum layer_names {
  BASE, // default layer
  _FUN, // function layer
  _NUMPAD, // num-pad
  _MEDIA // media keys
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐    ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │  `  │  1  │  2  │  3  │  4  │  5  │  6  │    │  7  │  8  │  9  │  0  │  -  │  =  │ BkSp     │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘ ┌--┴-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │ Tab    │  Q  │  W  │  E  │  R  │  T  │    │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │ \     │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │ Ctrl    │  A  │  S  │  D  │  F  │  G  │    │  H  │  J  │  K  │  L  │  ;  │  '  │ Enter      │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │ LShift   │  Z  │  X  │  C  │  V  │  B  │    │  N  │  M  │  <  │  >  │  ?  │ Sft │ Up  │_MED │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘   ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │ _NUM │_MED │ Alt  │ Cmd         │ Spc │    │ Space         │ Cmd   │ Alt  │ Lft │ Dwn │ Rgt │
 * └------┴-----┴------┴-------------┴-----┘    └---------------┴-------┴------┴-----┴-----┴-----┘
 */
[BASE] = LAYOUT(
  MT(QK_BOOT, KC_GRAVE),   KC_1,      KC_2,    KC_3,    KC_4,    KC_5,     KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_MINUS,    KC_EQUAL,    KC_BSPACE,
  KC_TAB,                KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,      KC_LBRACKET, KC_RBRACKET,   KC_BSLS,
  KC_LCTL,               KC_A,      KC_S,    KC_D,    KC_F,    KC_G,     KC_H,     KC_J,    KC_K,    KC_L,    KC_SCOLON, KC_QUOTE,                  KC_ENTER,
  KC_LSFT,               KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,     KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,     KC_UP,     OSL(_MEDIA),
  LT(_NUMPAD, KC_CAPS), TT(_MEDIA), KC_LALT, KC_LGUI, LT(_FUN, KC_SPACE),    KC_SPACE,          KC_RGUI, KC_RALT,        KC_LEFT,   KC_DOWN,        KC_RIGHT
  ),
/* Keymap 1: Function Layer / Vim Arrows
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐    ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │ Esc │ F1  │  F2 │ F3  │ F4  │ F5  │ F6  │    │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │          │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘ ┌--┴-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │        │     │     │     │     │     │    │     │     │     │     │     │     │     │       │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │         │     │     │     │     │     │    │     │Left │ Up  │Down │Right│     │            │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │          │     │     │     │     │     │    │     │     │     │     │     │     │     │     │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘   ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │      │     │      │             │     │    │               │       │      │     │     │     │
 * └------┴-----┴------┴-------------┴-----┘    └---------------┴-------┴------┴-----┴-----┴-----┘
 */
[_FUN] = LAYOUT(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,              KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  _______,
  _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______,  _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,           KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT, _______, _______,          _______,
  _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______,  _______, _______, _______, _______,
  _______, _______, _______, _______,          _______,           _______,          _______, _______,           _______, _______, _______
  ),
/* Keymap 2: NumPad
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐    ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │     │     │     │     │     │     │     │    │  7  │  8  │  9  │     │ Vol-│ Vol+│ Mute     │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘ ┌--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │        │     │     │     │     │     │    │     │  4  │  5  │  6  │     │ |<< │ >>| │ >||   │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │         │     │     │     │     │     │    │     │  1  │  2  │  3  │     │     │            │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │          │     │     │     │     │     │    │     │  0  │     │     │     │     │     │     │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘   ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │      │     │      │             │     │    │               │       │      │     │     │     │
 * └------┴-----┴------┴-------------┴-----┘    └---------------┴-------┴------┴-----┴-----┴-----┘
 */
[_NUMPAD] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______,           KC_P7,   KC_P8,   KC_P9,   _______, KC_VOLD, KC_VOLU, KC_MUTE,
  _______, _______, _______, _______, _______, _______,           _______, KC_P4,   KC_P5,   KC_P6,   _______, KC_MPRV, KC_MNXT, KC_MPLY,
  _______, _______, _______, _______, _______, _______,           _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,          _______,
  _______, _______, _______, _______, _______, _______,           _______, KC_P0,   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,          _______,           _______,          _______, _______,          _______, _______, _______
  ),
/* Keymap 3: Media
 *
 * ┌-----┬-----┬-----┬-----┬-----┬-----┬-----┐    ┌-----┬-----┬-----┬-----┬-----┬-----┬----------┐
 * │     │     │     │     │     │     │     │    │     │     │     │     │     │     │          │
 * ├-----┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┘ ┌--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬--┴--┬-------┤
 * │        │     │     │     │     │     │    │     │     │     │     │     │     │     │       │
 * ├--------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴-------┤
 * │         │     │     │     │     │     │    │     │     │     │     │     │     │            │
 * ├---------┴┬----┴┬----┴┬----┴┬----┴┬----┴┐   └┬----┴┬----┴┬----┴┬----┴┬----┴┬----┴┬-----┬-----┤
 * │          │     │     │     │     │     │    │     │     │     │     │     │     │     │     │
 * ├------┬---┴-┬---┴--┬--┴-----┴----┬┴----┬┘   ┌┴-----┴-----┴--┬--┴----┬┴-----┼-----┼-----┼-----┤
 * │      │     │      │ Backlight   │     │    │               │       │      │     │     │     │
 * └------┴-----┴------┴-------------┴-----┘    └---------------┴-------┴------┴-----┴-----┴-----┘
 */
[_MEDIA] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,          _______,
  _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, RGB_TOG,          _______,           _______,          _______, _______,          _______, _______, _______
  ),
};
