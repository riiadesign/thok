/* Copyright 2022 THOK
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

// Adobe Shortcuts - Windows
#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define PASTE   LCTL(KC_V)
#define PPASTE  LCTL(LSFT(KC_V))
#define REDO    LCTL(LSFT(KC_Z))
#define UNDO    LCTL(KC_Z)
#define RGB_WHI rgblight_sethsv(rgblight_get_hue(), 0, rgblight_get_val())

// Adobe Shortcuts - Mac
// #define COPY     LGUI(KC_C)
// #define CUT      LGUI(KC_X)
// #define PASTE    LGUI(KC_V)
// #define PPASTE   LGUI(LSFT(KC_V))
// #define REDO     LGUI(LSFT(KC_Z))
// #define UNDO     LGUI(KC_Z)

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [1] = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = { ENCODER_CCW_CW(LCTL(KC_PMNS), LCTL(KC_PPLS)) },
    [4] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [5] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [1] = LAYOUT(
                        TO(2),
    RGB_MOD,  _______,  _______,
    _______,  KC_UP,    _______,
    KC_LEFT,  KC_DOWN,  KC_RGHT
  ),
  [2] = LAYOUT(
                        TO(3),
    KC_MUTE,  KC_MPLY,  KC_MSTP,
    KC_VOLU,  KC_MPRV,  KC_MNXT,
    KC_VOLD,  _______,  _______
  ),
  [3] = LAYOUT(
                        TO(4),
    UNDO,     REDO,     KC_DEL,
    COPY,     CUT,      PASTE,
    PPASTE,   KC_SPC,   _______
  ),
  [4] = LAYOUT(
                        TO(5),
    RGB_M_B,  RGB_WHI,  _______,
    _______,  _______,  _______,
    _______,  _______,  _______
  ),
  [5] = LAYOUT(
                        TO(1),
    _______,  _______,  _______,
    _______,  _______,  _______,
    _______,  _______,  _______
  ),
  [RESET] = LAYOUT (
                        RESET,
    _______,  _______,  _______,
    _______,  _______,  _______,
    _______,  _______,  _______
  ),
};