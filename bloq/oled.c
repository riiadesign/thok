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

#pragma once

static void render_startup(bool show_pattern) {
  // "startup" 90x32px
  static const char PROGMEM startup[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 
    0x08, 0x08, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x91, 0x91, 0x9f, 
    0x91, 0x91, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x48, 0x48, 0xc8, 
    0x48, 0x48, 0x47, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0x01, 0x00, 
    0x01, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc7, 0x49, 0x49, 0x4f, 
    0x49, 0x49, 0x47, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe3, 0x10, 0x10, 0x10, 
    0x10, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x49, 0x89, 0x89, 
    0x89, 0x89, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 
    0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x11, 0x11, 0x11, 
    0x12, 0x18, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x24, 0x24, 0x24, 
    0x24, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  // "pattern" 90x32px
  static const char PROGMEM pattern[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 
    0xfc, 0xfc, 0x7c, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 
    0x01, 0x80, 0xc0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 
    0x7f, 0x3f, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x07, 0x03, 0x01, 0x80, 
    0xc0, 0xe0, 0xf0, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfc, 0xfe, 0x7f, 0x3f, 
    0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
  
  static const char PROGMEM no_pattern[] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 
    0x20, 0x20, 0x20, 0x20, 0x20, 
    0x20, 0x20, 0x20, 0x20, 0x20, 
    0x20, 0x20, 0x20, 0x20, 0x20, 
    0x20, 0x20, 0x20, 0x20, 0x00,
  };

  oled_write_raw_P(startup, sizeof(startup));
    oled_set_cursor(0,11);
  if (show_pattern) {
    oled_write_raw_P(pattern, sizeof(pattern));
  } else {
    oled_write_P(no_pattern, false);
  }
}

// Bloq. Branding (0)
static void render_oled_bloq_brand(void) {
  // "bloq." 14x32px
  static const char PROGMEM bloq_brand[] = {
    0xfe, 0xfe, 0x66, 0x66, 0x7e, 0xfc, 0xc0, 0x00, 0xff, 0xff, 0xff, 0x00, 0xe0, 0xf0, 0x30, 0x30, 
    0x30, 0xf0, 0xe0, 0x00, 0xc0, 0xe0, 0xf0, 0x30, 0x30, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 
    0x07, 0x07, 0x06, 0x06, 0x06, 0x07, 0x03, 0x00, 0x07, 0x07, 0x07, 0x00, 0x03, 0x07, 0x06, 0x06, 
    0x06, 0x07, 0x03, 0x00, 0x01, 0x03, 0x07, 0x06, 0x06, 0x3f, 0x3f, 0x3f, 0x00, 0x02, 0x07, 0x02,
  };

  oled_write_raw_P(bloq_brand, sizeof(bloq_brand));
}

// Layer Indicator (2)
static void render_oled_layers(void) {
  static const char PROGMEM layer_1[] = {
    0x20, 0x91, 0x92, 0x93, 0x0a,
    0x20, 0xb1, 0xb2, 0xb3, 0x0a,
    0x20, 0xd1, 0xd2, 0xd3, 0x00,
  };
  static const char PROGMEM layer_2[] = {
    0x20, 0x94, 0x95, 0x96, 0x0a,
    0x20, 0xb4, 0xb5, 0xb6, 0x0a,
    0x20, 0xd4, 0xd5, 0xd6, 0x00,
  };
  static const char PROGMEM layer_3[] = {
    0x20, 0x97, 0x98, 0x99, 0x0a,
    0x20, 0xb7, 0xb8, 0xb9, 0x0a,
    0x20, 0xd7, 0xd8, 0xd9, 0x00,
  };
  static const char PROGMEM layer_4[] = {
    0x20, 0x9a, 0x9b, 0x9c, 0x0a,
    0x20, 0xba, 0xbb, 0xbc, 0x0a,
    0x20, 0xda, 0xdb, 0xdc, 0x00,
  };
  static const char PROGMEM layer_5[] = {
    0x20, 0x9d, 0x9e, 0x9f, 0x0a,
    0x20, 0xbd, 0xbe, 0xbf, 0x0a,
    0x20, 0xdd, 0xde, 0xdf, 0x00, 
  };
  static const char PROGMEM layer_other[] = {
    0x20, 0x97, 0x98, 0x99, 0x0a,
    0x20, 0xb1, 0xb2, 0xb3, 0x0a,
    0x20, 0xd1, 0xd2, 0xd3, 0x00,
  };

  oled_set_cursor(0,2);

  switch (get_highest_layer(layer_state | default_layer_state)) {
    case 1:
      oled_write_P(layer_1, false);
      break;
    case 2:
      oled_write_P(layer_2, false);
      break;
    case 3:
      oled_write_P(layer_3, false);
      break;
    case 4:
      oled_write_P(layer_4, false);
      break;
    case 5:
      oled_write_P(layer_5, false);
      break;
    default:
      oled_write_P(layer_other, false);
  }
}

// Idle Ghost (7)
static void render_oled_idle(void) {
  // Blank, to be replaced with ghost animation
  static const char PROGMEM oled_idle[] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 
    0x20, 0x20, 0x20, 0x20, 0x20, 
    0x20, 0x20, 0x20, 0x20, 0x20, 
    0x20, 0x20, 0x20, 0x20, 0x20, 
    0x20, 0x20, 0x20, 0x20, 0x00,
  };
  
  oled_set_cursor(0,7);
  oled_write_P(oled_idle, false);
}

// Layer Label (7)
static void render_oled_show_labels(void) {
  static const char PROGMEM layer_1_label[] = {
    0x20, 0x81, 0x82, 0x83, 0x20,
    0xa0, 0xa1, 0xa2, 0x20, 0xa4,
    0x80, 0x85, 0x20, 0x87, 0x84,
    0xc0, 0xa5, 0xa6, 0xa7, 0xc4,
    0x20, 0xc1, 0xc2, 0xc3, 0x00,
  };
  static const char PROGMEM layer_2_label[] = {
    0x20, 0x81, 0x82, 0x83, 0x20, 
    0xa0, 0xa1, 0xa2, 0x20, 0xa4, 
    0x80, 0x88, 0x89, 0x8a, 0x84, 
    0xc0, 0xa8, 0xa9, 0xaa, 0xc4, 
    0x20, 0xc1, 0xc2, 0xc3, 0x00,
  };
  static const char PROGMEM layer_3_label[] = {
    0x20, 0x81, 0x82, 0x83, 0x20, 
    0xa0, 0xa1, 0xa2, 0x20, 0xa4, 
    0x80, 0x8b, 0x20, 0x8d, 0x84, 
    0xc0, 0xab, 0xac, 0xad, 0xc4, 
    0x20, 0xc1, 0xc2, 0xc3, 0x00,
  };
  static const char PROGMEM layer_4_label[] = {
    0x20, 0x81, 0x82, 0x83, 0x20, 
    0xa0, 0xa1, 0xa2, 0x20, 0xa4, 
    0x80, 0x8e, 0x8f, 0x20, 0x84, 
    0xc0, 0xae, 0xaf, 0xb0, 0xc4, 
    0x20, 0xc1, 0xc2, 0xc3, 0x00,
  };
  static const char PROGMEM layer_5_label[] = {
    0x20, 0x81, 0x82, 0x83, 0x20, 
    0xa0, 0xa1, 0xa2, 0x20, 0xa4, 
    0x80, 0xc5, 0xc6, 0xc7, 0x84, 
    0xc0, 0xc8, 0xc9, 0xca, 0xc4, 
    0x20, 0xc1, 0xc2, 0xc3, 0x00,
  };

  oled_set_cursor(0,7);
  
  switch (get_highest_layer(layer_state | default_layer_state)) {
    case 1:
      oled_write_P(layer_1_label, false);
      break;
    case 2:
      oled_write_P(layer_2_label, false);
      break;
    case 3:
      oled_write_P(layer_3_label, false);
      break;
    case 4:
      oled_write_P(layer_4_label, false);
      break;
    case 5:
      oled_write_P(layer_5_label, false);
      break;
    default:
      render_oled_idle();
  }
}

// Key Indicators (13)
static void render_oled_indicator(uint16_t key_state[]) {
  static const char PROGMEM oled_indicator_bot[2][3] = {
    { 0xcb, 0xcc, 0x00, },
    { 0xa3, 0x86, 0x00, },
  };
  static const char PROGMEM oled_indicator_mid[2][2] = {
    { 0xcd, 0x00, },
    { 0x8c, 0x00, },
  };
  static const char PROGMEM oled_indicator_top[2][3] = {
    { 0xce, 0xcf, 0x00, },
    { 0x90, 0xD0, 0x00, },
  };
  
  oled_set_cursor(0,13);

  oled_write_P(oled_indicator_bot[key_state[7]], false);
  oled_write_P(oled_indicator_mid[key_state[4]], false);
  oled_write_P(oled_indicator_top[key_state[1]], false);

  oled_write_P(oled_indicator_bot[key_state[8]], false);
  oled_write_P(oled_indicator_mid[key_state[5]], false);
  oled_write_P(oled_indicator_top[key_state[2]], false);

  oled_write_P(oled_indicator_bot[key_state[9]], false);
  oled_write_P(oled_indicator_mid[key_state[6]], false);
  oled_write_P(oled_indicator_top[key_state[3]], false);
}