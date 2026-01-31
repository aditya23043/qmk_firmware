// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │GUI├───┐           ┌───┤Alt│
      *           └───┤Bsp├───┐   ┌───┤Ent├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */
    [0] = LAYOUT_split_3x5_3(
        KC_Q,           KC_W,    KC_E,              KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,           KC_S,    KC_D,              KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        LSFT_T(KC_Z),   KC_X,    KC_C,              KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  LSFT_T(KC_SLSH),
                                 LGUI_T(KC_ESC),    KC_BSPC, LT(1, KC_TAB),           KC_ENT,  KC_SPC,  KC_RALT
    ),
    [1] = LAYOUT_split_3x5_3(
        KC_TRNS,        KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_UP  , KC_TRNS, KC_TRNS,
        KC_TRNS,        KC_LCTL, KC_LOPT,           KC_LCMD, KC_TRNS,          KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,
        KC_TRNS,        KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                 KC_TRNS,           KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS                   
    )
	/* [0] = LAYOUT_split_3x5_3( */
	/* 	KC_Q, 		KC_W, 		KC_F,		KC_P,		KC_B,				KC_J,		KC_L,		KC_U,		KC_Y,		KC_SCLN, */
	/* 	KC_A,		KC_R,		KC_S,		KC_T,		KC_G,				KC_M,		KC_N,		KC_E,		KC_I,		KC_O, */
        /* MT(KC_LOPT, KC_Z),		KC_X,		KC_C,		KC_D,		        KC_V,		KC_K,		KC_H,		KC_COMM,	KC_DOT,		MT(KC_LSFT, KC_SLSH), */
	/* 					MT(KC_RSFT, KC_ESC),		MT(KC_ROPT, KC_DEL),	MT(KC_RCTL, KC_TAB),		KC_ENT,		KC_SPC,		LT(1, KC_BSPC) */

    /* ), */
	/* [1] = LAYOUT_split_3x5_3( */
	/*     KC_EXLM, 	KC_AT, 		KC_HASH, 	KC_DLR,  	KC_PERC, 			KC_CIRC, 	KC_AMPR, 	KC_ASTR, 	KC_CAPS, 	KC_BSPC, */
	/* 	KC_1,    	KC_2, 	 	KC_3,    	KC_4,    	KC_5,    			KC_6,    	KC_7,    	KC_8,    	KC_9,    	KC_0, */
	/* 	KC_TRNS, 	KC_NO, 		KC_NO,   	KC_NO,   	MO(3),   			KC_NO,   	KC_NO,   	KC_COMM, 	KC_DOT,  	KC_TRNS, */
                                /* KC_TRNS, 	KC_TRNS, 	KC_TRNS, 			KC_TRNS, 	KC_TRNS,	KC_TRNS */
	/* ) */
};

