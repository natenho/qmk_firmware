#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers
{
  _BASE_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
  _DEBUG_LAYER
};

const annepro2Led_t COLOR_FN1   = {.p.red = 0x00, .p.green = 0xff, .p.blue = 0x00, .p.alpha = 0xff};
const annepro2Led_t COLOR_FN2   = {.p.red = 0x00, .p.green = 0x00, .p.blue = 0xff, .p.alpha = 0xff};
const annepro2Led_t COLOR_DEBUG = {.p.red = 0x00, .p.green = 0xff, .p.blue = 0x00, .p.alpha = 0xff};
const annepro2Led_t COLOR_BLACK = {.p.red = 0x00, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};

// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  FN3  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER] = KEYMAP(/* Base */
                           KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
                           KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
                           MO(_FN1_LAYER), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
                           KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
                           KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, LT(_FN1_LAYER, KC_LEFT), LT(_FN2_LAYER, KC_DOWN), RCTL_T(KC_RGHT)),
    /*
* Layer _FN1_LAYER
* ,-----------------------------------------------------------------------------------------.
* |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |    | HOME | END |   \    |
* |-----------------------------------------------------------------------------------------+
* | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  DEBUG  | Ctrl|
* \-----------------------------------------------------------------------------------------/
*
*/
    [_FN1_LAYER] = KEYMAP(/* Base */
                          KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
                          _______, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END, _______,
                          _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,
                          _______, _______, _______, KC_CALCULATOR, _______, _______, _______, _______, _______, KC_INS, KC_DEL, _______,
                          _______, _______, _______, _______, _______, _______, TG(_DEBUG_LAYER), _______),
    /*
* Layer _FN2_LAYER
* ,-----------------------------------------------------------------------------------------.
* |     | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 |  F7 |LEDOF|LEDON| F10 | F11 | F12 |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |BREAK | HOME | END |  \   |
* |-----------------------------------------------------------------------------------------+
* | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |V-DWN|V-UP |MUTE |  v  |  b  |  n  |  m  |PREV_TRACK|NEXT_TRACK| DEL |Shift |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |     MEDIA PLAY/PAUSE            |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
*
*/
    [_FN2_LAYER] = KEYMAP(/* Base */
                          _______, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______, _______, _______, KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, _______, _______,
                          MO(_FN2_LAYER), _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, KC_PAUSE, KC_HOME, KC_END, _______,
                          _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,
                          _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, _______, _______,
                          _______, _______, _______, KC_MEDIA_PLAY_PAUSE, _______, MO(_FN1_LAYER), MO(_FN2_LAYER), _______),
    /*
* Layer _DEBUG_LAYER
* ,-----------------------------------------------------------------------------------------.
* | ESC |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  Bksp     |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |    | HOME | END |   \    |
* |-----------------------------------------------------------------------------------------+
* | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
*
*/
    [_DEBUG_LAYER] = KEYMAP(/* Base */
                            KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______,
                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, _______, _______, _______, _______, _______),
};
const uint16_t keymaps_size = sizeof(keymaps);

void matrix_init_user(void) {}
void matrix_scan_user(void) {}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void)
{
  annepro2LedEnable();

  // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
  // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
  // annepro2LedSetProfile(i);
}

layer_state_t layer_state_set_user(layer_state_t layer)
{
  switch (get_highest_layer(layer))
  {
  case _FN1_LAYER:
    annepro2LedMaskSetMono(COLOR_FN1);
    break;
  case _FN2_LAYER:
    annepro2LedMaskSetMono(COLOR_FN2);
    break;
  case _DEBUG_LAYER:
    annepro2LedMaskSetMono(COLOR_BLACK);
    annepro2LedMaskSetKey(0, 5, COLOR_DEBUG); //F5
    annepro2LedMaskSetKey(0, 9, COLOR_DEBUG); //F9
    annepro2LedMaskSetKey(0, 10, COLOR_DEBUG); //F10
    annepro2LedMaskSetKey(0, 11, COLOR_DEBUG); //F11
    annepro2LedMaskSetKey(0, 12, COLOR_DEBUG); //F12
    break;
  default:
    annepro2LedResetForegroundColor();
    break;
  }
  return layer;
}
