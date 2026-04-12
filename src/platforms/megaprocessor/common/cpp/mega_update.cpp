#include <cstdio>
#include <string>
#include <deque>

#include "emf/emf.h"
#include "premix_loader.h"
#include "io.h"

#include "emulator/megaprocessor/cpp/clock_cpu.h"

#include "emulator/megaprocessor/cpp/megaprocessor_cpu_emulator.cpp" // YEAH YEAH - I KNOW!

megaprocessor_clock_cpu mega_clock;
megaprocessor_cpu_emulator mega_emu;


void mega_start() {

    mega_emu.start();
    mega_clock.setRate(9200);

    loadPremixedCode();

    mega_io_start();

    for(int i=0;i<256;++i) {
        write8(0xA000 + i, i);
    }
}


void mega_update(int fps) {
    uint32_t totalCycles = mega_clock.getFrequency();
    uint32_t cycles = 0;

    totalCycles /= fps;

    do {
#if 0
        MegaState state;
        mega_emu.getState(&state);
        // printf("%d (%d) : r0=%d r1=%d r2=%d r3=%d sp=%d ix=%d iy=%d\n", state.pc, read8(state.pc), state.r0, state.r1, state.r2, state.r3, state.sp, state.ix, state.iy);
        printf("%x (%x) : r0=%x r1=%x r2=%x r3=%x sp=%x ix=%x iy=%x\n", state.pc, read8(state.pc), state.r0, state.r1, state.r2, state.r3, state.sp, state.ix, state.iy);
#endif
        cycles += mega_emu.step();
    } while(cycles < totalCycles);
    
    mega_io_update();
}



void mega_trapVector1() {
    mega_emu.mp_trapVector1();
}


void mega_end() {
}

