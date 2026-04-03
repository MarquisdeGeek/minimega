#include <cstdio>
#include <string>
#include <deque>

#include "emf/emf.h"
#include "premix_loader.h"
#include "io.h"

#include "emulator/megaprocessor/cpp/clock_cpu.h"

#include "emulator/megaprocessor/cpp/megaprocessor_emulator.cpp" // YEAH YEAH - I KNOW!
#include "emulator/megaprocessor/cpp/megaprocessor_emulator.h"

megaprocessor_clock_cpu zx_clock;
megaprocessor_emulator mega_emu;


void mega_start() {

    mega_emu.start();
    zx_clock.setRate(150);

    loadPremixedCode();

    mega_io_start();

    for(int i=0;i<256;++i) {
        write8(0xA000 + i, i);
    }
}


void mega_update() {
    uint32_t totalCycles = zx_clock.getFrequency();
    uint32_t cycles = 0;
    // MegaState state;

    do {
        // mega_emu.getState(&state);
        // printf("%d (%d) : r0=%d r1=%d r2=%d r3=%d sp=%d ix=%d iy=%d\n", state.pc, read8(state.pc), state.r0, state.r1, state.r2, state.r3, state.sp, state.ix, state.iy);
        cycles += mega_emu.step();
    } while(cycles < totalCycles);
    
    mega_io_update();
}



void mega_trapVector1() {
    mega_emu.mp_trapVector1();
}


void mega_end() {
}

