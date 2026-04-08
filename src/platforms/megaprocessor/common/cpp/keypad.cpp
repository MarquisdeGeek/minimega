#include "emf/emf.h"
#include "platforms/megaprocessor/common/cpp/memory.h"

#include "keypad.h"
#include "keycodes.h"
#include "io.h"
#include <string>
#include <unordered_map>
#include <cstdint>


MegaKeypad mega_keypad;


void mega_keypad_onDown(uint8_t key) {
    mega_keypad.onKeyDown(key);
}

void mega_keypad_onUp(uint8_t key) {
    mega_keypad.onKeyUp(key);
}


static std::unordered_map<int, uint16_t> keyCodes = {
  { SDLK_UP,  0x0001 }, // IO_SWITCH_FLAG_UP
  { SDLK_DOWN,  0x0002 }, // IO_SWITCH_FLAG_DOWN
  { SDLK_LEFT,  0x0004 }, // IO_SWITCH_FLAG_LEFT
  { SDLK_RIGHT,  0x0008 }, // IO_SWITCH_FLAG_RIGHT
  { SDLK_a,  0x0010 }, // IO_SWITCH_FLAG_SQUARE (A)
  { SDLK_w,  0x0020 }, // IO_SWITCH_FLAG_TRIANGLE (W)
  { SDLK_s,  0x0040 }, // IO_SWITCH_FLAG_CIRCLE (S)
  { SDLK_z,  0x0080 }, // IO_SWITCH_FLAG_CROSS (Z)
  { SDLK_e,  0x0100 }, // IO_SWITCH_FLAG_L1 (E)
  { SDLK_d,  0x0200 }, // IO_SWITCH_FLAG_L2 (D)
  { SDLK_r,  0x0400 }, // IO_SWITCH_FLAG_R1 (R)
  { SDLK_f,  0x0800 }, // IO_SWITCH_FLAG_R2 (F)
};



MegaKeypad::MegaKeypad() : m_ioInputData(0xffff) {
}


void MegaKeypad::start() {
    m_ioInputData = 0xffff;
}


uint16_t MegaKeypad::getInputData() const {
    return m_ioInputData;
}


void MegaKeypad::onKeyDown(uint8_t key) {

    // SDL keys do not map my experiments:
    // SDLK_UP is 273, but I get 82 - the same as 'R' (after capitalisation)
    // So, ignore this, and hope CAPS LOCK isn't on
    // key = toupper(key);

    if (keyCodes.find(key) != keyCodes.end()) {
        uint16_t keyMask = keyCodes[key];

        m_ioInputData &= ~keyMask;
    }
}


void MegaKeypad::onKeyUp(uint8_t key) {
    // key = toupper(key);

    if (keyCodes.find(key) != keyCodes.end()) {
        uint16_t keyMask = keyCodes[key];

        m_ioInputData |= keyMask;
    }
}

