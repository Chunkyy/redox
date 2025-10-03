/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
   _COLEMAK_Mac,
   _COLEMAK_Win,
   _SYMB,
   _NAV,
   _ADJUST
};

const rgblight_segment_t PROGMEM colemakColour[] = RGBLIGHT_LAYER_SEGMENTS(
      {0, 5, HSV_GREEN}
);
const rgblight_segment_t PROGMEM symbolColour[] = RGBLIGHT_LAYER_SEGMENTS(
      {0, 5, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM navigationColour[] = RGBLIGHT_LAYER_SEGMENTS(
      {0, 5, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM adjustColour[] = RGBLIGHT_LAYER_SEGMENTS(
      {0, 5, HSV_BLUE}
);

const rgblight_segment_t* const PROGMEM layerColours[] = RGBLIGHT_LAYERS_LIST(
   colemakColour,
   symbolColour,
   navigationColour,
   adjustColour
);

void keyboard_post_init_user(void) {
   // Enable the LED layers
   rgblight_layers = layerColours;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
   rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK_Mac));
   return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
   rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK_Win));
   rgblight_set_layer_state(1, layer_state_cmp(state, _SYMB));
   rgblight_set_layer_state(2, layer_state_cmp(state, _NAV));
   rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
   return state;
}

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)
#define CMM_L	TG(_COLEMAK_Mac)
#define CMW_L	TG(_COLEMAK_Win)

#define KC_NAPLS LT(_NAV, KC_PPLS)
#define KC_NARI LT(_NAV, KC_RGHT)

#define KC_ADPSC LT(_ADJUST, KC_PSCR)
#define KC_ADEN LT(_ADJUST, KC_END)

enum{
   SQUO_DQUO,
   SCLN_CLN,
   LSBR_LCBR,
   RSBR_RCBR,
   Min_UNDS,
   Eql_PLUS,
   Dot_RABK,
   Com_LABK,
   FSL_QUES,
   BSL_PIPE
};

tap_dance_action_t tap_dance_actions[] = {
   [SQUO_DQUO] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT,KC_DQUO),
   [SCLN_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN,KC_COLN),
   [LSBR_LCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC,KC_LCBR),
   [RSBR_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC,KC_RCBR),
   [Eql_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_EQL,KC_PLUS),
   [Dot_RABK] = ACTION_TAP_DANCE_DOUBLE(KC_DOT,KC_RABK),
   [Com_LABK] = ACTION_TAP_DANCE_DOUBLE(KC_COMM,KC_LABK),
   [FSL_QUES] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH,KC_QUES),
   [BSL_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS,KC_PIPE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK_Mac] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NUBS , KC_1   ,KC_2    ,KC_3    ,KC_4    , KC_5   ,                                            KC_6    , KC_7   ,KC_8    ,KC_9    ,KC_0    , KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,KC_ESC  ,                          SYM_L   ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,TD(SCLN_CLN) ,TD(Eql_PLUS)  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SYM_L   ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,TD(LSBR_LCBR) ,               TD(RSBR_RCBR),KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,TD(SQUO_DQUO) ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,KC_ADPSC,CMW_L   ,        KC_HOME ,KC_ADEN ,KC_K    ,KC_H    ,TD(Com_LABK) ,TD(Dot_RABK),TD(FSL_QUES) ,TD(BSL_PIPE) ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_NAPLS,KC_MINS ,KC_LCTL ,KC_LOPT ,     KC_LCMD ,    KC_SPC  ,KC_ENT  ,        KC_DEL  ,KC_BSPC ,    KC_RSFT ,     KC_LEFT ,KC_UP   ,KC_DOWN ,KC_NARI 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_COLEMAK_Win] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,TD(Min_UNDS) ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,KC_ESC  ,                          SYM_L   ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,TD(SCLN_CLN) ,TD(Eql_PLUS)  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SYM_L   ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,TD(LSBR_LCBR) ,               TD(RSBR_RCBR),KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,TD(SQUO_DQUO) ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,KC_ADPSC,_______ ,       KC_HOME  ,KC_ADEN ,KC_K    ,KC_H    ,TD(Com_LABK) ,TD(Dot_RABK),TD(FSL_QUES) ,TD(BSL_PIPE) ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LGUI ,KC_NAPLS,KC_MINS ,KC_LALT ,     KC_LCTL ,    KC_SPC  ,KC_ENT  ,        KC_DEL  ,KC_BSPC ,    KC_RSFT ,     KC_LEFT ,KC_UP   ,KC_DOWN ,KC_NARI 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,					                           KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HASH ,KC_AT   ,KC_LABK ,KC_RABK ,KC_PIPE ,_______ ,                          _______ ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_DLR  ,KC_EXLM ,KC_AT   ,KC_NUBS ,KC_PIPE ,CW_TOGG ,                          KC_NUM  ,KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_TILD ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_PERC ,KC_VOLD ,KC_VOLU ,        KC_MCTL ,KC_LPAD ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    KC_MPLY ,KC_MUTE ,        KC_MPRV ,KC_MNXT ,    KC_P0   ,     KC_PDOT ,KC_PDOT ,KC_PENT ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,XXXXXXX ,KC_UP   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX, KC_LEFT ,KC_DOWN ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    KC_BTN1 ,KC_BTN2 ,        _______ ,_______ ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,QK_BOOT,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI  ,                         RGB_SAD  ,RGB_SAI ,RGB_VAD ,RGB_VAI ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RGB_M_B ,RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K ,RGB_M_G ,                         RGB_M_X  ,RGB_M_TW,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};
