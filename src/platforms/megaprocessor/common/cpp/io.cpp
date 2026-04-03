#include "emf/emf.h"
#include "mega_update.h"
#include "io.h"
#include "keypad.h"


uint16_t ioTimer;
uint8_t ioTimerControl;
uint16_t ioCounter;

extern MegaKeypad mega_keypad; // our ioInputData hides in here


void mega_io_start() {
    ioTimer = 0xffff;
    ioTimerControl = 0;
    ioCounter = 0;

    mega_keypad.start();
}


void mega_io_update() {
    // Both counter and timer trigger trap vector 1.

    if (++ioCounter == 0) {
        mega_trapVector1();
    }

    if (ioTimerControl & TIME_BLK_TIMER_CTRL_EN_TIMER) {
        if (ioTimer) {
            --ioTimer;
        } else {
            ioTimer = 0xffff;
            mega_trapVector1();
        }
    }
}



uint8_t mega_io_read8(uint16_t addr, uint8_t data) {
    switch (addr) {
    case TIME_BLK_TIMER:
        return ioTimerControl;

    case GEN_IO_INPUT+1:
        return mega_keypad.getInputData() >> 8;
    case GEN_IO_INPUT+0:
        return mega_keypad.getInputData() & 0xff;

    case TIME_BLK_COUNTER+1:
        return ioCounter >> 8;
    case TIME_BLK_COUNTER+0:
        return ioCounter & 0xff;
    }

    return data;
}


void mega_io_write8(uint16_t addr, uint8_t data) {

    if (addr == TIME_BLK_TIMER_CTRL) {
        ioTimerControl = data;
    }
}

