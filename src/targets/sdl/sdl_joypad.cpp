#include "sdl_joypad.h"
#include "platforms/megaprocessor/common/cpp/keypad.h"


SDL_MegaprocessorJoypad::SDL_MegaprocessorJoypad() {
    for(int i=0;i<MAX_BUTTONS;++i) {
        m_ButtonState[i] = false;
    }
}


void
SDL_MegaprocessorJoypad::onDown(uint8_t button) {
    if (m_ButtonState[button]) {
        return;
    }
    //
    int key = getJoypadKeyMap(button);

    if (key != -1) {
        mega_keypad_onDown(key);
        m_ButtonState[button] = true;
    }
}


void
SDL_MegaprocessorJoypad::onUp(uint8_t button) {
    if (!m_ButtonState[button]) {
        return;
    }
    //
    int key = getJoypadKeyMap(button);

    if (key != -1) {
        mega_keypad_onUp(key);
        m_ButtonState[button] = false;
    }
}


void
SDL_MegaprocessorJoypad::onAxis(uint8_t axis, int value) {
int deadzone = 200; //  (range: -32768 to 32767)

    switch (axis) {
        case 0: // X
        if (value < -deadzone) {
            mega_keypad_onDown(80); // left
        } else if (value > deadzone) {
            mega_keypad_onDown(79); // right
        } else {
            mega_keypad_onUp(79);
            mega_keypad_onUp(80);
        }
        break;
        //
        case 1: // Y
        if (value < -deadzone) {
            mega_keypad_onDown(82); // up
        } else if (value > deadzone) {
            mega_keypad_onDown(81); // down
        } else {
            mega_keypad_onUp(82);
            mega_keypad_onUp(81);
        }
        break;
        //
        
    }
}


int
SDL_MegaprocessorJoypad::getJoypadKeyMap(int button) {
int key = -1;

    switch(button) {
        case 8: // select
        key = SDLK_q;
        break;
        case 9: // start
        key = SDLK_r;
        break;
        case 0: // A
        key = SDLK_s;
        break;
        case 1: // X
        key = SDLK_z;
        break;
        case 2: // Y
        key = SDLK_d;
        break;
        case 3: // B
        key = SDLK_f;
        break;
        // tetris rotation
        case 4: // left shoulder
        key = SDLK_w;
        break;
        case 5: // right shoulder
        key = SDLK_a;
        break;
    }
    return key;
}
