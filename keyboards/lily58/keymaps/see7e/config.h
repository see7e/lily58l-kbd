/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2020 Ben Roesner (keycapsss.com)

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

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_SPLIT
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_HUE_STEP 6             // number of steps to cycle through the hue by
#    define RGBLIGHT_SAT_STEP 6             // number of steps to increment the saturation by
#    define RGBLIGHT_VAL_STEP 6             // number of steps to increment the brightness by
#    define RGBLIGHT_SLEEP                  //  the RGB lighting will be switched off when the host goes to sleep
#endif

#ifndef RGB_MATRIX_ENABLE
#    define DRIVER_LED_TOTAL 58             // Number of LEDs your Lily58 actually has (check your board config)
#    define RGB_MATRIX_SPLIT { 29, 29 }
/* error: 'RGB_MATRIX_LED_COUNT' undeclared here (not in a function); did you mean 'RGBLIGHT_LED_COUNT'?  */
#    define RGB_MATRIX_LED_COUNT DRIVER_LED_TOTAL

#    define RGB_MATRIX_KEYPRESSES           // reacts to keypresses
// # define RGB_MATRIX_KEYRELEASES

// Effects
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP

#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK
