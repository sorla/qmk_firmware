#include QMK_KEYBOARD_H
#include "keymap_uk.h"

/* #define A_GUI GUI_T(KC_A)
#define R_ALTT ALT_T(KC_R)
#define S_SFT SFT_T(KC_S)
#define T_CTRL CTL_T(KC_T)
#define N_CTRL CTL_T(KC_N)
#define E_SFT SFT_T(KC_E)
#define I_ALT ALT_T(KC_I)
#define O_GUI GUI_T(KC_O) */

#define GO_HOME TO(_COLEMAK)
#define GO_NUMS TO(_NUMBERS)
#define GO_NAV TO(_NAV)
#define ESC_CTL MT(MOD_LCTL,KC_ESC)
#define BSP_NUM LT(_NUMBERS,KC_BSPC)
#define DEL_FUN LT(_FUNCTION,KC_DEL)
#define SPC_NAV LT(_NAV,KC_SPC)
#define ENT_MOS LT(_MOUSE,KC_ENT)
#define TAB_ALT MT(MOD_LALT,KC_TAB)

#define OS_CTL OSM(MOD_LCTL)
#define OS_SFT OSM(MOD_LSFT)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)
#define OS_RAL OSM(MOD_RALT)

// Keys for FrogPad layout
#define BS_NUM LT(_FNUM,KC_BSPC)
#define SP_EX LT(_FEXT, KC_SPC)
#define OSYM OSL(_FSYM)
#define ONUM OSL(_FNUM)
#define OSFT OSM(MOD_LSFT)
#define OGUI OSM(MOD_LGUI)
#define ATAB LCA(KC_TAB)
#define OALT OSM(MOD_LALT)
#define OCTL OSM(MOD_LCTL)
#define CBSP C(KC_BSPC)

// Shortcuts for Teams
#define TM_QUIT C(S(KC_B))
#define TM_MUTE C(S(KC_M))
#define TM_HAND C(S(KC_K))
// Set up for alt-tab macro
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

 enum plaid_layers {
	 _COLEMAK,
	 _QWERTY,
	 _NAV,
	 _NUMBERS,
	 _FUNCTION,
	 _MOUSE,
     _FROG,
     _FSYM,
     _FNUM,
     _FFUN,
     _FEXT,
 };

 // macro keys
 enum plaid_keycodes {
	 COLEMAK = SAFE_RANGE,
	 QWERTY,
	 NAV,
	 NUMBERS,
	 SYMS,
	 FUNCTION,
	 MOUSE,
	 ADJUST,
	 ALT_TAB,
     STP_CAP,
     ENT_CAP,
     QUES_CAP,
     EXCL_CAP,
};
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = LAYOUT_plaid_grid(
	      KC_Q,    KC_W,   KC_F,    KC_P,    KC_B, STP_CAP, TM_QUIT,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,
		  KC_A,    KC_R,   KC_S,    KC_T,    KC_G,  KC_EQL, TM_MUTE,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
		  KC_Z,    KC_X,   KC_C,    KC_D,    KC_V, _______, TM_HAND,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,
		OS_CTL, KC_LGUI, KC_EQL, DEL_FUN, BSP_NUM, ESC_CTL, TAB_ALT, SPC_NAV, ENT_MOS,  GO_NAV, GO_NUMS, UK_HASH),

	[_QWERTY] = LAYOUT_plaid_grid(
		 KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
         KC_ESC,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
		KC_LSFT, LT(_FUNCTION,KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
		KC_LCTL,    KC_RALT, KC_LALT, KC_LGUI, DEL_FUN, BSP_NUM, SPC_NAV, ENT_MOS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT
        ),

	[_NAV] = LAYOUT_plaid_grid(
		  KC_F2, KC_HOME,   KC_UP,  KC_END, KC_PGUP, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,
		C(KC_S), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, KC_PSCR,  OS_CTL,  OS_SFT,  OS_ALT,  OS_GUI,
		C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y), _______, _______, KC_CAPS,  KC_APP, _______,  OS_RAL, _______,
		_______, _______, _______, _______, _______, ALT_TAB, _______, _______, _______, _______, GO_HOME, _______
        ),

	[_NUMBERS] = LAYOUT_plaid_grid(
		_______, _______, _______, _______, _______, _______, _______, _______,   KC_7,    KC_8,    KC_9, KC_COLN,
		 OS_GUI,  OS_ALT,  OS_SFT,  OS_CTL, _______, _______, _______,  KC_EQL,   KC_1,    KC_2,    KC_3,  KC_DOT,
		_______,  OS_RAL, _______, _______, _______, _______, _______, KC_PLUS,   KC_4,    KC_5,    KC_6, _______,
		_______, _______, _______, _______, _______, _______,  KC_TAB,    KC_0, KC_ENT, _______, GO_HOME, KC_BSPC
        ),

	[_FUNCTION] = LAYOUT_plaid_grid(
		    _______,      DM_RSTP,   DM_PLY1, DM_PLY2, DM_REC1,   RESET, _______,  KC_F14,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
		     OS_GUI,       OS_ALT,    OS_SFT,  OS_CTL, DM_REC2, _______, _______,  KC_F13,   KC_F1,   KC_F2,   KC_F3,  KC_F12,
		DF(_QWERTY), DF(_COLEMAK), TO(_FROG), _______, _______, _______, _______,  KC_F15,   KC_F4,   KC_F5,   KC_F6,  KC_F11,
		    _______,      _______,   _______, _______, _______, _______, _______, _______, _______, _______, GO_HOME, _______
        ),

	[_MOUSE] = LAYOUT_plaid_grid(
		_______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______, _______,   KC_NO, KC_ACL0, KC_ACL2, KC_BTN3, KC_BTN5,
		_______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, KC_BTN4, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI,
		_______,   KC_NO,  	KC_NO,   KC_NO,   KC_NO, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______, _______, _______, GO_HOME, _______
        ),

    [_FROG] = LAYOUT_plaid_grid( // possibly more combos on the home row for letters and layer switching
         KC_ESC,    KC_F,    KC_D,    KC_N,    KC_I,    KC_G,    KC_G,    KC_I,    KC_N,    KC_D,    KC_F,  KC_ESC,
         KC_TAB,    KC_S,    KC_T,    KC_H,    KC_E,    KC_O,    KC_O,    KC_E,    KC_H,    KC_T,    KC_S,  KC_TAB,
         OS_CTL,    KC_C,    KC_W,    KC_R,    KC_A,    KC_U,    KC_U,    KC_A,    KC_R,    KC_W,    KC_C,  OS_CTL,
        _______, _______, _______,    OSYM,  BS_NUM,   SP_EX,   SP_EX,  BS_NUM,    OSYM, _______, GO_HOME, _______
        ),

    [_FSYM] = LAYOUT_plaid_grid( // check with nums and alpha layers for coverage
       KC_TAB, KC_LBRC, KC_LCBR, KC_LPRN,   KC_AT, KC_CIRC, KC_CIRC,   KC_AT, KC_LPRN, KC_LCBR, KC_LBRC,  KC_TAB,
      KC_BSLS, KC_COLN, KC_SCLN, KC_QUES, KC_EXLM, KC_SLSH, KC_SLSH, KC_EXLM, KC_QUES, KC_SCLN, KC_COLN, KC_BSLS,
      KC_TILD, KC_RBRC, KC_RCBR, KC_RPRN, KC_AMPR, KC_ASTR, KC_ASTR, KC_AMPR, KC_RPRN, KC_RCBR, KC_RBRC, KC_TILD,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_FNUM] = LAYOUT_plaid_grid(  // Re-arrange to numpad with 1-3 on home row
       KC_EQL,    KC_8,    KC_9,    KC_8,    KC_7,  KC_DOT,  KC_DOT,    KC_5,    KC_6,    KC_7,    KC_8,  KC_EQL,
       KC_EQL,  KC_DOT,    KC_3,    KC_2,    KC_1,    KC_0,    KC_5,    KC_1,    KC_2,    KC_3,    KC_4,  KC_EQL,
      KC_MINS, KC_SLSH,    KC_6,    KC_5,    KC_4, KC_COMM, KC_COMM,    KC_9,    KC_0, KC_HASH, KC_SLSH, KC_MINS,
      _______, _______, _______, XXXXXXX, _______,    OGUI,    OGUI, XXXXXXX, XXXXXXX,_______, _______, _______
      ),
// TODO add in a function layer
    [_FEXT] = LAYOUT_plaid_grid(// make this match the main layers layout of the arrows at least
      XXXXXXX, KC_WBAK, KC_HOME,   KC_UP,  KC_END, KC_WFWD, KC_WFWD, KC_HOME,   KC_UP,  KC_END, KC_WBAK, XXXXXXX,
      XXXXXXX,    ATAB, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,  KC_DEL, KC_LEFT, KC_DOWN, KC_RGHT,    ATAB, XXXXXXX,
      XXXXXXX, C(KC_Z), C(KC_X), C(KC_C), C(KC_V),    OALT,    OALT, C(KC_V), C(KC_C), C(KC_X), C(KC_Z), XXXXXXX,
      _______, _______, _______,    OSFT,    OCTL,    CBSP,    CBSP,    OCTL,    OSFT, _______, _______, _______
    )
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

        case ENT_CAP:
			  if (record->event.pressed) {
                  SEND_STRING(".\n");
                  set_oneshot_mods(MOD_MASK_SHIFT);
              }
              break;

        case QUES_CAP:
			  if (record->event.pressed) {
                  SEND_STRING("? ");
                  set_oneshot_mods(MOD_MASK_SHIFT);
              }
              break;

        case EXCL_CAP:
			  if (record->event.pressed) {
                  SEND_STRING("! ");
                  set_oneshot_mods(MOD_MASK_SHIFT);
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

    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _NUMBERS:
            writePinHigh(LED_RED);
			writePinLow(LED_GREEN);
            break;
        case _FROG:
        case _FSYM:
        case _FNUM:
        case _FEXT:
            writePinHigh(LED_GREEN);
			writePinLow(LED_RED);
            break;
		case _FUNCTION:
			writePinHigh(LED_GREEN);
			writePinHigh(LED_RED);
			break;
		default:
            writePinLow(LED_GREEN);
            writePinLow(LED_RED);
    }
}

void matrix_init_user(void) {
	eeconfig_init();
}
