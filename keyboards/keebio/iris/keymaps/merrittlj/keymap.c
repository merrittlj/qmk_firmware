// Copyright 2023 Lucas Merritt (merrittlj)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _DVORAK,
    _QWERTY,
    _SHIFT,
    _SYMBOL,
    _FUNCTION,
    _ADDITIONAL,
};

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  SYMBOL,
  FUNCTION,
  ADDITIONAL,
};

// Restrict symbols only to the symbol layer(disable ability to shift-num for a certain symbol).
const key_override_t zero_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_0);
const key_override_t one_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_1);
const key_override_t two_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_2);
const key_override_t three_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_3);
const key_override_t four_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_4, KC_4);
const key_override_t five_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_5);
const key_override_t six_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_6);
const key_override_t seven_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_7);
const key_override_t eight_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_8);
const key_override_t nine_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_9);

const key_override_t **key_overrides = (const key_override_t *[]){
    &zero_key_override,
    &one_key_override,
    &two_key_override,
    &three_key_override,
    &four_key_override,
    &five_key_override,
    &six_key_override,
    &seven_key_override,
    &eight_key_override,
    &nine_key_override,
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_7,    KC_5,    KC_3,    KC_1,    KC_9,                               KC_0,    KC_2,    KC_4,    KC_6,    KC_8,    KC_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_UP,   KC_LGUI, KC_RALT, KC_LCTL, KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                               KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DOWN, KC_TAB,  KC_Q,    KC_J,    KC_K,    KC_X,    MO(_ADDITIONAL),  MO(_FUNCTION),KC_B,KC_M,   KC_W,    KC_V,    KC_Z,    KC_PGDN,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    DF(_QWERTY),KC_CAPS,KC_SPC,                  MO(_SYMBOL),KC_LEFT,KC_RIGHT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MO(_ADDITIONAL),  MO(_FUNCTION),KC_N,KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    DF(_DVORAK),KC_CAPS,KC_SPC,                  MO(_SYMBOL),KC_LEFT,KC_RIGHT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
 ),

  [_SYMBOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_LABK, KC_MINUS,KC_LBRC, KC_LPRN, KC_EQUAL,                           KC_ASTR, KC_RPRN, KC_RBRC, KC_UNDS, KC_RABK, KC_CIRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_DQUO, KC_COMMA,KC_LCBR, KC_SCLN, KC_QUOT,                            KC_PLUS, KC_DOT,  KC_RCBR, KC_SLSH, KC_PIPE, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_QUES, KC_EXLM, KC_AMPR, KC_COLN, KC_HASH, XXXXXXX,          XXXXXXX, KC_PERC, KC_AT,   KC_GRAVE,KC_DLR,  KC_TILDE,XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FUNCTION] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,                              KC_F10,  KC_F2,   KC_F4,   KC_F6,   KC_F8,   XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, QK_REP,  QK_AREP, QK_LOCK, KC_BTN4, KC_BTN5,                            KC_SCRL, KC_HOME, KC_END,  QK_BOOT, KC_PWR,  XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_CAPS, KC_LEFT, KC_RIGHT,KC_WBAK, KC_WFWD,                            KC_INS,  KC_DEL,  KC_VOLU, KC_VOLD, KC_MUTE, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADDITIONAL] = LAYOUT(  // Delete the line above the commented keycodes and remove the commented keycodes if you want more RGB animations(heavier on space).
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // XXXXXXX, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X,                            RGB_M_G, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, RGB_TOG, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,                            RGB_VAI, RGB_VAD, RGB_M_P, RGB_M_B, RGB_M_T, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};
