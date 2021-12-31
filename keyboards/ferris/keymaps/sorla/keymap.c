#include QMK_KEYBOARD_H
#include "keymap_uk.h"

enum ferris_layers {
    _COLEMAK,
    _NAV,
    _NUMBERS,
    _MATHS,
    _FUNCTION,
    _MOUSE,
};

// One shot mods
#define OS_SFT OSM(MOD_LSFT)
#define OS_GUI OSM(MOD_LGUI)
#define ATAB LCA(KC_TAB)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define CBSP C(KC_BSPC)
#define OS_RALT OSM(MOD_RALT)

// Layer manipulation
#define GO_HOME TO(_COLEMAK)
#define GO_NUMS TO(_NUMBERS)
#define GO_MATHS TO(_MATHS)
#define GO_NAV TO(_NAV)

#define ESC_CTL MT(MOD_LCTL,KC_ESC)
#define BSP_NAV LT(_NAV,KC_BSPC)
#define ENT_FUN LT(_FUNCTION,KC_ENT)
#define SPC_NUM LT(_NUMBERS,KC_SPC)
#define ESC_MOS LT(_MOUSE,KC_ESC)

#define TAB_ALT MT(MOD_LALT,KC_TAB)

 // macro keys
enum ferris_keycodes {
    STP_CAP = SAFE_RANGE,
    ALT_TAB,
    QTY_OFF,
};

// All the combo magic
#include "g/keymap_combo.h"

// Set up for alt-tab macro
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = LAYOUT(
	      KC_Q,    KC_W,   KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,
		  KC_A,    KC_R,   KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
		  KC_Z,    KC_X,   KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,
		                         ESC_MOS, BSP_NAV, SPC_NUM, ENT_FUN ),

	[_NAV] = LAYOUT(
	     KC_Q, KC_CAPS,  KC_APP, KC_PSCR,    KC_B, GO_HOME, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,
	   OS_GUI,  OS_ALT,  OS_SFT,  OS_CTL, OS_RALT,    KC_M, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
	  C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y),    KC_K, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,
		                          KC_ESC, KC_BSPC,  KC_SPC,  KC_ENT ),

	[_MATHS] = LAYOUT(
	      KC_Q,    KC_W,   KC_F,    KC_P,    KC_B, GO_HOME,  OS_CTL,  OS_SFT,  OS_ALT,  OS_GUI,
		  KC_8,    KC_6,   KC_2,    KC_0,    KC_G,    KC_M,    KC_3,    KC_1,    KC_7,    KC_9,
		  KC_Z,    KC_X,   KC_C,    KC_4,    KC_V,    KC_K,    KC_5, KC_COMM,  KC_DOT, KC_SLSH,
		                          KC_ESC, KC_BSPC,  KC_SPC,  KC_ENT ),

	[_NUMBERS] = LAYOUT(
	      KC_X,    KC_9,   KC_8,    KC_7, QTY_OFF, GO_HOME,    KC_L,    KC_U,    KC_Y, KC_QUOT,
	    KC_DOT,    KC_6,   KC_5,    KC_4,  KC_EQL,    KC_M,  OS_CTL,  OS_SFT,  OS_ALT,  OS_GUI,
	   KC_SLSH,    KC_3,   KC_2,    KC_1,    KC_M,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,
		                          KC_ESC,    KC_0,  KC_TAB,  KC_ENT ),

	[_MOUSE] = LAYOUT(
	     KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, GO_HOME, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
	   OS_GUI,  OS_ALT,  OS_SFT,  OS_CTL, OS_RALT, KC_MS_L, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
	  C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y),    KC_K, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,
		                          KC_ESC, KC_BSPC,  KC_SPC,  KC_ENT ),

	[_FUNCTION] = LAYOUT(
	      KC_Q,    KC_W,   KC_F,    KC_P,   RESET, GO_HOME,  OS_CTL,  OS_SFT,  OS_ALT,  OS_GUI,
		 KC_F8,   KC_F6,  KC_F2,   KC_F4,    KC_G,    KC_M,   KC_F3,   KC_F1,   KC_F7,   KC_F9,
		  KC_Z,    KC_X, KC_F12,  KC_F10,    KC_V,    KC_K,   KC_F5,  KC_F11,  KC_DOT, KC_SLSH,
		                          KC_ESC, KC_BSPC,  KC_SPC,  KC_ENT ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case ALT_TAB:
			if (record->event.pressed) {
				if (!is_alt_tab_active) {
				  is_alt_tab_active = true;
				  register_code(KC_LALT);
				}
				alt_tab_timer = timer_read();
				register_code(KC_TAB);
			} else {
				unregister_code(KC_TAB);
			}
			break;

        case STP_CAP:
			if (record->event.pressed) {
                SEND_STRING(". ");
                set_oneshot_mods(MOD_MASK_SHIFT);
            }
            break;

        case QTY_OFF:
			  if (record->event.pressed) {
                  SEND_STRING("off");
              }
              break;
    }
    return true;
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

void matrix_init_user(void) {
	eeconfig_init();
}
