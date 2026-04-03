// Memory controller : 
// std.memory
#include "emf/emf.h"
#include "io.h"

class megaprocessor_memory {
public:
megaprocessor_memory() {
// enableBlock('ram');
// enableBlock('screen_ram');
// enableBlock('peripheral_ram');
}
uint8_t ram[32768] = {
{0}
};
uint8_t screen_ram[256] = {
{0}
};
uint8_t peripheral_ram[256] = {
{0}
};

/*
**
** Basic methods
**
*/
void enableBlock() {
}

void disableBlock() {
}

bool isValidAddress(uint16_t addr) {
// if (addr >= 0 && addr < 32768 && enabledBlockList['ram']) { return true; }
// if (addr >= 40960 && addr < 41216 && enabledBlockList['screen_ram']) { return true; }
// if (addr >= 32768 && addr < 33024 && enabledBlockList['peripheral_ram']) { return true; }
return false;
}
 // isValidAddress

void getAddressRanges() {
  //  let ranges = [];
  // ranges.push({name:'ram', start:0, size:32768, read:true, write:true, shadow:false, enabled:enabledBlockList['ram']});
  // ranges.push({name:'screen_ram', start:40960, size:256, read:true, write:true, shadow:false, enabled:enabledBlockList['screen_ram']});
  // ranges.push({name:'peripheral_ram', start:32768, size:256, read:true, write:true, shadow:false, enabled:enabledBlockList['peripheral_ram']});
  //  return ranges;
}

const char* getLabel(uint16_t addr) {
  //  addr = addr.getUnsigned ? addr.getUnsigned() : addr;
  //  addr &= 0xffff;
return "";
}

uint8_t read8(uint16_t addr) {
  //  addr = addr.getUnsigned ? addr.getUnsigned() : addr;
  //  addr &= 0xffff;
if (addr >= 0 && addr < 32768) {
uint8_t data;
  data = ram[addr - 0];
  //  if (watchList[addr]) {
  //    watchList[addr].cbfn(addr, data, false);
  //  }
return data;
} //fi 
if (addr >= 40960 && addr < 41216) {
uint8_t data;
  data = screen_ram[addr - 40960];
// data = bus.display.hook.onRead8(addr, data);
//    if (watchList[addr]) {
//      watchList[addr].cbfn(addr, data, false);
//    }
return data;
} //fi 
if (addr >= 32768 && addr < 33024) {
uint8_t data;
  data = peripheral_ram[addr - 32768];
  data = mega_io_read8(addr, data);
// data = bus.peripherals.hook.onRead8(addr, data);
//    if (watchList[addr]) {
//      watchList[addr].cbfn(addr, data, false);
//    }
return data;
} //fi 
return 0; // a bad default
}
// read8

void write8(uint16_t addr, uint8_t data) {
  //  addr = addr.getUnsigned ? addr.getUnsigned() : addr;
  //  addr &= 0xffff;
  //  data = data.getUnsigned ? data.getUnsigned() : data;
  //  data &= 0xff;
  // memory_trap8cpp(addr, data);

if (addr >= 0 && addr < 32768) {
  //  if (watchList[addr]) {
  //    watchList[addr].cbfn(addr, data, true);
  //  }
  ram[addr - 0] = data;
return ;
} //fi 
if (addr >= 40960 && addr < 41216) {
// bus.display.hook.onWrite8(addr, data);
//    if (watchList[addr]) {
//      watchList[addr].cbfn(addr, data, true);
//    }
  screen_ram[addr - 40960] = data;
return ;
} //fi 
if (addr >= 32768 && addr < 33024) {
// bus.peripherals.hook.onWrite8(addr, data);
//    if (watchList[addr]) {
//      watchList[addr].cbfn(addr, data, true);
//    }
  peripheral_ram[addr - 32768] = data;
  mega_io_write8(addr, data);
return ;
} //fi 
}
 // write8


/*
**
** Helper methods
**
*/
uint16_t read16(uint16_t addr) {
  // addr = addr.getUnsigned ? addr.getUnsigned() : addr;
  return read8(addr+1)*256 + read8(addr);
}
void write16(uint16_t addr, uint16_t data) {
  // addr = addr.getUnsigned ? addr.getUnsigned() : addr;
  // data = data.getUnsigned ? data.getUnsigned() : data;
  write8(addr+1, data>>8);
  write8(addr+0, data&255);
}


};



megaprocessor_memory memory;

uint8_t fetch8(uint16_t address) { 
  return memory.read8(address);
}

uint8_t read8(uint16_t a) { return memory.read8(a); }
uint16_t read16(uint16_t a) { return memory.read16(a); }

void write8(uint16_t a, uint8_t d) { memory.write8(a,d); }
void write16(uint16_t a, uint16_t d) { memory.write16(a,d); }

