/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"

#if KEYBOARD_SIDE == LEFT

/*
 * initiialize the default layer (QWERTY/PRESS) with the following
 * keymap
 */
 std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP( /* qwerty */
       KC_EQL,   KC_1,     KC_2,    KC_3,     KC_4,    KC_5,  BLEPROFILE_1,    \
       KC_TAB,   KC_Q,     KC_W,    KC_E,     KC_R,    KC_T,  KC_LBRC,  \
       KC_LCTL,  KC_A,     KC_S,    KC_D,     KC_F,    KC_G,  _______, \
       KC_LSFT,  KC_Z,     KC_X,    KC_C,     KC_V,    KC_B,  _______,  \
       KC_ESC,   KC_GRV,   KC_LBRC, KC_LSFT,  KC_LGUI, KC_ENT, _______, \
       KC_1, BLEPROFILE_2, KC_DEL, KC_BSPC, KC_VOLU, KC_LGUI, KC_LALT \
     )};

void setupKeymap() {

    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP( /* qwerty */
       KC_EQL,   KC_1,     KC_2,    KC_3,     KC_4,    KC_5,  BLEPROFILE_1,    \
       KC_TAB,   KC_Q,     KC_W,    KC_E,     KC_R,    KC_T,  KC_LBRC,  \
       KC_LCTL,  KC_A,     KC_S,    KC_D,     KC_F,    KC_G,  _______, \
       KC_LSFT,  KC_Z,     KC_X,    KC_C,     KC_V,    KC_B,  _______,  \
       KC_ESC,   KC_GRV,   KC_LBRC, KC_LSFT,  KC_LGUI, KC_ENT, _______, \
       KC_1, BLEPROFILE_2, KC_DEL, KC_BSPC, KC_VOLU, KC_LGUI, KC_LALT \
     );


     /*
      * add the other layers
      */
     for (int row = 0; row < MATRIX_ROWS; ++row)
     {
         for (int col = 0; col < MATRIX_COLS; ++col)
         {
             matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
         }
     }

 }
#else

 std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
     {KEYMAP( /* qwerty */
       KC_NO, KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_MINUS,   \
       KC_RBRC,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,  KC_BSLS,  \
       KC_RBRC, KC_H,   KC_J,   KC_K,   KC_L,   KC_SCOLON,  KC_QUOTE, \
       KC_NO,   KC_N,   KC_M, KC_COMMA, KC_DOT, KC_SLASH,   KC_LSFT,  \
       KC_NO,   KC_NO, KC_LEFT,   KC_UP, KC_RIGHT, KC_DOWN, KC_LALT,   \
       KC_LCTL, KC_LGUI, KC_PGUP, KC_SPACE, KC_ENTER, KC_PGDN, KC_NO \
     )};

 void setupKeymap() {

     uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
     KEYMAP( /* qwerty */
       KC_NO, KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_MINUS,   \
       KC_RBRC,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,  KC_BSLS,  \
       KC_RBRC, KC_H,   KC_J,   KC_K,   KC_L,   KC_SCOLON,  KC_QUOTE, \
       KC_NO,   KC_N,   KC_M, KC_COMMA, KC_DOT, KC_SLASH,   KC_LSFT,  \
       KC_NO,   KC_NO, KC_LEFT,   KC_UP, KC_RIGHT, KC_DOWN, KC_LALT,   \
       KC_LCTL, KC_LGUI, KC_PGUP, KC_SPACE, KC_ENTER, KC_PGDN, KC_NO \
     );
     /*
      * add the other layers
      */
     for (int row = 0; row < MATRIX_ROWS; ++row)
     {
         for (int col = 0; col < MATRIX_COLS; ++col)
         {
             matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
         }
     }

 }


#endif /* KEYBOARD_SIDE */
