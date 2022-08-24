#include QMK_KEYBOARD_H
#include "keymap_uk.h"
#include "keymap_steno.h"
#include "custom_keys.h"

enum ferris_layers {
    _BASE,
    _NAV,
    _NUMBERS,
    _FUNCTION,
    _SYMS,
};


 // macro keys
enum ferris_keycodes {
    STP_CAP = SAFE_RANGE,
    ALT_TAB,
    QTY_OFF,
};

// Set up for alt-tab macro
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

// All the combo magic
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = SH_LAYOUT(
	      KC_B,    KC_R,   KC_A,    KC_N, GO_NUMS,
		  KC_O,    KC_I,   KC_E,    KC_T,  KC_ENT,
		  KC_Z,    KC_W,   KC_C,    KC_F,  GO_NAV,
		                         BSP_ALT, SPC_CTL),

    [_NAV] = LAYOUT(
	  KC_HOME, KC_PGDN, KC_PGUP,  KC_END, GO_NUMS, GO_NUMS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,
	  KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, GO_HOME, GO_HOME, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
	  KC_CAPS, KC_VOLD, KC_VOLU, KC_MUTE,  KC_APP,  KC_APP, KC_MUTE, KC_VOLD, KC_VOLU, KC_CAPS,
		                         _______, _______, _______, _______ ),

	[_NUMBERS] = SH_LAYOUT(
	      KC_X,    KC_6,   KC_5,    KC_4, GO_NUMS,
		  KC_3,    KC_2,   KC_1,    KC_0, GO_HOME,
	   KC_SLSH,    KC_9,   KC_8,    KC_7,  GO_NAV,
		                         _______, _______),


	[_FUNCTION] = SH_LAYOUT(
	    KC_F12,  KC_F11,  KC_F10,  KC_F9, GO_NUMS,
		 KC_F4,   KC_F3,   KC_F2,  KC_F1, GO_HOME,
	     KC_F8,   KC_F7,   KC_F6,  KC_F5,  GO_NAV,
		                         _______, _______),


	[_SYMS] = SH_LAYOUT(
	    KC_GRV,   KC_LT, KC_LBRC, KC_LPRN, GO_NUMS,
	   UK_HASH, KC_SLSH, KC_MINS,  KC_EQL, GO_HOME,
	   KC_BSLS,   KC_GT, KC_RBRC, KC_RPRN,  GO_NAV,
		                         _______, _______),
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
