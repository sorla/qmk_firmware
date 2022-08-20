/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define ___x___ KC_NO

enum custom_keycodes {
    SAFE = PLOOPY_SAFE_RANGE, // avoid other things?  There's a smarter way to do this
    CUT,
    COPY,
    PASTE,
};
// safe range starts at `PLOOPY_SAFE_RANGE` instead.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_BTN1, KC_BTN3, KC_BTN2,
          KC_LCTL, LT(1, KC_SPC)
    ),

    [1] = LAYOUT( /* Edit */
        PASTE, CUT, COPY,
          DPI_CONFIG, _______
    ),

    [2] = LAYOUT( /* Base */
        KC_BTN1, KC_BTN3, KC_BTN2,
          KC_BTN4, KC_BTN5
    ),

    [3] = LAYOUT( /* Base */
        KC_BTN1, KC_BTN3, KC_BTN2,
          KC_BTN4, KC_BTN5
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CUT:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTRL("x"));
      }
      return false;
      break;
    case COPY:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTRL("c"));
      }
      return false;
      break;
    case PASTE:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTRL("v"));
      }
      return false;
      break;
  }
  return true;
}
