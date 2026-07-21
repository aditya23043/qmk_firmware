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
    //╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
    //│  Q       │  W       │  E       │  R       │  T       │   │  Y       │  U       │  I       │  O       │  P       │
        KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,          KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,
    //├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    //│  A       │  S       │  D       │  F       │  G       │   │  H       │  J       │  K       │  L       │ ' "      │
        HRM_A,     HRM_S,     HRM_D,     HRM_F,     KC_G,          KC_H,      HRM_J,     HRM_K,     HRM_L,     HRM_QUOT,
    //├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    //│  Z       │  X       │  C       │  V       │  B       │   │  N       │  M       │ , <      │ . >      │ / ?      │
        KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,          KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,
    //╰──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
                              KC_ESC,    TAB_LT,    KC_BSPC,       KC_SPC,    ENT_RT,    KC_DEL
    //                      ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
    ),

    [_RIGHT] = LAYOUT(
    //╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
    //│ INSERT   │  1       │  2       │  3       │          │   │ HOME     │ PAGE DN  │ PAGE UP  │ END      │  :       │
        KC_INS,    KC_1,      KC_2,      KC_3,      KC_TRNS,       KC_HOME,   KC_PGDN,   KC_PGUP,   KC_END,    KC_COLN,
    //├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    //│ DELETE   │  4       │  5       │  6       │          │   │ LEFT     │ DOWN     │ UP       │ RIGHT    │  ;       │
        KC_DEL,    KC_4,      KC_5,      KC_6,      KC_TRNS,       KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   KC_SCLN,
    //├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    //│ CAPS     │  7       │  8       │  9       │  0       │   │          │          │          │          │          │
        CW_TOGG,   KC_7,      KC_8,      KC_9,      KC_0,          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
    //╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
                              KC_TRNS,   KC_TRNS,   KC_ESC,        KC_TRNS,   KC_TRNS,   KC_TRNS
    //                      ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
    ),

    [_LEFT] = LAYOUT(
    //╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
    //│          │  [       │  {       │  }       │          │   │  ^       │  (       │  )       │  ]       │  ~       │
        KC_TRNS,   KC_LBRC,   KC_LCBR,   KC_RCBR,   KC_TRNS,       KC_CIRC,   KC_LPRN,   KC_RPRN,   KC_RBRC,   KC_TILD,
    //├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    //│  !       │  @       │  #       │  $       │  %       │   │  *       │  -       │  =       │  \       │  `       │
        KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,       KC_ASTR,   KC_MINS,   KC_EQL,    KC_BSLS,   KC_GRV,
    //├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    //│          │          │          │          │          │   │  &       │  _       │  +       │  │       │          │
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_AMPR,   KC_UNDS,   KC_PLUS,   KC_PIPE,   KC_TRNS,
    //╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
                              KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS
    //                      ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
    ),

    [_TRI] = LAYOUT(
    //╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
    //│ RESET    │          │ MS UP    │          │ WHEEL UP │   │ WHEEL UP │          │ MS UP    │          │  RESET   │
        QK_RBT,    KC_NO,     MS_UP  ,   KC_NO,     MS_WHLU,       MS_WHLU,   KC_NO,     MS_UP  ,   KC_NO,     QK_RBT,
    //├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    //│BOOTLOADER│ MS LEFT  │ MS DOWN  │ MS RIGHT │ WHEEL DN │   │ WHEEL DN │ MS LEFT  │ MS DOWN  │ MS RIGHT │BOOTLOADER│
        QK_BOOT,   MS_LEFT,   MS_DOWN,   MS_RGHT,   MS_WHLD,       MS_WHLD,   MS_LEFT,   MS_DOWN,   MS_RGHT,   QK_BOOT,
    //├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    //│          │          │          │          │ WHEEL L  │   │ WHEEL R  │          │          │          │          │
        KC_NO,     KC_NO,     KC_NO,     MS_WHLL,   MS_WHLR,       MS_WHLL,   MS_WHLR,   MS_ACL0,   MS_ACL1,   MS_ACL2,
    //╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
                              MS_BTN2,   MS_BTN3,   MS_BTN1,       MS_BTN1,   MS_BTN3,   MS_BTN2
    //                      ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
    //                        Right Clk  Mid Clk   Left Clk      Left Clk   Mid Clk   Right Clk
    )
};

// Tri-layer: when both _RIGHT and _LEFT are active, activate _TRI
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _RIGHT, _LEFT, _TRI);
}

// Home row mods configuration
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_A:
        case HRM_S:
        case HRM_D:
        case HRM_F:
        case HRM_J:
        case HRM_K:
        case HRM_L:
        case HRM_QUOT:
            return 220;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_A:
        case HRM_S:
        case HRM_D:
        case HRM_F:
        case HRM_J:
        case HRM_K:
        case HRM_L:
        case HRM_QUOT:
            return false;  // tap-preferred behavior
        default:
            return true;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_A:
        case HRM_S:
        case HRM_D:
        case HRM_F:
        case HRM_J:
        case HRM_K:
        case HRM_L:
        case HRM_QUOT:
            return false;
        default:
            return false;
    }
}
