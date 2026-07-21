// keymap.c
// Miryoku-inspired QWERTY for 3x5+3 (macOS)
// NOTE: Adapted for custom split36v2_ferris_km.
#include QMK_KEYBOARD_H
enum layers { BASE, NAV, NUM, SYM, FUN, MOUSE };

// Home row mods, QWERTY letters (GUI, ALT, CTL, SHIFT from pinky -> index)
#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LSFT_T(KC_F)
#define HM_J RSFT_T(KC_J)
#define HM_K RCTL_T(KC_K)
#define HM_L RALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)

#define NAV_SPC LT(NAV, KC_SPC)
#define NUM_ENT LT(NUM, KC_ENT)
#define SYM_TAB LT(SYM, KC_TAB)
/* #define FUN_BSP LT(FUN, KC_BSPC) */
#define FUN_DEL LT(FUN, KC_DEL)
#define MOU_ESC LT(MOUSE, KC_ESC)

enum custom_keycodes {
    MC_SPOT = SAFE_RANGE,
    MC_EMOJI,
    MC_MCTL,
    MC_SS3,
    MC_SS4,
    MC_SS5,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record){
    if(!record->event.pressed) return true;
    switch(keycode){
        case MC_SPOT: tap_code16(LGUI(KC_SPC)); return false;
        case MC_EMOJI: tap_code16(LCTL(LGUI(KC_SPC))); return false;
        case MC_MCTL: tap_code16(KC_MCTL); return false;
        case MC_SS3: tap_code16(LGUI(LSFT(KC_3))); return false;
        case MC_SS4: tap_code16(LGUI(LSFT(KC_4))); return false;
        case MC_SS5: tap_code16(LGUI(LSFT(KC_5))); return false;
    }
    return true;
}


            


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS]={
    [BASE]=LAYOUT(
            KC_Q,KC_W,KC_E,KC_R,KC_T,            KC_Y,KC_U,KC_I,KC_O,KC_P,
            HM_A,HM_S,HM_D,HM_F,KC_G,            KC_H,HM_J,HM_K,HM_L,HM_SCLN,
            KC_Z,KC_X,KC_C,KC_V,KC_B,            KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,
            MOU_ESC,NAV_SPC,KC_BSPC,             NUM_ENT,SYM_TAB,FUN_DEL),
    [NAV]=LAYOUT(
            KC_ESC,KC_HOME,KC_UP,KC_END,KC_PGUP, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
            KC_TAB,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,LGUI(KC_LEFT),LCTL(KC_LEFT),LCTL(KC_RGHT),LGUI(KC_RGHT),KC_DEL,
            KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,       LALT(KC_LEFT),LALT(KC_RGHT),KC_NO,KC_NO,KC_NO,
            _______,_______,_______,             _______,_______,_______),
    [NUM]=LAYOUT(
            KC_LBRC,KC_7,KC_8,KC_9,KC_RBRC,      KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
            KC_SCLN,KC_4,KC_5,KC_6,KC_EQL,       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
            KC_GRV,KC_1,KC_2,KC_3,KC_BSLS,       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
            _______,_______,_______,             KC_0,KC_DOT,_______),
    [SYM]=LAYOUT(
            KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC, KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,
            KC_UNDS,KC_MINS,KC_PLUS,KC_EQL,KC_PIPE,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,KC_BSLS,
            KC_TILD,KC_GRV,KC_LCBR,KC_RCBR,KC_COLN,KC_LBRC,KC_RBRC,KC_LT,KC_GT,KC_QUES,
            _______,_______,_______,             _______,_______,_______),
    [FUN]=LAYOUT(
            KC_F12,KC_F7,KC_F8,KC_F9,MC_SPOT,    KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLU,KC_BRIU,
            KC_F11,KC_F4,KC_F5,KC_F6,MC_MCTL,    KC_MUTE,KC_VOLD,MC_EMOJI,MC_SS3,KC_BRID,
            KC_F10,KC_F1,KC_F2,KC_F3,MC_SS4,     MC_SS5,KC_NO,KC_NO,KC_NO,QK_BOOT,
            _______,_______,_______,             _______,_______,_______),
    // Hold BASE's Esc (bottom-left thumb key) to reach this layer.
    // Left hand: cursor movement (cluster around home row, arrow-style)
    // Right hand: scroll wheel + mouse buttons (home row = click, outer = scroll)
    [MOUSE]=LAYOUT(
            KC_NO,KC_NO,MS_UP,KC_NO,KC_NO,             KC_NO,MS_WHLU,MS_BTN3,KC_NO,KC_NO,
            KC_NO,MS_LEFT,MS_DOWN,MS_RGHT,KC_NO,        MS_WHLL,MS_BTN1,MS_BTN2,MS_WHLR,KC_NO,
            KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,              KC_NO,MS_WHLD,KC_NO,KC_NO,KC_NO,
            _______,MS_BTN1,MS_BTN2,                   MS_ACL0,MS_ACL2,_______)
};
uint16_t get_tapping_term(uint16_t keycode,keyrecord_t *record){
    switch(keycode){
        case HM_A: case HM_S: case HM_D: case HM_F:
        case HM_J: case HM_K: case HM_L: case HM_SCLN:
            return 200;
    }
    return TAPPING_TERM;
}
bool get_permissive_hold(uint16_t keycode,keyrecord_t *record){ return false; }
bool get_hold_on_other_key_press(uint16_t keycode,keyrecord_t *record){ return false; }
