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

// Adobe Shortcuts - Mac
// #define COPY    LGUI(KC_C)
// #define CUT     LGUI(KC_X)
// #define PASTE   LGUI(KC_V)
// #define PPASTE  LGUI(LSFT(KC_V))
// #define REDO    LGUI(LSFT(KC_Z))
// #define UNDO    LGUI(KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_v1(
                            TO(1),
        RGB_MOD,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_UP,    KC_TRNS,
        KC_LEFT,  KC_DOWN,  KC_RGHT
    ),
    [1] = LAYOUT_v1(
                            TO(2),
        KC_MUTE,  KC_MPLY,  KC_MSTP,
        KC_VOLU,  KC_MPRV,  KC_MNXT,
        KC_VOLD,  KC_TRNS,  KC_TRNS
    ),
    [2] = LAYOUT_v1(
                            TO(3),
        UNDO,     REDO,     KC_DEL,
        COPY,     CUT,      PASTE,
        PPASTE,   KC_SPC,   KC_TRNS
    ),
    [3] = LAYOUT_v1(
                            TO(4),
        KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [4] = LAYOUT_v1(
                            TO(0),
        KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS
    )
};
