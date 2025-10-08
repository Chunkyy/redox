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

#pragma once

/* Select hand configuration */
// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

//#undef RGBLIGHT_LED_COUNT
//#define RGBLIGHT_EFFECT_BREATHING
//#define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#define RGBLIGHT_EFFECT_SNAKE
//#define RGBLIGHT_EFFECT_KNIGHT
//#define RGBLIGHT_EFFECT_CHRISTMAS
//#define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#define RGBLIGHT_EFFECT_RGB_TEST
//#define RGBLIGHT_EFFECT_ALTERNATING
//#define RGBLIGHT_EFFECT_TWINKLE
//#define RGBLIGHT_LED_COUNT 14

#undef RGBLIGHT_LED_COUNT
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL

#define RGBLIGHT_LED_COUNT 10
#define RBGLIGHT_HUE_STEP 21
#define RBGLIGHT_SAT_STEP 20
#define RBGLIGHT_VAL_STEP 20

#define RGBLIGHT_DEFAULT_ON true
#define RGBLIGHT_DEFAULT_HUE 85

#define RGBLIGHT_LAYERS
#define SPLIT_LAYER_STATE_ENABLE

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT

#define TAPPING_TERM 200
#define FLOW_TAP_TERM 150

#define USE_SERIAL
