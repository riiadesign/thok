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

#include "bloq.h"
#include "oled.c"

#define LABEL_TIMEOUT 2000
#define STARTUP_TIMEOUT 10000

uint16_t startup_timer;
bool startup = true;

uint16_t key_pressed, key_pos, key_state[10]; 

uint16_t layer_timer;
bool show_label = false;

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { NO_LED, NO_LED, NO_LED },
  { 0, 3, 6 },
  { 1, 4, 7 },
  { 2, 5, 8 }
}, {
  // LED Index to Physical Position
  { 0,  0 }, { 112,  0 }, { 224,  0 },
  { 0, 32 }, { 112, 32 }, { 224, 32 },
  { 0, 64 }, { 112, 64 }, { 224, 64 }
}, {
  // LED Index to Flag
  4, 4, 4,
  4, 4, 4,
  4, 4, 4
} };
#endif

void keyboard_post_init_user(void) {
  // Start startup timer
  startup_timer = timer_read();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // To stay consistent with layer naming, the first layer starts at 1. This sets the default layer.
  set_single_persistent_default_layer(1);

  // Convert key row, column and whether pressed into an array
  key_pressed = record->event.pressed;
  key_pos = record->event.key.col;
  if (record->event.key.row != 0) { key_pos += record->event.key.row * 3 - 2; }

  key_state[key_pos] = key_pressed;
    
  // Layer change label timer
  if (key_state[0] == 1) {
    layer_timer = timer_read();
    show_label = true;
  }

  return true;
}

// OLED
#ifdef OLED_ENABLE

// OLED Rotations
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_90;
}

static void render_status(void) {
  // Left Section
  render_oled_bloq_brand();
  render_oled_layers();

  // Mid Section
  if (show_label == true && timer_elapsed(layer_timer) < LABEL_TIMEOUT) {
    render_oled_show_labels();
  } else {
    render_oled_idle();
    show_label = false;
  }

  // Right Section
  render_oled_indicator(key_state);
}

bool oled_task_user(void) {
  // Startup timer ends
  if (startup && timer_elapsed(startup_timer) > STARTUP_TIMEOUT) {
    startup = false;
    oled_clear();
  }

  if (startup) {
    // If the number of seconds on the timer is odd, show pattern
    render_startup((((timer_elapsed(startup_timer) / 1000) % 2) != 1));
  } else {
    render_status();
  }
  return false;
}

#endif
