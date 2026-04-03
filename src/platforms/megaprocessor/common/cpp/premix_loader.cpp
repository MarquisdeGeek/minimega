#include "emf/emf.h"
#include "platforms/megaprocessor/common/cpp/memory.h"


// THere's a hack in:
// /home/steev/work/svn/clients/self/code/native/emf/targets/megaprocessor_ecma6/framework
// to extract the imported data

#if MEGA_PREMIX_TETRIS
#include "sw/tetris.cpp"
#elif MEGA_PREMIX_SNAKE
#include "sw/snake.cpp"
#endif


uint8_t ram[32768];


void loadPremixedCode() {
    filldata(ram);

    for(int i=0;i<sizeof(ram);++i) {
        write8(i, ram[i]);
    }
}

