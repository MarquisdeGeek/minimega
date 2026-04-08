#include "emf/emf.h"
#include "platforms/megaprocessor/common/cpp/memory.h"


// THere's a hack in:
// /home/steev/work/svn/clients/self/code/native/emf/targets/megaprocessor_ecma6/framework
// to extract the imported data


static uint8_t ram[32768];


void loadPremixedCode() {
    extern void filldata(uint8_t* ram);

    filldata(ram);

    for(int i=0;i<sizeof(ram);++i) {
        write8(i, ram[i]);
    }
}

