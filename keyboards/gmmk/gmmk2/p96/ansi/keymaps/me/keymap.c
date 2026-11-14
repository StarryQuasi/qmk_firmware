/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
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
#include "secure.h"
#include "lib/lib8tion/lib8tion.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
enum custom_layers {
  _BL,
  _FL,
};

enum custom_keycodes {
  MY_TOGGUI = SAFE_RANGE, // Toggle Win
  MY_WINV,                // Presses Win + V
  MY_WINSPC,              // Presses Win + Space
  MY_TGPPLS,              // Toggle numpad plus or right click
  MY_TGBRK,               // Toggle insert or break
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
[_BL] = LAYOUT(
  // ESC    F1        F2        F3        F4        F5        F6        F7        F8        F9        F10       F11       F12       Prt                           Del       Ins       PgUp      PgDn
  QK_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,                       KC_HOME,  KC_END,   KC_INS,   KC_PSCR,
  // `      1         2         3         4         5         6         7         8         9         0         -         =         BSpc                          Num       /         *         -
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,                      KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
  // Tab    Q         W         E         R         T         Y         U         I         O         P         [         ]         \                             7         8         9         +
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,                      KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
  // Caps   A         S         D         F         G         H         J         K         L         ;         '                   Enter                         4         5         6
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,                       KC_P4,    KC_P5,    KC_P6,
  // Sh_L   Z         X         C         V         B         N         M         ,         .         /                   Sh_R                Up                  1         2         3         Enter
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,    KC_PENT,
  // Ct_L   Win_L     Alt_L                         SPACE                                   Alt_R     FN        Ct_R                Left      Down      Right               0         .
  KC_LCTL,  MO(_FL),  KC_LALT,                      KC_SPC,                                 KC_RALT,  KC_LGUI,  KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT,            KC_P0,    KC_PDOT),

  /* Keymap _FL: Function Layer
   */
[_FL] = LAYOUT(
  // ESC    F1        F2        F3        F4        F5        F6        F7        F8        F9        F10       F11       F12       Prt                           Del       Ins       PgUp      PgDn
  QK_BOOT,  KC_CALC,  _______,  _______,  _______,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_MPLY,  _______,  _______,  _______,  _______,  SE_LOCK,                      KC_PGUP,  KC_PGDN,  MY_TGBRK, KC_SCRL,
  // `      1         2         3         4         5         6         7         8         9         0         -         =         BSpc                          Num       /         *         -
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,
  // Tab    Q         W         E         R         T         Y         U         I         O         P         [         ]         \                             7         8         9         +
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RM_VALU,  _______,  _______,  _______,  _______,  _______,                      KC_HOME,  KC_UP,    KC_PGUP,  MY_TGPPLS,
  // Caps   A         S         D         F         G         H         J         K         L         ;         '                   Enter                         4         5         6
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RM_PREV,  RM_VALD,  RM_NEXT,  _______,  _______,            _______,                      KC_LEFT,  _______,  KC_RGHT,
  // Sh_L   Z         X         C         V         B         N         M         ,         .         /                   Sh_R                Up                  1         2         3         Enter
  _______,  RM_SPDD,  RM_SPDU,  _______,  MY_WINV,  _______,  _______,  _______,  RM_HUED,  RM_HUEU,  _______,            _______,            KC_PGUP,            KC_END,   KC_DOWN,  KC_PGDN,  _______,
  // Ct_L   Win_L     Alt_L                         SPACE                                   Alt_R     FN        Ct_R                Left      Down      Right               0         .
  _______,  _______,  _______,                      MY_WINSPC,                              _______,  MY_TOGGUI,_______,            KC_HOME,  KC_PGDN,  KC_END,             KC_INS,   KC_DEL)
};


static const uint8_t num_keys[] = {
  50, 51, 52, // 789
  67, 68, 69, // 456
  83, 84, 85, // 123
      97, 98  //  0.
};
static bool enable_win_key = true;
static bool enable_num_plus_to_right_click = false;
static bool enable_ins_to_break = false;
static uint32_t secure_light_start_time = 0;

void set_hsv(uint8_t i, uint8_t h, uint8_t s, uint8_t v) {
  RGB rgb = hsv_to_rgb((HSV){h, s, v});
  rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
}

bool secure_hook_user(secure_status_t secure_status) {
  secure_light_start_time = timer_read32();
  return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  uint8_t brightness = rgb_matrix_get_val();
  uint8_t light_brightness = qadd8(brightness, 100);
  led_t led_state = host_keyboard_led_state();

  const uint8_t hue_red = 0;
  const uint8_t hue_green = 85;

  if (led_state.caps_lock)
    set_hsv(38, hue_red, 255, light_brightness); // W

  if (led_state.scroll_lock)
    set_hsv(17, hue_red, 255, light_brightness); // Pgdn, now Pscr

  if (!led_state.num_lock)
    for (uint8_t i = 0; i < ARRAY_SIZE(num_keys); i++)
      set_hsv(num_keys[i], hue_red, 255, light_brightness); // All nums and dot

  if (!enable_win_key)
    set_hsv(92, hue_red, 255, light_brightness); // Win

  if (enable_num_plus_to_right_click)
    set_hsv(53, hue_red, 255, light_brightness); // Num plus

  if (enable_ins_to_break)
    set_hsv(16, hue_red, 255, 255); // Pgup, now Ins
  
  if (secure_is_locked())
    set_hsv(13, hue_red, 255, 255); // Pcsr, now Del

  if (secure_light_start_time) {
    uint32_t elapsed = timer_elapsed32(secure_light_start_time);
    if (elapsed >= 1024 && !secure_is_unlocking())
      elapsed = 0;
    else {
      RGB rgb = {};
      switch (secure_get_status()) {
      case SECURE_PENDING:
        rgb = hsv_to_rgb((HSV){hue_red, 255, light_brightness});
        break;
      case SECURE_LOCKED:
        rgb = hsv_to_rgb((HSV){hue_red, 255, blend8(light_brightness, 0, elapsed / 4)});
        break;
      case SECURE_UNLOCKED:
        rgb = hsv_to_rgb((HSV){hue_green, 255, blend8(light_brightness, 0, elapsed / 4)});
        break;
      }
      for (uint8_t i = 0; i <= 17; i++)
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
      for (uint8_t i = 87; i <= 98; i++)
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
      uint8_t a[] = {18, 36, 54, 70, 35, 53, 86};
      for (uint8_t i = 0; i < ARRAY_SIZE(a); i++)
        rgb_matrix_set_color(a[i], rgb.r, rgb.g, rgb.b);
    }
  }

  return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (secure_is_locked() && keycode == SE_LOCK && record->event.pressed) {
    secure_request_unlock();
    return false;
  }

  if (secure_is_unlocking())
    return true;

  if (secure_is_locked() && keycode != MO(_FL))
    return false;

  switch (keycode) {
  case MY_TOGGUI:
    if (record->event.pressed)
      enable_win_key = !enable_win_key;
    return false;
  
  case KC_LGUI:
    return enable_win_key;
  
	case MY_TGBRK:
    if (record->event.pressed)
      enable_ins_to_break = !enable_ins_to_break;
	  return false;
  
  case KC_INS:
    if (enable_ins_to_break) {
      if (record->event.pressed)
        register_code16(KC_BRK);
      else
        unregister_code16(KC_BRK);
      return false;
    }
    return true;
  
  case MY_WINV:
    if (record->event.pressed) {
      register_code16(KC_LGUI);
      register_code16(KC_V);
    } else {
      unregister_code16(KC_V);
      unregister_code16(KC_LGUI);
    }
    return false;
  
  case MY_WINSPC:
    if (record->event.pressed) {
      register_code16(KC_LGUI);
      register_code16(KC_SPC);
    } else {
      unregister_code16(KC_SPC);
      unregister_code16(KC_LGUI);
    }
    return false;
  
  case MY_TGPPLS:
    if (record->event.pressed)
      enable_num_plus_to_right_click = !enable_num_plus_to_right_click;
    return false;
  
  case KC_PPLS:
    if (enable_num_plus_to_right_click) {
      if (record->event.pressed)
        register_code16(MS_RGHT);
      else
        unregister_code16(MS_RGHT);
      return false;
    }
    return true;

  default:
    return true; // Continue processing
  }
}