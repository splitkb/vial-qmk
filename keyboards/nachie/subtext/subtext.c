/*
Copyright 2024 nachie

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
#include "quantum.h"

void board_init(void) {
    SYSCFG->CFGR1 |= SYSCFG_CFGR1_I2C1_DMA_RMP; // DMA re-map, you may not need this depending on your
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

static void render_logo(void) {
    static const char PROGMEM my_logo[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0x3f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f,
0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0x00, 0x00, 0x1f, 0x8f, 0x07, 0x03, 0x71, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0x03, 0x01,
0x38, 0x1c, 0x06, 0xa6, 0xb6, 0x86, 0xfc, 0xf8, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0xf1,
0xf9, 0xfc, 0xfc, 0xfc, 0xf8, 0xe1, 0x03, 0x0f, 0xff, 0xff, 0x1f, 0x03, 0x01, 0xf9, 0xfc, 0x1c,
0x80, 0xf8, 0xf0, 0xf1, 0xf7, 0xff, 0xff, 0xff, 0x03, 0x01, 0x38, 0x1c, 0x06, 0xa6, 0xb6, 0x86,
0xfc, 0xf8, 0x00, 0x03, 0xff, 0xff, 0xdf, 0x9f, 0x3f, 0x7f, 0xf8, 0xf2, 0xf2, 0x00, 0x01, 0xff,
0xff, 0xff, 0x07, 0x03, 0x91, 0x99, 0x9c, 0x9c, 0x9c, 0x98, 0x91, 0x83, 0x87, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xe0, 0xe0, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xe0, 0xe3, 0xe7, 0xff, 0xff, 0xff, 0xe0,
0xe0, 0xe0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0xff, 0xff, 0xff, 0x00, 0x00, 0xf1,
0xe7, 0xe7, 0xe7, 0xe7, 0xe3, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xfe, 0xf8, 0x70, 0x03, 0xc0, 0xe4,
0xe7, 0xe7, 0xe1, 0xf0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xfe, 0xff, 0xff, 0xff,
0xff, 0xff, 0xe0, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf1, 0xe1, 0xe0, 0xe0, 0xff,
0xff, 0xff, 0xfc, 0xf0, 0xf1, 0xe3, 0xe7, 0xe7, 0xe7, 0xe7, 0xe3, 0xf1, 0xf9, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
    oled_write_raw_P(my_logo, sizeof(my_logo));
}


bool oled_task_kb(void) {
    // Defer to the keymap if they want to override
    if(!oled_task_user()) {
        return false;
    }

    // default keyboard drawing code
    render_logo();
    return false;
}

#endif