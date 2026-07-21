// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    _BASE,
    _RIGHT,
    _LEFT,
    _TRI
};

// Home row mod tap definitions
#define HRM_A MT(MOD_LSFT, KC_A)
#define HRM_S MT(MOD_LALT, KC_S)
#define HRM_D MT(MOD_LCTL, KC_D)
#define HRM_F MT(MOD_LGUI, KC_F)

#define HRM_J MT(MOD_RGUI, KC_J)
#define HRM_K MT(MOD_RCTL, KC_K)
#define HRM_L MT(MOD_RALT, KC_L)
#define HRM_QUOT MT(MOD_RSFT, KC_QUOT)

// Layer tap definitions
#define TAB_LT LT(_LEFT, KC_TAB)
#define ENT_RT LT(_RIGHT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
    //╭──────────┬──────────┬──────────┬──────────┬──────────╮
    //│  Q       │  W       │  E       │  R       │  T       │
        KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,     
    //├──────────┼──────────┼──────────┼──────────┼──────────┤
    //│  A       │  S       │  D       │  F       │  G       │
        HRM_A,     HRM_S,     HRM_D,     HRM_F,     KC_G,     
    //├──────────┼──────────┼──────────┼──────────┼──────────┤
    //│  Z       │  X       │  C       │  V       │  B       │
        KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,     
    //╰──────────┴──────────┼──────────┼──────────┼──────────┤
                              KC_ESC,    TAB_LT,    KC_BSPC  
    //                      ╰──────────┴──────────┴──────────╯
    ),
};
