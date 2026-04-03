#include <math.h>

#include "emf/emf.h"
#include "emulator/megaprocessor/cpp/megaprocessor_emulator.h"

#include "platforms/megaprocessor/common/cpp/memory.h"


// megaprocessor_cpu_emulator
class megaprocessor_emulator {
public:

#include "zx81_z80_emulator.cpp.alu.h"

uint16_t alu_lsl16wt(uint16_t v, uint16_t n) {
// TODO
return 0;
}

uint16_t alu_lsr16wt(uint16_t v, uint16_t n) {
// TODO
return 0;
}
uint16_t alu_asl16wt(uint16_t v, uint16_t n) {
// TODO
return 0;
}
uint16_t alu_asr16wt(uint16_t v, uint16_t n) {
// TODO
return 0;
}
uint16_t alu_rol16wt(uint16_t v, uint16_t n) {
// TODO
return 0;
}
uint16_t alu_ror16wt(uint16_t v, uint16_t n) {
// TODO
return 0;
}
uint16_t alu_roxl16wt(uint16_t v, uint16_t n) {
// TODO
return 0;
}
uint16_t alu_roxr16wt(uint16_t v, uint16_t n) {
// TODO
return 0;
}


emfNumber<uint8_t> tmp8;
emfNumber<uint16_t> tmp16;

emfNumber<uint8_t> f;


bool cc_bit_0 = 0;
bool cc_bit_1 = 0;
bool cc_bit_2 = 0;
bool cc_bit_3 = 0;
bool cc_bit_4 = 0;
bool cc_bit_5 = 0;
bool cc_bit_6 = 0;
bool cc_bit_7 = 0;



uint8_t computeFlags8(uint8_t r) {
  wasSign = r & 0x80 ? 1 : 0;
  wasZero = r == 0 ? 1 : 0;
  wasParity = getParity8(r);
  return r;
}

uint16_t computeFlags16(uint16_t r) {
  wasSign = r & 0x8000 ? 1 : 0;
  wasZero = r == 0 ? 1 : 0;
  wasParity = getParity16(r);
  return r;
}


#if 0
let inHalt = false;

    bus.attachPin('reset', {
    	onFalling: function() {
    		reset();
    	},
    });

    bus.attachPin('counter', {
        onFalling: function() {
            mp_interruptCounter();
        }
    });

    bus.attachPin('timer', {
        onFalling: function() {
            mp_interruptTimer();
        }
    });
// Options: directMemory = true
// Options: directFetch = true
let read1 = function(a) {
  return read8(a) & 0x01;
}
let read2 = function(a) {
  return read8(a) & 0x03;
}
let read3 = function(a) {
  return read8(a) & 0x07;
}
let read4 = function(a) {
  return read8(a) & 0x0f;
}
let read5 = function(a) {
  return read8(a) & 0x1f;
}
let read6 = function(a) {
  return read8(a) & 0x3f;
}
let read7 = function(a) {
  return read8(a) & 0x7f;
}
let read8;
let read9 = function(a) {
  return read16(a) & 0x1ff;
}
let read10 = function(a) {
  return read16(a) & 0x3ff;
}
let read11 = function(a) {
  return read16(a) & 0x7ff;
}
let read12 = function(a) {
  return read16(a) & 0xfff;
}
let read13 = function(a) {
  return read16(a) & 0x1fff;
}
let read14 = function(a) {
  return read16(a) & 0x3fff;
}
let read15 = function(a) {
  return read16(a) & 0x7fff;
}
let read16;
#endif

int read4(int a) {
  return read8(a) & 0x0f;
}

int read5(int a) {
  return read8(a) & 0x1f;
}
int read7(int a) {
  return read8(a) & 0x7f;
}

/*
**
** Declarations
**
*/
emfNumber<uint16_t> r0 = 0;
emfNumber<uint16_t> r1 = 0;
emfNumber<uint16_t> r2 = 0;
emfNumber<uint16_t> r3 = 0;
emfNumber<uint16_t> pc = 0;
emfNumber<uint16_t> sp = 0;
emfNumber<uint16_t> ix = 0;
emfNumber<uint16_t> iy = 0;
// CHANGE: 
emfNumber<uint16_t> ps = 0;


/*
**
** Internal state
**
*/

/*
**
** Bus
**
*/
void setupBusHandlersInternal() {
// Watching the pins
}

/*
**
** ALU
**
*/
void set(emfNumber<uint16_t>& r, int v) {
	r.assign(v);
}

auto get(emfNumber<uint16_t>& r) {
	return r.getUnsigned();
}

auto reg(emfNumber<uint16_t>& r) {
	return r;
}

uint16_t lit(uint16_t v) {
    return v;
}

emfNumber<uint16_t> lit(emfNumber<uint16_t>& v) {
	return v;
}
// NOTE: When using the bus versions, this uses Z80 conventions
// let in8;
// let out8;
// let write8;
// let fetch8;
// let write16;
//
void setupBusHandlers() {
    #if 0
  if (options.directIORQ) {
    in8 = bus.iorq.readPort;
    out8 = bus.iorq.writePort;
  } else {
    in8 = function(port) {
      port = port.getUnsigned ? port.getUnsigned() : port;
      bus.writeBlock('address', port);
      bus.setLow('rd');
      bus.setLow('iorq');
      let data = bus.readBlock('data');
      bus.setHigh('iorq');
      bus.setHigh('rd');
      return data;
    };

    out8 = function(port, data) {
      port = port.getUnsigned ? port.getUnsigned() : port;
      data = data.getUnsigned ? data.getUnsigned() : data;
      bus.writeBlock('address', port);
      bus.writeBlock('data', data);
      bus.setLow('wr');
      bus.pulseLow('iorq');
      bus.setHigh('wr');
    };
  }
  //
  if (options.directMemory) {
    // TODO: don't auto generate these
    read8 = bus.memory.read8;
    read16 = bus.memory.read16;
    write8 = bus.memory.write8;
    write16 = bus.memory.write16;
  } else {
    // TODO: CPU needs endian knowledge to do read16
    read8 = function(address) {
      address = address.getUnsigned ? address.getUnsigned() : address;
      bus.writeBlock('address', address);
      bus.setLow('rd');
      bus.setLow('mreq');
      let data = bus.readBlock('data');
      bus.setHigh('mreq');
      bus.setHigh('rd');
      return data;
    };

    write8 = function(address, data) {
      address = address.getUnsigned ? address.getUnsigned() : address;
      data = data.getUnsigned ? data.getUnsigned() : data;
      bus.writeBlock('address', address);
      bus.writeBlock('data', data);
      bus.setLow('wr');
      bus.pulseLow('mreq');
      bus.setHigh('wr');
    };

    read16 = function(address) {
      address = address.getUnsigned ? address.getUnsigned() : address;
      if (isBigEndian) {
        return read8(address) * 256 + read8(address + 1);
      } else {
        return read8(address + 1) * 256 + read8(address);
      }
    };

    write16 = function(address, data) {
      address = address.getUnsigned ? address.getUnsigned() : address;
      data = data.getUnsigned ? data.getUnsigned() : data;

      if (isBigEndian) {
        write8(address + 0, data >> 8);
        write8(address + 1, data & 0xff);
      } else {
        write8(address + 1, data >> 8);
        write8(address + 0, data & 0xff);
      }
    };
  }
  //
  if (options.directFetch) {
    fetch8 = function() {
      let pcValue = pc.getUnsigned();
      return bus.memory.read8(pcValue);
    };
  } else {
    fetch8 = function() {
      let pcValue = pc.getUnsigned();
      bus.writeBlock('address', pcValue);
      bus.setLow('m1');
      bus.setLow('rd');
      bus.setLow('mreq');
      let data = bus.readBlock('data');
      bus.setHigh('mreq');
      bus.setHigh('rd');
      bus.setHigh('m1');

      // TODO: Re-introduce this?
      //pc.inc();
      updateMemoryRefresh();

      return data;
    };

  }
  //
#endif
}

#if 0
  function processBytes(bytes) {
    let offetch8 = fetch8;
    let address = 0;
    let pc = getRegisterValuePC();

    fetch8 = function() {
      return bytes[address++];
    };
    processOpcode();

    let pcnow = getRegisterValuePC();
    if (pcnow - pc === bytes.length) {
      // PC has only moved by the bytes in the instruction, so
      // repair the original PC
      setRegisterValuePC(pc);
    } else {
      // The instruction was a jump, so keep whatever PC it has
    }
    fetch8 = offetch8;
  }
var alu = alu || {};

alu_parityLUT8 = [];

alu_start = function() {
  for (let i = 0; i < 256; ++i) {
    alu_parityLUT8[i] = calculateParity(i);
  }
}

alu_reset = function() {

}

function calculateParity(v, sz = 8) {
  let bits = 0;

  v = v & 255; /// ensure it's positive, for the table deference

  for (let i = 0; i < sz; ++i) {
    if (v & (1 << i)) {
      ++bits;
    }
  }
  let parity = (bits & 1) == 1 ? 0 : 1; // odd parity returns 0
  return parity;
}
let flagHalfCarryAdd = [0, 1, 1, 1, 0, 0, 0, 1];
let flagHalfCarrySub = [0, 0, 1, 0, 1, 0, 1, 1];
#endif

uint8_t parityLUT8[256];


uint8_t flagHalfCarryAdd[8] = {0, 1, 1, 1, 0, 0, 0, 1};
uint8_t flagHalfCarrySub[8] = {0, 0, 1, 0, 1, 0, 1, 1};

// Common var for many ALU calculations
// TODO: consider whether a local var is better for small memory environments
u32 result;

// utility methods
bool wasCarry;
bool wasNegation;
bool wasOverflow;
bool wasHalfCarry;
bool wasZero;
bool wasSign;
bool wasParity;
//
bool aluLastResult;
bool sign() {
  return wasSign;
}

bool sign16() {
  return wasSign;
}

bool zero() {
  return wasZero;
}

bool halfcarry() {
  return wasHalfCarry;
}

bool overflow() {
  return wasOverflow;
}

bool parity() {
  return wasParity;
}

bool carry() {
  return wasCarry;
}

bool getParity8(int v) {
  return parityLUT8[v];
}

bool getParity16(int v) {
  return parityLUT8[v & 255] ^ parityLUT8[v >> 8];
}



/*
**
** Utility methods
**
*/
void start() {
alu_main_start();
setupBusHandlersInternal();
setupBusHandlers();
return reset();
}

void reset() {
//   alu_reset();
  r0.assign(0);
  r1.assign(0);
  r2.assign(0);
  r3.assign(0);
  pc.assign(0);
  sp.assign(0);
  ix.assign(0);
  iy.assign(0);
  ps.assign(0);
}
#if 0
 function getRegisterValueR0() {
  return r0.getUnsigned();
}
function setRegisterValueR0(v) {
   r0.assign(v);
}
function getRegisterValueR1() {
  return r1.getUnsigned();
}
function setRegisterValueR1(v) {
   r1.assign(v);
}
function getRegisterValueR2() {
  return r2.getUnsigned();
}
function setRegisterValueR2(v) {
   r2.assign(v);
}
function getRegisterValueR3() {
  return r3.getUnsigned();
}
function setRegisterValueR3(v) {
   r3.assign(v);
}
function getRegisterValuePC() {
  return pc.getUnsigned();
}
function setRegisterValuePC(v) {
   pc.assign(v);
}
function getRegisterValueSP() {
  return sp.getUnsigned();
}
function setRegisterValueSP(v) {
   sp.assign(v);
}
function getRegisterValueIX() {
  return ix.getUnsigned();
}
function setRegisterValueIX(v) {
   ix.assign(v);
}
function getRegisterValueIY() {
  return iy.getUnsigned();
}
function setRegisterValueIY(v) {
   iy.assign(v);
}
function getRegisterValuePS() {
  return ps.getUnsigned();
}
function setRegisterValuePS(v) {
   ps.assign(v);
}
function getRegisterValue(name) {
  name = name.toLowerCase();
  if (name == 'r0') return getRegisterValueR0();
  if (name == 'r1') return getRegisterValueR1();
  if (name == 'r2') return getRegisterValueR2();
  if (name == 'r3') return getRegisterValueR3();
  if (name == 'pc') return getRegisterValuePC();
  if (name == 'sp') return getRegisterValueSP();
  if (name == 'ix') return getRegisterValueIX();
  if (name == 'iy') return getRegisterValueIY();
  if (name == 'ps') return getRegisterValuePS();
}
function setRegisterValue(name,v) {
  name = name.toLowerCase();
  if (name === 'r0') return setRegisterValueR0(v);
  if (name === 'r1') return setRegisterValueR1(v);
  if (name === 'r2') return setRegisterValueR2(v);
  if (name === 'r3') return setRegisterValueR3(v);
  if (name === 'pc') return setRegisterValuePC(v);
  if (name === 'sp') return setRegisterValueSP(v);
  if (name === 'ix') return setRegisterValueIX(v);
  if (name === 'iy') return setRegisterValueIY(v);
  if (name === 'ps') return setRegisterValuePS(v);
}
void setFlagValue(name, v) {
  name = name.toLowerCase();
  if (name === 'u') return changeFlagU(v);
  if (name === 'd') return changeFlagD(v);
  if (name === 'c') return changeFlagC(v);
  if (name === 'x') return changeFlagX(v);
  if (name === 'v') return changeFlagV(v);
  if (name === 'z') return changeFlagZ(v);
  if (name === 'n') return changeFlagN(v);
  if (name === 'i') return changeFlagI(v);
}
#endif


uint16_t getRegisterValuePC() {
  return pc.getUnsigned();
}
void setRegisterValuePC(uint16_t v) {
   pc.assign(v);
}
uint16_t getRegisterValueSP() {
  return sp.getUnsigned();
}
void setRegisterValueSP(uint16_t v) {
   sp.assign(v);
}
uint16_t getRegisterValueIX() {
  return ix.getUnsigned();
}
void setRegisterValueIX(uint16_t v) {
   ix.assign(v);
}
uint16_t getRegisterValueIY() {
  return iy.getUnsigned();
}
void setRegisterValueIY(uint16_t v) {
   iy.assign(v);
}

//

bool getFlagU() {
  return (ps.getUnsigned() & (1<<7)) ? 1 : 0;
}
void clearFlagU() {
  ps.assign(ps.getUnsigned() & ~(1<<7));
}
void setFlagU() {
  ps.assign(ps.getUnsigned() | (1<<7));
}
void affectFlagU() {
  if (uflag()) {
    setFlagU();
} else {
    clearFlagU();
  }
}
void changeFlagU(bool newState) {
  if (newState) { // uflag
    setFlagU();
} else {
    clearFlagU();
  }
}
//
bool getFlagD() {
  return (ps.getUnsigned() & (1<<6)) ? 1 : 0;
}
void clearFlagD() {
  ps.assign(ps.getUnsigned() & ~(1<<6));
}
void setFlagD() {
  ps.assign(ps.getUnsigned() | (1<<6));
}
void affectFlagD() {
  if (dflag()) {
    setFlagD();
} else {
    clearFlagD();
  }
}
bool changeFlagD(bool newState) {
  if (newState) { // dflag
    setFlagD();
} else {
    clearFlagD();
  }
  return newState;
 }
bool getFlagC() {
  return (ps.getUnsigned() & (1<<5)) ? 1 : 0;
}
void clearFlagC() {
  ps.assign(ps.getUnsigned() & ~(1<<5));
}
void setFlagC() {
  ps.assign(ps.getUnsigned() | (1<<5));
}
void affectFlagC() {
  if (carry()) {
    setFlagC();
} else {
    clearFlagC();
  }
}
bool changeFlagC(bool newState) {
  if (newState) { // carry
    setFlagC();
} else {
    clearFlagC();
  }
  return newState;
 }

bool getFlagX() {
  return (ps.getUnsigned() & (1<<4)) ? 1 : 0;
}
void clearFlagX() {
  ps.assign(ps.getUnsigned() & ~(1<<4));
}
void setFlagX() {
  ps.assign(ps.getUnsigned() | (1<<4));
}
void affectFlagX() {
  if (xflag()) {
    setFlagX();
} else {
    clearFlagX();
  }
}
bool changeFlagX(bool newState) {
  if (newState) { // xflag
    setFlagX();
} else {
    clearFlagX();
  }
  return newState;
 }

bool getFlagV() {
  return (ps.getUnsigned() & (1<<3)) ? 1 : 0;
}
void clearFlagV() {
  ps.assign(ps.getUnsigned() & ~(1<<3));
}
void setFlagV() {
  ps.assign(ps.getUnsigned() | (1<<3));
}
void affectFlagV() {
  if (overflow()) {
    setFlagV();
} else {
    clearFlagV();
  }
}
bool changeFlagV(bool newState) {
  if (newState) { // overflow
    setFlagV();
} else {
    clearFlagV();
  }
  return newState;
 }

bool getFlagZ() {
  return (ps.getUnsigned() & (1<<2)) ? 1 : 0;
}
void clearFlagZ() {
  ps.assign(ps.getUnsigned() & ~(1<<2));
}
void setFlagZ() {
  ps.assign(ps.getUnsigned() | (1<<2));
}
void affectFlagZ() {
  if (zero()) {
    setFlagZ();
} else {
    clearFlagZ();
  }
}
bool changeFlagZ(bool newState) {
  if (newState) { // zero
    setFlagZ();
} else {
    clearFlagZ();
  }
  return newState;
 }

bool getFlagN() {
  return (ps.getUnsigned() & (1<<1)) ? 1 : 0;
}
void clearFlagN() {
  ps.assign(ps.getUnsigned() & ~(1<<1));
}
void setFlagN() {
  ps.assign(ps.getUnsigned() | (1<<1));
}
void affectFlagN() {
  if (sign()) {
    setFlagN();
} else {
    clearFlagN();
  }
}
bool changeFlagN(bool newState) {
  if (newState) { // sign
    setFlagN();
} else {
    clearFlagN();
  }
  return newState;
 }

bool getFlagI() {
  return (ps.getUnsigned() & (1<<0)) ? 1 : 0;
}
void clearFlagI() {
  ps.assign(ps.getUnsigned() & ~(1<<0));
}
void setFlagI() {
  ps.assign(ps.getUnsigned() | (1<<0));
}
void affectFlagI() {
  if (iflag()) {
    setFlagI();
} else {
    clearFlagI();
  }
}
bool changeFlagI(bool newState) {
  if (newState) { // iflag
    setFlagI();
} else {
    clearFlagI();
  }
  return newState;
 }




int update() {
   // emf.control ensures only 1 step is executed
   return step();
}
bool wasFlagX;
// Shifts..

int previousWeight;


int16_t alu_as_s5(uint16_t v) {
	v &= 0x1f; // LSB 5 bits
	if (v & 0x10) { // -32 is set
		return -16 + (v & 0x0f);
	}
	return v;
}

// Logical
uint16_t alu_lsl16(uint16_t v, uint16_t n) {
	int16_t ns = alu_as_s5(n);
	if (ns<0) {
		return alu_lsr16_op(v, -(ns));
	}
	
	return alu_lsl16_op(v, ns);
}

uint16_t alu_lsr16(uint16_t v, uint16_t n) {
	int16_t ns = alu_as_s5(n);
	if (ns<0) {
		return alu_lsl16_op(v, -(ns));
	}
	return alu_lsr16_op(v, ns);
}

uint16_t alu_lsl16_op(uint16_t v, uint16_t n) {
	uint16_t  result = v;
	previousWeight = 0;

	wasCarry = 0; // because it's cleared for a shift of 0
	wasOverflow = 0;

	while(n) {
		uint16_t  previousMSB = result & 0x8000;
		result <<= 1;

		if (previousMSB != result & 0x8000) {
			wasOverflow = 1;
		}

		wasCarry = (result & 0x8000) ? 1 : 0;
		wasFlagX = wasCarry;
		previousWeight += wasCarry;

		result &= 0xffff;
		computeFlags16(result);
		//
		--n;
	}
	//
	return result;
}

uint16_t alu_lsr16_op(uint16_t v, uint16_t n) {
	uint16_t  result = v;
	previousWeight = 0;

	wasCarry = 0; // because it's cleared for a shift of 0
	wasOverflow = 0;

	while(n) {
		wasCarry = (result & 1) ? 1 : 0;
		wasFlagX = wasCarry;
		previousWeight += wasCarry;

		uint16_t  previousMSB = result & 0x8000;
		//
		result >>= 1;
		result &= 0xffff;
		//
		computeFlags16(result);

		if (previousMSB != result & 0x8000) {
			wasOverflow = 1;
		}
		//
		--n;
	}

	return result;
}


uint16_t alu_lsl16wt(emfNumber<uint16_t> destreg, uint16_t v, uint16_t n) {
	alu_lsl16wt(v,n);
	destreg.assign(previousWeight);
}

uint16_t alu_lsr16wt(emfNumber<uint16_t> destreg, uint16_t v, uint16_t n) {
	alu_lsr16wt(v,n);
	destreg.assign(previousWeight);
}


// Arithmetic
uint16_t alu_asl16(uint16_t v, uint16_t n) {
	// NOTE: ASL is the same as LSL, AFAICS
	int16_t ns = alu_as_s5(n);
	if (ns<0) {
		return alu_asr16_op(v, -(ns));
	}
	
	return alu_asl16_op(v, ns);
}

uint16_t alu_asr16(uint16_t v, uint16_t n) {
	int16_t ns = alu_as_s5(n);
	if (ns<0) {
		return alu_asl16_op(v, -(ns));
	}
	return alu_asr16_op(v, ns);
}

uint16_t alu_asl16_op(uint16_t v, uint16_t n) {
	uint16_t  result = v;
	previousWeight = 0;

	while(n) {
		result <<= 1;

		wasCarry = (result & 0x8000) ? 1 : 0;
		wasFlagX = wasCarry;
		previousWeight += wasCarry;

		result &= 0xffff;
		computeFlags16(result);
		//
		--n;
	}
	//
	return result;
}

uint16_t alu_asr16_op(uint16_t v, uint16_t n) {
	uint16_t  result = v;
	previousWeight = 0;

	while(n) {
		wasCarry = (result & 1) ? 1 : 0;
		wasFlagX = wasCarry;
		previousWeight += wasCarry;

		result >>= 1;
		result |= (result & 0x4000) << 1; // replicate the MSB, which is now 1 bit further to the right
		result &= 0xffff;
		//
		computeFlags16(result);
		//
		--n;
	}

	return result;
}

uint16_t alu_asl16wt(emfNumber<uint16_t> destreg, uint16_t v, uint16_t n) {
	alu_asl16wt(v,n);
	destreg.assign(previousWeight);
  return destreg;
}

uint16_t alu_asr16wt(emfNumber<uint16_t> destreg, uint16_t v, uint16_t n) {
	alu_asr16wt(v,n);
	destreg.assign(previousWeight);
  return destreg;
}



// Rolling
uint16_t alu_rol16(uint16_t v, uint16_t n) {
	// NOTE: ASL is the same as LSL, AFAICS
	int16_t ns = alu_as_s5(n);
	if (ns<0) {
		return alu_ror16_op(v, -(ns));
	}
	
	return alu_rol16_op(v, ns);
}

uint16_t alu_ror16(uint16_t v, uint16_t n) {
	int16_t ns = alu_as_s5(n);
	if (ns<0) {
		return alu_rol16_op(v, -(ns));
	}
	return alu_ror16_op(v, ns);
}

uint16_t alu_rol16_op(uint16_t v, uint16_t n) {
	uint16_t  result = v;
	previousWeight = 0;

	while(n) {
		result <<= 1;

		wasCarry = (result & 0x10000) ? 1 : 0;
		result |= wasCarry;

		previousWeight += wasCarry;

		result &= 0xffff;
		computeFlags16(result);
		//
		--n;
	}
	//
	return result;
}

uint16_t alu_ror16_op(uint16_t v, uint16_t n) {
	uint16_t  result = v;
	previousWeight = 0;
	bool prevCarry = getFlagC();

	while(n) {
		wasCarry = (result & 1) ? 1 : 0;
		previousWeight += wasCarry;

		result >>= 1;
		result |= prevCarry ? 0x8000 : 0;
		result &= 0xffff;
		//
		prevCarry = wasCarry;
		//
		computeFlags16(result);
		//
		--n;
	}

	return result;
}

uint16_t alu_rol16wt(emfNumber<uint16_t> destreg, uint16_t v, uint16_t n) {
	alu_rol16wt(v,n);
	destreg.assign(previousWeight);
  return destreg;
}

uint16_t alu_ror16wt(emfNumber<uint16_t> destreg,uint16_t  v, uint16_t n) {
	alu_ror16wt(v,n);
	destreg.assign(previousWeight);
  return destreg;
}


// Extended Rolling
uint16_t alu_roxl16(uint16_t v, uint16_t n) {
	int16_t ns = alu_as_s5(n);
	if (ns<0) {
		return alu_roxr16_op(v, -(ns));
	}
	
	return alu_roxl16_op(v, ns);
}

uint16_t alu_roxr16(uint16_t v, uint16_t n) {
	int16_t ns = alu_as_s5(n);
	if (ns<0) {
		return alu_roxl16_op(v, -(ns));
	}
	return alu_roxr16_op(v, ns);
}

uint16_t alu_roxl16_op(uint16_t v, uint16_t n) {
	uint16_t  result = v;
	previousWeight = 0;
	wasXFlag = getFlagX();

	while(n) {
		result <<= 1;

		wasCarry = (result & 0x8000) ? 1 : 0;
		result |= wasXFlag;

		wasXFlag = wasCarry;

		previousWeight += (result&2) ? 1: 0; // &2 checks bit 1, because result has already been shifted

		result &= 0xffff;
		computeFlags16(result);
		//
		--n;
	}
	//
	return result;
}

uint16_t alu_roxr16_op(uint16_t v, uint16_t n) {
	uint16_t  result = v;
	previousWeight = 0;
	wasXFlag = getFlagX();

	while(n) {
		wasCarry = (result & 1) ? 1 : 0;
		previousWeight += wasCarry;

		result >>= 1;
		result |= wasXFlag ? 0x8000 : 0;
		result &= 0xffff;
		//
		wasXFlag = wasCarry;
		computeFlags16(result);
		//
		--n;
	}

	return result;
}

uint16_t alu_roxl16wt(emfNumber<uint16_t> destreg, uint16_t v, uint16_t n) {
	alu_roxl16wt(v,n);
	destreg.assign(previousWeight);
  return destreg;
}

uint16_t alu_roxr16wt(emfNumber<uint16_t> destreg, uint16_t v,uint16_t  n) {
	alu_roxr16wt(v,n);
	destreg.assign(previousWeight);
  return destreg;
}



void alu_cmp16(uint16_t v1, uint16_t v2) {
	//TODO
	wasCarry = (v1 & 0x80) ? 1 : 0;
	wasFlagX = wasCarry;
	wasZero = v1 == v2 ? 1 : 0;
}


uint16_t alu_bchg16(uint16_t v1, uint16_t bit) {
	uint16_t wasBit = v1 & (1<<bit);
	wasZero = wasBit == 0 ? 1 : 0;
	return v1 ^ (1<<bit); // change the bit with XOR
}

uint16_t alu_bclr16(uint16_t v1, uint16_t bit) {
	uint16_t wasBit = v1 & (1<<bit);
	wasZero = wasBit == 0 ? 1 : 0;
	return v1 & ~(1<<bit);
}

uint16_t alu_bset16(uint16_t v1, uint16_t bit) {
	uint16_t wasBit = v1 & (1<<bit);
	wasZero = wasBit == 0 ? 1 : 0;
	return v1 | (1<<bit);
}

void alu_btst16(uint16_t v1,uint16_t bit) {
	uint16_t wasBit = v1 & (1<<bit);
	wasZero = wasBit == 0 ? 1 : 0;
}

// MP-specific
void mp_interruptCounter() {
	// Q. TODO. Is this right?
	mp_trapVector1();
}

void mp_interruptTimer() {
	// Q. TODO. Is this right?
	mp_trapVector1();
}

void mp_trapDivideZero() {
	mp_trapVector(2);
}

// The vectors are offsets of  0x0, 0x4, 0x8 and 0xC relative to the vector base.
void mp_trapVector(int vector) {
	// push pc
	set(sp, alu_add_u16u16(sp,lit(-2)));
	write16(get(sp),alu_add_u16u16(pc,1));

	// push sp
	set(sp, alu_add_u16u16(get(sp),lit(-1)));
	write8(get(sp), get(ps));

	// Jump
	set(pc, 0 + vector * 4 - 1); // -1 because of PC increments afterwards

}

void mp_trapVector0() { // reset
	mp_trapVector(0);
}

void mp_trapVector1() { // ext_int
	mp_trapVector(1);
}

void mp_trapVector2() { // div_zero
	mp_trapVector(2);
}

void mp_trapVector3() { // illegal
	mp_trapVector(3);
}

uint16_t Math_floor(float v) {
    return v;
}

void alu_divu() {
	if (r1.getUnsigned() == 0) {
		mp_trapDivideZero();
	}
	uint16_t quotient = Math_floor(r0.getUnsigned() / r1.getUnsigned());
	uint16_t remainder = Math_floor(r0.getUnsigned() % r1.getUnsigned());

	uint16_t dflag = getFlagD();
	if (dflag && remainder < 0) { // no negative remainders allowed
		quotient += quotient > 0 ? 1 : -1; //i.e abs()
		remainder += r1.getUnsigned();
	}

	r2.assign(quotient);
	r3.assign(remainder);
}

void alu_divs() {
	alu_divu();
	r1.abs();
}

void alu_mulu() {
	u32 result = r0.getUnsigned() * r1.getUnsigned();

	r2.assign((result & 0x0000ffff) >>  0);
	r3.assign((result & 0xffff0000) >> 16);
}

void alu_muls() {
	alu_mulu();

	if (r0.getUnsigned() < 0) {
		r0.assign(0);
	}

	if (r1.getUnsigned() < 0) {
		r0.assign(r0.getUnsigned() + r1.getUnsigned());
	}

}

uint16_t Math_sqrt(uint16_t c) {
    return sqrt(c);
}

uint16_t alu_sqrt() {
uint16_t root = Math_floor(Math_sqrt(r1.getUnsigned()));
uint16_t error = r1.getUnsigned() - (root * root);

	r0.assign(root);
	r1.assign(error);
	r2.assign(0);

  return root;// but unused
}


uint16_t alu_neg16(uint16_t v) {
	if (v == 0x8000) {
		wasOverflow = 1;
	}
	//
	v = (-v & 0xffff);
	return computeFlags16(v);
}

uint16_t alu_signextend16(uint16_t v) {
	if (v & 0x80) {
		v |= 0xff00;
	} else {
		v &= 0x00ff;
	}

	return computeFlags16(v);
}

void mp_trap() {
	pc.sub(2);
	write16(sp.getUnsigned(), pc.getUnsigned()+1);
	sp.sub(1);
	write8(sp.getUnsigned(), ps.getUnsigned());
	pc.assign(0xc - 1);
}


		
		// utility methods
		bool wasXFlag;
		bool wasIFlag;
		

		bool xflag() {
			return wasXFlag;
		}
		bool iflag() {
			return wasIFlag;
		}
		
		bool uflag() {
			return 0;
		}
		
		bool dflag() {
			return 0;
		}
		

		uint8_t complement(emfNumber<uint8_t> v1) {
			uint8_t v =  v1.getUnsigned();
			return computeFlags8(~v);
		}		

		uint16_t alu_invert16(emfNumber<uint16_t> v1) {
			uint16_t v = v1.getUnsigned();
			return computeFlags16(~v);
		}

		//
		// CPU handlers

		void updateMemoryRefresh() {
		}

		bool updateInterupts() {
			return false;
		}

int step()  {
   return processOpcode();
}
// Writing from instruction block:
// /emf/res/devices/megaprocessor/mp.xml
int processOpcode() {
int bit;  /* of type i8 */
int opcode = fetch8(pc);  /* of type i8 */
int cycles = 1;  /* of type i8 */
switch (opcode) {
case 0: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r0,get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
cycles += 1;
// sxt @r;
// Reference:  page 53
set(r0, alu_signextend16(get(r0)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 1: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r1,get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 2: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r2,get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 3: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r3,get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 4: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r0,get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 5: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r1,get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
cycles += 1;
// sxt @r;
// Reference:  page 53
set(r1, alu_signextend16(get(r0)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 6: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r2,get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 7: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r3,get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 8: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r0,get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 9: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r1,get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 10: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r2,get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
cycles += 1;
// sxt @r;
// Reference:  page 53
set(r2, alu_signextend16(get(r0)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 11: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r3,get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 12: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r0,get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 13: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r1,get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 14: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r2,get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 15: {
cycles += 1;
// move @r,@s;
// Reference:  page 34
set(r3,get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
cycles += 1;
// sxt @r;
// Reference:  page 53
set(r3, alu_signextend16(get(r0)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 16: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r0,alu_and16(get(r0),get(r0)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
cycles += 1;
// test @r;
// Reference:  page 55
alu_test16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 17: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r1,alu_and16(get(r1),get(r0)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 18: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r2,alu_and16(get(r2),get(r0)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 19: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r3,alu_and16(get(r3),get(r0)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 20: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r0,alu_and16(get(r0),get(r1)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 21: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r1,alu_and16(get(r1),get(r1)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
cycles += 1;
// test @r;
// Reference:  page 55
alu_test16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 22: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r2,alu_and16(get(r2),get(r1)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 23: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r3,alu_and16(get(r3),get(r1)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 24: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r0,alu_and16(get(r0),get(r2)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 25: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r1,alu_and16(get(r1),get(r2)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 26: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r2,alu_and16(get(r2),get(r2)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
cycles += 1;
// test @r;
// Reference:  page 55
alu_test16(get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 27: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r3,alu_and16(get(r3),get(r2)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 28: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r0,alu_and16(get(r0),get(r3)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 29: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r1,alu_and16(get(r1),get(r3)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 30: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r2,alu_and16(get(r2),get(r3)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 31: {
cycles += 1;
// and @r,@s;
// Reference:  page 9
set(r3,alu_and16(get(r3),get(r3)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
cycles += 1;
// test @r;
// Reference:  page 55
alu_test16(get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 32: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r0, alu_xor16(get(r0),get(r0)));
pc.add(1);
 return cycles;
} break;
case 33: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r1, alu_xor16(get(r1),get(r0)));
pc.add(1);
 return cycles;
} break;
case 34: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r2, alu_xor16(get(r2),get(r0)));
pc.add(1);
 return cycles;
} break;
case 35: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r3, alu_xor16(get(r3),get(r0)));
pc.add(1);
 return cycles;
} break;
case 36: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r0, alu_xor16(get(r0),get(r1)));
pc.add(1);
 return cycles;
} break;
case 37: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r1, alu_xor16(get(r1),get(r1)));
pc.add(1);
 return cycles;
} break;
case 38: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r2, alu_xor16(get(r2),get(r1)));
pc.add(1);
 return cycles;
} break;
case 39: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r3, alu_xor16(get(r3),get(r1)));
pc.add(1);
 return cycles;
} break;
case 40: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r0, alu_xor16(get(r0),get(r2)));
pc.add(1);
 return cycles;
} break;
case 41: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r1, alu_xor16(get(r1),get(r2)));
pc.add(1);
 return cycles;
} break;
case 42: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r2, alu_xor16(get(r2),get(r2)));
pc.add(1);
 return cycles;
} break;
case 43: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r3, alu_xor16(get(r3),get(r2)));
pc.add(1);
 return cycles;
} break;
case 44: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r0, alu_xor16(get(r0),get(r3)));
pc.add(1);
 return cycles;
} break;
case 45: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r1, alu_xor16(get(r1),get(r3)));
pc.add(1);
 return cycles;
} break;
case 46: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r2, alu_xor16(get(r2),get(r3)));
pc.add(1);
 return cycles;
} break;
case 47: {
cycles += 1;
// xor @r,@s;
// Reference:  page 57
set(r3, alu_xor16(get(r3),get(r3)));
pc.add(1);
 return cycles;
} break;
case 48: {
cycles += 1;
// inv @r;
// Reference:  page 22
set(r0, alu_invert16(get(r0)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r0, alu_or16(get(r0),get(r0)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 49: {
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r1, alu_or16(get(r1),get(r0)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 50: {
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r2, alu_or16(get(r2),get(r0)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 51: {
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r3, alu_or16(get(r3),get(r0)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 52: {
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r0, alu_or16(get(r0),get(r1)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 53: {
cycles += 1;
// inv @r;
// Reference:  page 22
set(r1, alu_invert16(get(r1)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r1, alu_or16(get(r1),get(r1)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 54: {
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r2, alu_or16(get(r2),get(r1)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 55: {
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r3, alu_or16(get(r3),get(r1)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 56: {
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r0, alu_or16(get(r0),get(r2)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 57: {
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r1, alu_or16(get(r1),get(r2)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 58: {
cycles += 1;
// inv @r;
// Reference:  page 22
set(r2, alu_invert16(get(r2)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r2, alu_or16(get(r2),get(r2)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 59: {
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r3, alu_or16(get(r3),get(r2)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 60: {
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r0, alu_or16(get(r0),get(r3)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 61: {
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r1, alu_or16(get(r1),get(r3)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 62: {
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r2, alu_or16(get(r2),get(r3)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 63: {
cycles += 1;
// inv @r;
// Reference:  page 22
set(r3, alu_invert16(get(r3)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
cycles += 1;
// or @r,@s;
// Reference:  page 40
set(r3, alu_or16(get(r3),get(r3)));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 64: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r0,alu_add_u16u16c(get(r0),get(r0)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 65: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r1,alu_add_u16u16c(get(r1),get(r0)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 66: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r2,alu_add_u16u16c(get(r2),get(r0)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 67: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r3,alu_add_u16u16c(get(r3),get(r0)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 68: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r0,alu_add_u16u16c(get(r0),get(r1)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 69: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r1,alu_add_u16u16c(get(r1),get(r1)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 70: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r2,alu_add_u16u16c(get(r2),get(r1)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 71: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r3,alu_add_u16u16c(get(r3),get(r1)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 72: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r0,alu_add_u16u16c(get(r0),get(r2)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 73: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r1,alu_add_u16u16c(get(r1),get(r2)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 74: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r2,alu_add_u16u16c(get(r2),get(r2)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 75: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r3,alu_add_u16u16c(get(r3),get(r2)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 76: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r0,alu_add_u16u16c(get(r0),get(r3)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 77: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r1,alu_add_u16u16c(get(r1),get(r3)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 78: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r2,alu_add_u16u16c(get(r2),get(r3)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 79: {
cycles += 1;
// add @r,@s;
// Reference:  page 5
set(r3,alu_add_u16u16c(get(r3),get(r3)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 80: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r0, alu_add_u16u16c(get(r0),lit(2)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 81: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r1, alu_add_u16u16c(get(r1),lit(2)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 82: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r2, alu_add_u16u16c(get(r2),lit(2)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 83: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r3, alu_add_u16u16c(get(r3),lit(2)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 84: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r0, alu_add_u16u16c(get(r0),lit(1)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 85: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r1, alu_add_u16u16c(get(r1),lit(1)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 86: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r2, alu_add_u16u16c(get(r2),lit(1)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 87: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r3, alu_add_u16u16c(get(r3),lit(1)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 88: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r0, alu_add_u16u16c(get(r0),lit(-2)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 89: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r1, alu_add_u16u16c(get(r1),lit(-2)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 90: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r2, alu_add_u16u16c(get(r2),lit(-2)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 91: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r3, alu_add_u16u16c(get(r3),lit(-2)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 92: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r0, alu_add_u16u16c(get(r0),lit(-1)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 93: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r1, alu_add_u16u16c(get(r1),lit(-1)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 94: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r2, alu_add_u16u16c(get(r2),lit(-1)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 95: {
cycles += 1;
// addq @r,#@q;
// Reference:  page 7
set(r3, alu_add_u16u16c(get(r3),lit(-1)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 96: {
cycles += 1;
// neg @r;
// Reference:  page 37
set(r0, alu_neg16(get(r0)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r0, alu_add_u16u16c(get(r0),-get(r0)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 97: {
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r1, alu_add_u16u16c(get(r1),-get(r0)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 98: {
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r2, alu_add_u16u16c(get(r2),-get(r0)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 99: {
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r3, alu_add_u16u16c(get(r3),-get(r0)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 100: {
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r0, alu_add_u16u16c(get(r0),-get(r1)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 101: {
cycles += 1;
// neg @r;
// Reference:  page 37
set(r1, alu_neg16(get(r1)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r1, alu_add_u16u16c(get(r1),-get(r1)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 102: {
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r2, alu_add_u16u16c(get(r2),-get(r1)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 103: {
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r3, alu_add_u16u16c(get(r3),-get(r1)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 104: {
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r0, alu_add_u16u16c(get(r0),-get(r2)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 105: {
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r1, alu_add_u16u16c(get(r1),-get(r2)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 106: {
cycles += 1;
// neg @r;
// Reference:  page 37
set(r2, alu_neg16(get(r2)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r2, alu_add_u16u16c(get(r2),-get(r2)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 107: {
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r3, alu_add_u16u16c(get(r3),-get(r2)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 108: {
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r0, alu_add_u16u16c(get(r0),-get(r3)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 109: {
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r1, alu_add_u16u16c(get(r1),-get(r3)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 110: {
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r2, alu_add_u16u16c(get(r2),-get(r3)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 111: {
cycles += 1;
// neg @r;
// Reference:  page 37
set(r3, alu_neg16(get(r3)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
cycles += 1;
// sub @r,@s;
// Reference:  page 52
set(r3, alu_add_u16u16c(get(r3),-get(r3)));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 112: {
cycles += 1;
// abs @r;
// Reference:  page 4
set(r0,alu_abs16(get(r0)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r0),get(r0));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 113: {
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r1),get(r0));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 114: {
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r2),get(r0));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 115: {
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r3),get(r0));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 116: {
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r0),get(r1));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 117: {
cycles += 1;
// abs @r;
// Reference:  page 4
set(r1,alu_abs16(get(r1)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r1),get(r1));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 118: {
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r2),get(r1));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 119: {
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r3),get(r1));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 120: {
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r0),get(r2));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 121: {
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r1),get(r2));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 122: {
cycles += 1;
// abs @r;
// Reference:  page 4
set(r2,alu_abs16(get(r2)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r2),get(r2));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 123: {
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r3),get(r2));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 124: {
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r0),get(r3));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 125: {
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r1),get(r3));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 126: {
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r2),get(r3));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 127: {
cycles += 1;
// abs @r;
// Reference:  page 4
set(r3,alu_abs16(get(r3)));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
cycles += 1;
// cmp @r,@s;
// Reference:  page 19
alu_cmp16(get(r3),get(r3));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 128: {
cycles += 2;
// ld.w @r,(@s);
// Reference:  page 28
set(r0, read16(get(r2)));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 129: {
cycles += 2;
// ld.w @r,(@s);
// Reference:  page 28
set(r1, read16(get(r2)));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 130: {
cycles += 2;
// ld.w @r,(@s);
// Reference:  page 28
set(r0, read16(get(r3)));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 131: {
cycles += 2;
// ld.w @r,(@s);
// Reference:  page 28
set(r1, read16(get(r3)));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 132: {
cycles += 2;
// ld.b @r,(@s);
// Reference:  page 28
set(r0, read8(get(r2)));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 133: {
cycles += 2;
// ld.b @r,(@s);
// Reference:  page 28
set(r1, read8(get(r2)));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 134: {
cycles += 2;
// ld.b @r,(@s);
// Reference:  page 28
set(r0, read8(get(r3)));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 135: {
cycles += 2;
// ld.b @r,(@s);
// Reference:  page 28
set(r1, read8(get(r3)));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 136: {
cycles += 2;
// st.w (@s),@r;
// Reference:  page 28
write16((get(r2)),get(r0));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 137: {
cycles += 2;
// st.w (@s),@r;
// Reference:  page 28
write16((get(r2)),get(r1));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 138: {
cycles += 2;
// st.w (@s),@r;
// Reference:  page 28
write16((get(r3)),get(r0));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 139: {
cycles += 2;
// st.w (@s),@r;
// Reference:  page 28
write16((get(r3)),get(r1));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 140: {
cycles += 2;
// st.b (@s),@r;
// Reference:  page 28
write8(get(r2),get(r0));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 141: {
cycles += 2;
// st.b (@s),@r;
// Reference:  page 28
write8(get(r2),get(r1));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 142: {
cycles += 2;
// st.b (@s),@r;
// Reference:  page 28
write8(get(r3),get(r0));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 143: {
cycles += 2;
// st.b (@s),@r;
// Reference:  page 28
write8(get(r3),get(r1));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 144: {
cycles += 2;
// ld.w @s,(@r++);
// Reference:  page 29
set(r0, read16(get(r2)));
set(r2, alu_add_u16u16c(get(r2),lit(2)));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 145: {
cycles += 2;
// ld.w @s,(@r++);
// Reference:  page 29
set(r1, read16(get(r2)));
set(r2, alu_add_u16u16c(get(r2),lit(2)));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 146: {
cycles += 2;
// ld.w @s,(@r++);
// Reference:  page 29
set(r0, read16(get(r3)));
set(r3, alu_add_u16u16c(get(r3),lit(2)));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 147: {
cycles += 2;
// ld.w @s,(@r++);
// Reference:  page 29
set(r1, read16(get(r3)));
set(r3, alu_add_u16u16c(get(r3),lit(2)));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 148: {
cycles += 2;
// ld.b @s,(@r++);
// Reference:  page 29
set(r0, read8(get(r2)));
set(r2, alu_add_u16u16c(get(r2),lit(1)));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 149: {
cycles += 2;
// ld.b @s,(@r++);
// Reference:  page 29
set(r1, read8(get(r2)));
set(r2, alu_add_u16u16c(get(r2),lit(1)));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 150: {
cycles += 2;
// ld.b @s,(@r++);
// Reference:  page 29
set(r0, read8(get(r3)));
set(r3, alu_add_u16u16c(get(r3),lit(1)));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 151: {
cycles += 2;
// ld.b @s,(@r++);
// Reference:  page 29
set(r1, read8(get(r3)));
set(r3, alu_add_u16u16c(get(r3),lit(1)));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 152: {
cycles += 2;
// st.w (@r++),@s;
// Reference:  page 29
write16(get(r2),get(r0));
set(r2, alu_add_u16u16c(get(r2),lit(2)));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 153: {
cycles += 2;
// st.w (@r++),@s;
// Reference:  page 29
write16(get(r2),get(r1));
set(r2, alu_add_u16u16c(get(r2),lit(2)));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 154: {
cycles += 2;
// st.w (@r++),@s;
// Reference:  page 29
write16(get(r3),get(r0));
set(r3, alu_add_u16u16c(get(r3),lit(2)));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 155: {
cycles += 2;
// st.w (@r++),@s;
// Reference:  page 29
write16(get(r3),get(r1));
set(r3, alu_add_u16u16c(get(r3),lit(2)));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 156: {
cycles += 2;
// st.b (@r++),@s;
// Reference:  page 29
write8(get(r2),get(r0));
set(r2, alu_add_u16u16c(get(r2),lit(1)));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 157: {
cycles += 2;
// st.b (@r++),@s;
// Reference:  page 29
write8(get(r2),get(r1));
set(r2, alu_add_u16u16c(get(r2),lit(1)));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 158: {
cycles += 2;
// st.b (@r++),@s;
// Reference:  page 29
write8(get(r3),get(r0));
set(r3, alu_add_u16u16c(get(r3),lit(1)));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 159: {
cycles += 2;
// st.b (@r++),@s;
// Reference:  page 29
write8(get(r3),get(r1));
set(r3, alu_add_u16u16c(get(r3),lit(1)));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 160: {
cycles += 2;
// ld.w @r, (SP,@n);
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
set(r0, read16(get(tmp16)));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 161: {
cycles += 2;
// ld.w @r, (SP,@n);
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
set(r1, read16(get(tmp16)));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 162: {
cycles += 2;
// ld.w @r, (SP,@n);
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
set(r2, read16(get(tmp16)));
computeFlags16(get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 163: {
cycles += 2;
// ld.w @r, (SP,@n);
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
set(r3, read16(get(tmp16)));
computeFlags16(get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 164: {
cycles += 2;
// ld.b @r, (SP,@n);
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
set(r0, read8(get(tmp16)));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 165: {
cycles += 2;
// ld.b @r, (SP,@n);
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
set(r1, read8(get(tmp16)));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 166: {
cycles += 2;
// ld.b @r, (SP,@n);
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
set(r2, read8(get(tmp16)));
computeFlags16(get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 167: {
cycles += 2;
// ld.b @r, (SP,@n);
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
set(r3, read8(get(tmp16)));
computeFlags16(get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 168: {
cycles += 2;
// st.w (SP,@n), @r;
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
write16(get(tmp16), get(r0));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 169: {
cycles += 2;
// st.w (SP,@n), @r;
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
write16(get(tmp16), get(r1));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 170: {
cycles += 2;
// st.w (SP,@n), @r;
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
write16(get(tmp16), get(r2));
computeFlags16(get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 171: {
cycles += 2;
// st.w (SP,@n), @r;
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
write16(get(tmp16), get(r3));
computeFlags16(get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 172: {
cycles += 2;
// st.b (SP,@n), @r;
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
write8(get(tmp16), get(r0));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 173: {
cycles += 2;
// st.b (SP,@n), @r;
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
write8(get(tmp16), get(r1));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 174: {
cycles += 2;
// st.b (SP,@n), @r;
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
write8(get(tmp16), get(r2));
computeFlags16(get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 175: {
cycles += 2;
// st.b (SP,@n), @r;
// Reference:  page 30
set(tmp16, alu_add_u16u8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
write8(get(tmp16), get(r3));
computeFlags16(get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 176: {
cycles += 2;
// ld.w @r,@n;
// Reference:  page 31
set(r0,read16(lit(read16(pc.getUnsigned() + (1)))));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 177: {
cycles += 2;
// ld.w @r,@n;
// Reference:  page 31
set(r1,read16(lit(read16(pc.getUnsigned() + (1)))));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 178: {
cycles += 2;
// ld.w @r,@n;
// Reference:  page 31
set(r2,read16(lit(read16(pc.getUnsigned() + (1)))));
computeFlags16(get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 179: {
cycles += 2;
// ld.w @r,@n;
// Reference:  page 31
set(r3,read16(lit(read16(pc.getUnsigned() + (1)))));
computeFlags16(get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 180: {
cycles += 3;
// ld.b @r,@n;
// Reference:  page 31
set(r0,read8(lit(read16(pc.getUnsigned() + (1)))));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 181: {
cycles += 3;
// ld.b @r,@n;
// Reference:  page 31
set(r1,read8(lit(read16(pc.getUnsigned() + (1)))));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 182: {
cycles += 3;
// ld.b @r,@n;
// Reference:  page 31
set(r2,read8(lit(read16(pc.getUnsigned() + (1)))));
computeFlags16(get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 183: {
cycles += 3;
// ld.b @r,@n;
// Reference:  page 31
set(r3,read8(lit(read16(pc.getUnsigned() + (1)))));
computeFlags16(get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 184: {
cycles += 2;
// st.w @n, @r;
// Reference:  page 31
write16(lit(read16(pc.getUnsigned() + (1))),get(r0));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 185: {
cycles += 2;
// st.w @n, @r;
// Reference:  page 31
write16(lit(read16(pc.getUnsigned() + (1))),get(r1));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 186: {
cycles += 2;
// st.w @n, @r;
// Reference:  page 31
write16(lit(read16(pc.getUnsigned() + (1))),get(r2));
computeFlags16(get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 187: {
cycles += 2;
// st.w @n, @r;
// Reference:  page 31
write16(lit(read16(pc.getUnsigned() + (1))),get(r3));
computeFlags16(get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 188: {
cycles += 2;
// st.b @n,@r;
// Reference:  page 31
write8(lit(read16(pc.getUnsigned() + (1))),get(r0));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 189: {
cycles += 2;
// st.b @n,@r;
// Reference:  page 31
write8(lit(read16(pc.getUnsigned() + (1))),get(r1));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 190: {
cycles += 2;
// st.b @n,@r;
// Reference:  page 31
write8(lit(read16(pc.getUnsigned() + (1))),get(r2));
computeFlags16(get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 191: {
cycles += 2;
// st.b @n,@r;
// Reference:  page 31
write8(lit(read16(pc.getUnsigned() + (1))),get(r3));
computeFlags16(get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 192: {
cycles += 3;
// pop @r;
// Reference:  page 42
set(r0, read16(sp));
set(sp, alu_add_u16u16(get(sp),lit(2)));
pc.add(1);
 return cycles;
} break;
case 193: {
cycles += 3;
// pop @r;
// Reference:  page 42
set(r1, read16(sp));
set(sp, alu_add_u16u16(get(sp),lit(2)));
pc.add(1);
 return cycles;
} break;
case 194: {
cycles += 3;
// pop @r;
// Reference:  page 42
set(r2, read16(sp));
set(sp, alu_add_u16u16(get(sp),lit(2)));
pc.add(1);
 return cycles;
} break;
case 195: {
cycles += 3;
// pop @r;
// Reference:  page 42
set(r3, read16(sp));
set(sp, alu_add_u16u16(get(sp),lit(2)));
pc.add(1);
 return cycles;
} break;
case 196: {
cycles += 3;
// pop PS;
// Reference:  page 42
set(ps, read8(sp));
set(sp, alu_add_u16u16(get(sp),lit(1)));
pc.add(1);
 return cycles;
} break;
case 197: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 198: {
cycles += 4;
// ret;
// Reference:  page 44
pc.assign(read16(sp)-1);
sp.assign(alu_add_u16u16(sp,2));
pc.add(1);
 return cycles;
} break;
case 199: {
cycles += 5;
// reti;
// Reference:  page 45
ps.assign(read8(sp));
sp.assign(alu_add_u16u16(sp,1));
pc.assign(read16(sp)-1);
sp.assign(alu_add_u16u16(sp,2));
affectFlagI();
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 200: {
cycles += 3;
// push @r;
// Reference:  page 42
set(sp, alu_add_u16u16(get(sp),lit(-2)));
write16(get(sp), get(r0));
pc.add(1);
 return cycles;
} break;
case 201: {
cycles += 3;
// push @r;
// Reference:  page 42
set(sp, alu_add_u16u16(get(sp),lit(-2)));
write16(get(sp), get(r1));
pc.add(1);
 return cycles;
} break;
case 202: {
cycles += 3;
// push @r;
// Reference:  page 42
set(sp, alu_add_u16u16(get(sp),lit(-2)));
write16(get(sp), get(r2));
pc.add(1);
 return cycles;
} break;
case 203: {
cycles += 3;
// push @r;
// Reference:  page 42
set(sp, alu_add_u16u16(get(sp),lit(-2)));
write16(get(sp), get(r3));
pc.add(1);
 return cycles;
} break;
case 204: {
cycles += 2;
// push PS;
// Reference:  page 42
set(sp, alu_add_u16u16(get(sp),lit(-1)));
write8(get(sp), get(ps));
pc.add(1);
 return cycles;
} break;
case 205: {
cycles += 6;
// trap;
// Reference:  page 56
mp_trapVector(3);
clearFlagI();
pc.add(1);
 return cycles;
} break;
case 206: {
cycles += 3;
// jsr (r0);
// Reference:  page 25
set(sp, alu_add_u16u16(sp,lit(-2)));;
write16(get(sp),alu_add_u16u16(pc,1));;
set(pc, alu_add_u16u16(r0, -1));
pc.add(1);
 return cycles;
} break;
case 207: {
cycles += 3;
// jsr @n;
// Reference:  page 26
set(sp, alu_add_u16u16(sp,lit(-2)));;
write16(get(sp),alu_add_u16u16(pc,3));;
set(pc, alu_add_u16u16(read16(pc.getUnsigned() + (1)), -3));
pc.add(3);
 return cycles;
cycles += 1;
// pushpop;
// Reference:  page 39
;
pc.add(1);
 return cycles;
} break;
case 208: {
cycles += 3;
// ld.w @r,#@n;
// Reference:  page 27
set(r0,lit(read16(pc.getUnsigned() + (1))));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 209: {
cycles += 3;
// ld.w @r,#@n;
// Reference:  page 27
set(r1,lit(read16(pc.getUnsigned() + (1))));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 210: {
cycles += 3;
// ld.w @r,#@n;
// Reference:  page 27
set(r2,lit(read16(pc.getUnsigned() + (1))));
computeFlags16(get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 211: {
cycles += 3;
// ld.w @r,#@n;
// Reference:  page 27
set(r3,lit(read16(pc.getUnsigned() + (1))));
computeFlags16(get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(3);
 return cycles;
} break;
case 212: {
cycles += 2;
// ld.b @r, #@n;
// Reference:  page 27
set(r0,lit(read8(pc.getUnsigned() + (1))));
computeFlags16(get(r0));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 213: {
cycles += 2;
// ld.b @r, #@n;
// Reference:  page 27
set(r1,lit(read8(pc.getUnsigned() + (1))));
computeFlags16(get(r1));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 214: {
cycles += 2;
// ld.b @r, #@n;
// Reference:  page 27
set(r2,lit(read8(pc.getUnsigned() + (1))));
computeFlags16(get(r2));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 215: {
cycles += 2;
// ld.b @r, #@n;
// Reference:  page 27
set(r3,lit(read8(pc.getUnsigned() + (1))));
computeFlags16(get(r3));
clearFlagV();
clearFlagC();
affectFlagN();
affectFlagZ();
pc.add(2);
 return cycles;
} break;
case 216: {
cycles += 0;
// LSL;
// Reference:  page 32
// Reference: This is all shifts, logical and arithmetic
// (extended instruction: This should return d8_ext();
set(pc, alu_add_u16u16(get(pc), lit(1)));;
return lsl_ext("'r0'", r0);;
pc.add(1);
 return cycles;
} break;
case 217: {
cycles += 0;
// LSL;
// Reference:  page 32
// Reference: This is all shifts, logical and arithmetic
// (extended instruction: This should return d9_ext();
set(pc, alu_add_u16u16(get(pc), lit(1)));;
return lsl_ext("'r1'", r1);;
pc.add(1);
 return cycles;
} break;
case 218: {
cycles += 0;
// LSL;
// Reference:  page 32
// Reference: This is all shifts, logical and arithmetic
// (extended instruction: This should return da_ext();
set(pc, alu_add_u16u16(get(pc), lit(1)));;
return lsl_ext("'r2'", r2);;
pc.add(1);
 return cycles;
} break;
case 219: {
cycles += 0;
// LSL;
// Reference:  page 32
// Reference: This is all shifts, logical and arithmetic
// (extended instruction: This should return db_ext();
set(pc, alu_add_u16u16(get(pc), lit(1)));;
return lsl_ext("r3", r3);;
pc.add(1);
 return cycles;
} break;
case 220: {
cycles += 0;
// bchg;
// Reference:  page 15
// (extended instruction: This should return dc_ext();
set(pc, alu_add_u16u16(get(pc), lit(1)));;
return bits_ext("'r0'", r0);;
pc.add(1);
 return cycles;
} break;
case 221: {
cycles += 0;
// bchg;
// Reference:  page 15
// (extended instruction: This should return dd_ext();
set(pc, alu_add_u16u16(get(pc), lit(1)));;
return bits_ext("'r1'", r1);;
pc.add(1);
 return cycles;
} break;
case 222: {
cycles += 0;
// bchg;
// Reference:  page 15
// (extended instruction: This should return de_ext();
set(pc, alu_add_u16u16(get(pc), lit(1)));;
return bits_ext("r2'", r2);;
pc.add(1);
 return cycles;
} break;
case 223: {
cycles += 0;
// bchg;
// Reference:  page 15
// (extended instruction: This should return df_ext();
set(pc, alu_add_u16u16(get(pc), lit(1)));;
return bits_ext("'r3'", r3);;
pc.add(1);
 return cycles;
} break;
case 224: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 225: {
cycles += 2;
// buc @n;
// Reference:  page 13
if ((getFlagU() == 0)) {
set(pc, alu_add_u16s8(pc,lit(read8(pc.getUnsigned() + (1)))));
cycles += 1;
}
pc.add(2);
 return cycles;
cycles += 2;
// bus @n;
// Reference:  page 13
if ((getFlagU() == 1)) {
set(pc, alu_add_u16s8(pc,lit(read8(pc.getUnsigned() + (1)))));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 226: {
cycles += 2;
// bhi @n;
// Reference:  page 13
if ((getFlagC() == 0) && (getFlagZ() == 0)) {
set(pc, alu_add_u16s8(pc,lit(read8(pc.getUnsigned() + (1)))));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 227: {
cycles += 2;
// blo @n;
// Reference:  page 13
if ((getFlagC() == 1)||(getFlagZ() == 1)) {
set(pc, alu_add_u16s8(pc,lit(read8(pc.getUnsigned() + (1)))));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 228: {
cycles += 2;
// bcc @n;
// Reference:  page 13
if ((getFlagC() == 0)) {
set(pc, alu_add_u16s8(pc,lit(read8(pc.getUnsigned() + (1)))));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 229: {
cycles += 2;
// bcs @n;
// Reference:  page 13
if ((getFlagC() == 1)) {
set(pc, alu_add_u16s8(pc,lit(read8(pc.getUnsigned() + (1)))));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 230: {
cycles += 2;
// bne @n;
// Reference:  page 13
if ((getFlagZ() == 0)) {
set(pc, alu_add_u16s8(pc,lit(read8(pc.getUnsigned() + (1)))));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 231: {
cycles += 2;
// beq @n;
// Reference:  page 13
if ((getFlagZ() == 1)) {
set(pc, alu_add_u16s8(pc,lit(read8(pc.getUnsigned() + (1)))));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 232: {
cycles += 2;
// bvc @n;
// Reference:  page 13
if ((getFlagV() == 0)) {
set(pc, alu_add_u16s8(pc,lit(read8(pc.getUnsigned() + (1)))));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 233: {
cycles += 2;
// bvs @n;
// Reference:  page 13
if ((getFlagV() == 1)) {
set(pc, alu_add_u16s8(pc,lit(read8(pc.getUnsigned() + (1)))));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 234: {
cycles += 2;
// bpl @n;
// Reference:  page 13
if ((getFlagN() == 0)) {
set(pc, alu_add_u16s8(pc,lit(read8(pc.getUnsigned() + (1)))));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 235: {
cycles += 2;
// bmi @n;
// Reference:  page 13
if ((getFlagN() == 1)) {
set(pc, alu_add_u16s8(pc,lit(read8(pc.getUnsigned() + (1)))));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 236: {
cycles += 2;
// bge @n;
// Reference:  page 13
if (((getFlagN() == 1)&&(getFlagV() == 1))||((getFlagN() == 0)&&(getFlagV() == 0))) {
set(pc, alu_add_u16s8(pc,lit(read8(pc.getUnsigned() + (1)))));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 237: {
cycles += 2;
// blt @n;
// Reference:  page 13
if (((getFlagN() == 1)&&(getFlagV() == 0))||((getFlagN() == 0)&&(getFlagV() == 1))) {
set(pc, alu_add_u16s8(pc,lit(read8(pc.getUnsigned() + (1)))));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 238: {
cycles += 2;
// bgt @n;
// Reference:  page 13
if (((getFlagN() == 1)&&(getFlagV() == 1)&&(getFlagZ() == 0))||((getFlagN() == 0)&&(getFlagV() == 0)&&(getFlagZ() == 0))) {
pc.assign(alu_add_u16u16(alu_add_u16s8(pc,read8(pc.getUnsigned() + (1))), 0));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 239: {
cycles += 2;
// ble @n;
// Reference:  page 13
if (((getFlagZ() == 1))||((getFlagN() == 1)&&(getFlagV() == 0))||((getFlagN() == 0)&&(getFlagV() == 1))) {
pc.assign(alu_add_u16u16(alu_add_u16s8(pc,read8(pc.getUnsigned() + (1))), 0));
cycles += 1;
}
pc.add(2);
 return cycles;
} break;
case 240: {
cycles += 1;
// move r0,sp;
// Reference:  page 35
set(r0,get(sp));
pc.add(1);
 return cycles;
} break;
case 241: {
cycles += 1;
// move sp,r0;
// Reference:  page 35
set(sp,get(r0));
pc.add(1);
 return cycles;
} break;
case 242: {
cycles += 2;
// JMP (r0);
// Reference:  page 23
set(pc, alu_add_u16u16(r0, -1));
pc.add(1);
 return cycles;
} break;
case 243: {
cycles += 4;
// JMP @n;
// Reference:  page 24
set(pc, alu_add_u16u16(read16(pc.getUnsigned() + (1)), -3));
pc.add(3);
 return cycles;
} break;
case 244: {
cycles += 1;
// and PS,@n;
// Reference:  page 9
set(ps,alu_and16(get(ps),lit(read8(pc.getUnsigned() + (1)))));
affectFlagI();
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(2);
 return cycles;
} break;
case 245: {
cycles += 2;
// or PS,#n;
// Reference:  page 41
set(ps, alu_or16(get(ps),lit(read7(pc.getUnsigned() + (1)))));
affectFlagI();
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 246: {
cycles += 1;
// add sp,#n;
// Reference:  page 6
set(sp,alu_add_u16s8(get(sp),lit(read8(pc.getUnsigned() + (1)))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(2);
 return cycles;
} break;
case 247: {
cycles += 18;
// sqrt;
// Reference:  page 50
alu_sqrt();
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 248: {
cycles += 1;
// mulu;
// Reference:  page 35
alu_mulu();
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 249: {
cycles += 1;
// muls;
// Reference:  page 35
alu_muls();
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 250: {
cycles += 18;
// div.u;
// Reference:  page 20
alu_divu();
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 251: {
cycles += 19;
// div.s;
// Reference:  page 20
alu_divs();
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 252: {
cycles += 1;
// addx r0,r1;
// Reference:  page 8
set(r0, alu_add_u16u16c(get(r0),get(r1),getFlagC()));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 253: {
cycles += 1;
// subx r0,r1;
// Reference:  page 53
set(r0, alu_add_u16u16c(get(r0),-get(r1), -getFlagC()));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 254: {
cycles += 1;
// negx r0;
// Reference:  page 38
set(r0, alu_add_u16u16c(-get(r0), -getFlagC()));
clearFlagN();
clearFlagZ();
clearFlagV();
clearFlagX();
clearFlagC();
pc.add(1);
 return cycles;
} break;
case 255: {
cycles += 1;
// NOP;
// Reference:  page 39
;
pc.add(1);
 return cycles;
} break;
}
return 1;
}
// Writing from instruction block:
// /emf/res/devices/megaprocessor/mp_lsl.xml
int lsl_ext(const char *pName, emfNumber<uint16_t>& thereg) {
int bit;  /* of type i8 */
int opcode = fetch8(pc);  /* of type i8 */
int cycles = 1;  /* of type i8 */
switch (opcode) {
case 0: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 1: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 2: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 3: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32
int r = alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0)))));
// printf("%s:(%d): the reg was %d r = %d r0 = %d\n", pName, &thereg, get(thereg), r, get(r0));

set(thereg, r);
// printf("%s:(%d): the reg now is %d r0 = %d\n", pName, &r0, get(thereg), get(r0));

// // set(r0, r);
// printf("%s:(%d): the reg now is %d r0 = %d\n", pName, &r0, get(thereg), get(r0));
// 'r0':(106244894): the reg was 32 r = 256 r0 = 32
// 'r0':(106244894): the reg now is 256 r0 = 32

affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 4: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32
set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 5: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32
set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 6: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32
set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 7: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32
set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 8: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32
set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 9: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32
set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 10: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 11: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 12: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 13: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 14: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 15: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 16: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 17: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 18: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 19: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 20: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 21: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 22: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 23: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 24: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 25: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 26: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 27: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 28: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 29: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 30: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 31: {
cycles += 10;
// lsl @r,#@n-16
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 32: {
cycles += 10;
// lsl @r,@s
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(get(r0))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 33: {
cycles += 10;
// lsl @r,@s
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(get(r1))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 34: {
cycles += 10;
// lsl @r,@s
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(get(r2))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 35: {
cycles += 10;
// lsl @r,@s
// Reference:  page 32

set(thereg, alu_lsl16(get(thereg), alu_as_s5(get(r3))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 36: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 37: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 38: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 39: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 40: {
cycles += 10;
// lsl.wt @r,@s
// Reference:  page 32
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_lsl16wt(thereg, get(thereg), alu_as_s5(reg(r0))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 41: {
cycles += 10;
// lsl.wt @r,@s
// Reference:  page 32
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_lsl16wt(thereg, get(thereg), alu_as_s5(reg(r1))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 42: {
cycles += 10;
// lsl.wt @r,@s
// Reference:  page 32
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_lsl16wt(thereg, get(thereg), alu_as_s5(reg(r2))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 43: {
cycles += 10;
// lsl.wt @r,@s
// Reference:  page 32
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_lsl16wt(thereg, get(thereg), alu_as_s5(reg(r3))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 44: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 45: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 46: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 47: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 48: {
cycles += 10;
// lsr @r,@s
// Reference:  page 32

set(thereg, alu_lsr16(get(thereg), alu_as_s5(reg(r0))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 49: {
cycles += 10;
// lsr @r,@s
// Reference:  page 32

set(thereg, alu_lsr16(get(thereg), alu_as_s5(reg(r1))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 50: {
cycles += 10;
// lsr @r,@s
// Reference:  page 32

set(thereg, alu_lsr16(get(thereg), alu_as_s5(reg(r2))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 51: {
cycles += 10;
// lsr @r,@s
// Reference:  page 32

set(thereg, alu_lsr16(get(thereg), alu_as_s5(reg(r3))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 52: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 53: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 54: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 55: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 56: {
cycles += 10;
// lsr.wt @r,@s
// Reference:  page 32
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_lsr16wt(thereg, get(thereg), alu_as_s5(reg(r0))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 57: {
cycles += 10;
// lsr.wt @r,@s
// Reference:  page 32
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_lsr16wt(thereg, get(thereg), alu_as_s5(reg(r1))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 58: {
cycles += 10;
// lsr.wt @r,@s
// Reference:  page 32
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_lsr16wt(thereg, get(thereg), alu_as_s5(reg(r2))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 59: {
cycles += 10;
// lsr.wt @r,@s
// Reference:  page 32
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_lsr16wt(thereg, get(thereg), alu_as_s5(reg(r3))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 60: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 61: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 62: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 63: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 64: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 65: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 66: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 67: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 68: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 69: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 70: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 71: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 72: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 73: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 74: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 75: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 76: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 77: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 78: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 79: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 80: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 81: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 82: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 83: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 84: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 85: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 86: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 87: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 88: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 89: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 90: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 91: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 92: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 93: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 94: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 95: {
cycles += 10;
// asl @r,#@n-16
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 96: {
cycles += 10;
// asl @r,@s
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(get(r0))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 97: {
cycles += 10;
// asl @r,@s
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(get(r1))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 98: {
cycles += 10;
// asl @r,@s
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(get(r2))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 99: {
cycles += 10;
// asl @r,@s
// Reference:  page 11

set(thereg, alu_asl16(get(thereg), alu_as_s5(get(r3))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 100: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 101: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 102: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 103: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 104: {
cycles += 1;
// asl.wt @r,@s
// Reference:  page 11
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_asl16wt(thereg, get(thereg), alu_as_s5(reg(r0))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 105: {
cycles += 1;
// asl.wt @r,@s
// Reference:  page 11
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_asl16wt(thereg, get(thereg), alu_as_s5(reg(r1))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 106: {
cycles += 1;
// asl.wt @r,@s
// Reference:  page 11
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_asl16wt(thereg, get(thereg), alu_as_s5(reg(r2))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 107: {
cycles += 1;
// asl.wt @r,@s
// Reference:  page 11
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_asl16wt(thereg, get(thereg), alu_as_s5(reg(r3))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 108: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 109: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 110: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 111: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 112: {
cycles += 1;
// asr @r,@s
// Reference:  page 11

set(thereg, alu_asr16(get(thereg), alu_as_s5(reg(r0))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 113: {
cycles += 1;
// asr @r,@s
// Reference:  page 11

set(thereg, alu_asr16(get(thereg), alu_as_s5(reg(r1))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 114: {
cycles += 1;
// asr @r,@s
// Reference:  page 11

set(thereg, alu_asr16(get(thereg), alu_as_s5(reg(r2))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 115: {
cycles += 1;
// asr @r,@s
// Reference:  page 11

set(thereg, alu_asr16(get(thereg), alu_as_s5(reg(r3))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 116: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 117: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 118: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 119: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 120: {
cycles += 1;
// asr.wt @r,@s
// Reference:  page 1
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_asr16wt(thereg, get(thereg), alu_as_s5(reg(r0))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 121: {
cycles += 1;
// asr.wt @r,@s
// Reference:  page 1
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_asr16wt(thereg, get(thereg), alu_as_s5(reg(r1))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 122: {
cycles += 1;
// asr.wt @r,@s
// Reference:  page 1
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_asr16wt(thereg, get(thereg), alu_as_s5(reg(r2))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 123: {
cycles += 1;
// asr.wt @r,@s
// Reference:  page 1
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_asr16wt(thereg, get(thereg), alu_as_s5(reg(r3))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 124: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 125: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 126: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 127: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 128: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 129: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 130: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 131: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 132: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 133: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 134: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 135: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 136: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 137: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 138: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 139: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 140: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 141: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 142: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 143: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 144: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 145: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 146: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 147: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 148: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 149: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 150: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 151: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 152: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 153: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 154: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 155: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 156: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 157: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 158: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 159: {
cycles += 4;
// rol @r,#@n-16
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 160: {
cycles += 4;
// rol @r,@s
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(get(r0))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 161: {
cycles += 4;
// rol @r,@s
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(get(r1))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 162: {
cycles += 4;
// rol @r,@s
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(get(r2))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 163: {
cycles += 4;
// rol @r,@s
// Reference:  page 46

set(thereg, alu_rol16(get(thereg), alu_as_s5(get(r3))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 164: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 165: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 166: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 167: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 168: {
cycles += 4;
// rol.wt @r,@s
// Reference:  page 46
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_rol16wt(thereg, get(thereg), alu_as_s5(reg(r0))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 169: {
cycles += 4;
// rol.wt @r,@s
// Reference:  page 46
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_rol16wt(thereg, get(thereg), alu_as_s5(reg(r1))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 170: {
cycles += 4;
// rol.wt @r,@s
// Reference:  page 46
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_rol16wt(thereg, get(thereg), alu_as_s5(reg(r2))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 171: {
cycles += 4;
// rol.wt @r,@s
// Reference:  page 46
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_rol16wt(thereg, get(thereg), alu_as_s5(reg(r3))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 172: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 173: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 174: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 175: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 176: {
cycles += 4;
// ror @r,@s
// Reference:  page 46

set(thereg, alu_ror16(get(thereg), alu_as_s5(reg(r0))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 177: {
cycles += 4;
// ror @r,@s
// Reference:  page 46

set(thereg, alu_ror16(get(thereg), alu_as_s5(reg(r1))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 178: {
cycles += 4;
// ror @r,@s
// Reference:  page 46

set(thereg, alu_ror16(get(thereg), alu_as_s5(reg(r2))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 179: {
cycles += 4;
// ror @r,@s
// Reference:  page 46

set(thereg, alu_ror16(get(thereg), alu_as_s5(reg(r3))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 180: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 181: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 182: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 183: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 184: {
cycles += 4;
// ror.wt @r,@s
// Reference:  page 46
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_ror16wt(thereg, get(thereg), alu_as_s5(reg(r0))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 185: {
cycles += 4;
// ror.wt @r,@s
// Reference:  page 46
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_ror16wt(thereg, get(thereg), alu_as_s5(reg(r1))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 186: {
cycles += 4;
// ror.wt @r,@s
// Reference:  page 46
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_ror16wt(thereg, get(thereg), alu_as_s5(reg(r2))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 187: {
cycles += 4;
// ror.wt @r,@s
// Reference:  page 46
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_ror16wt(thereg, get(thereg), alu_as_s5(reg(r3))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 188: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 189: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 190: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 191: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 192: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 193: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 194: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 195: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 196: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 197: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 198: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 199: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 200: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 201: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 202: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 203: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 204: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 205: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 206: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 207: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 208: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 209: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 210: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 211: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 212: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 213: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 214: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 215: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 216: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 217: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 218: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 219: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 220: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 221: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 222: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 223: {
cycles += 4;
// roxl @r,#@n-16
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(lit(read5(pc.getUnsigned() + (0))))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 224: {
cycles += 4;
// roxl @r,@s
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(get(r0))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 225: {
cycles += 4;
// roxl @r,@s
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(get(r1))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 226: {
cycles += 4;
// roxl @r,@s
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(get(r2))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 227: {
cycles += 4;
// roxl @r,@s
// Reference:  page 48

set(thereg, alu_roxl16(get(thereg), alu_as_s5(get(r3))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 228: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 229: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 230: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 231: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 232: {
cycles += 4;
// roxl.wt @r,@s
// Reference:  page 48
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_roxl16wt(thereg, get(thereg), alu_as_s5(reg(r0))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 233: {
cycles += 4;
// roxl.wt @r,@s
// Reference:  page 48
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_roxl16wt(thereg, get(thereg), alu_as_s5(reg(r1))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 234: {
cycles += 4;
// roxl.wt @r,@s
// Reference:  page 48
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_roxl16wt(thereg, get(thereg), alu_as_s5(reg(r2))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 235: {
cycles += 4;
// roxl.wt @r,@s
// Reference:  page 48
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_roxl16wt(thereg, get(thereg), alu_as_s5(reg(r3))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 236: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 237: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 238: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 239: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 240: {
cycles += 4;
// roxr @r,@s
// Reference:  page 48

set(thereg, alu_roxr16(get(thereg), alu_as_s5(reg(r0))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 241: {
cycles += 4;
// roxr @r,@s
// Reference:  page 48

set(thereg, alu_roxr16(get(thereg), alu_as_s5(reg(r1))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 242: {
cycles += 4;
// roxr @r,@s
// Reference:  page 48

set(thereg, alu_roxr16(get(thereg), alu_as_s5(reg(r2))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 243: {
cycles += 4;
// roxr @r,@s
// Reference:  page 48

set(thereg, alu_roxr16(get(thereg), alu_as_s5(reg(r3))));
affectFlagN();
affectFlagZ();
affectFlagV();
affectFlagX();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 244: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 245: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 246: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 247: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 248: {
cycles += 4;
// roxr.wt @r,@s
// Reference:  page 48
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_roxr16wt(thereg, get(thereg), alu_as_s5(reg(r0))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 249: {
cycles += 4;
// roxr.wt @r,@s
// Reference:  page 48
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_roxr16wt(thereg, get(thereg), alu_as_s5(reg(r1))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 250: {
cycles += 4;
// roxr.wt @r,@s
// Reference:  page 48
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_roxr16wt(thereg, get(thereg), alu_as_s5(reg(r2))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 251: {
cycles += 4;
// roxr.wt @r,@s
// Reference:  page 48
// Reference: Weighted stores the number of 1 bits shifted out into RA

set(thereg, alu_roxr16wt(thereg, get(thereg), alu_as_s5(reg(r3))));
clearFlagN();
clearFlagV();
clearFlagX();
affectFlagZ();
affectFlagC();
pc.add(1);
 return cycles;
} break;
case 252: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 253: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 254: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 255: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
}
return 1;
}
// Writing from instruction block:
// /emf/res/devices/megaprocessor/mp_bits.xml
int bits_ext(const char*pName, emfNumber<uint16_t>& thereg) {
int bit;  /* of type i8 */
int opcode = fetch8(pc);  /* of type i8 */
int cycles = 1;  /* of type i8 */
switch (opcode) {
case 0: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 1: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 2: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 3: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 4: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 5: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 6: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 7: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 8: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 9: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 10: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 11: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 12: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 13: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 14: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 15: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 16: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 17: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 18: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 19: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 20: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 21: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 22: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 23: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 24: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 25: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 26: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 27: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 28: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 29: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 30: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 31: {
cycles += 1;
// btst @r,#@n
// Reference:  page 16

alu_btst16(get(thereg), lit(read5(pc.getUnsigned() + (0))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 32: {
cycles += 1;
// btst @r,@s
// Reference:  page 16

alu_btst16(get(thereg), alu_and8(get(r0),0x0f));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 33: {
cycles += 1;
// btst @r,@s
// Reference:  page 16

alu_btst16(get(thereg), alu_and8(get(r1),0x0f));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 34: {
cycles += 1;
// btst @r,@s
// Reference:  page 16

alu_btst16(get(thereg), alu_and8(get(r2),0x0f));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 35: {
cycles += 1;
// btst @r,@s
// Reference:  page 16

alu_btst16(get(thereg), alu_and8(get(r3),0x0f));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 36: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 37: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 38: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 39: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 40: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 41: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 42: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 43: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 44: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 45: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 46: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 47: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 48: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 49: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 50: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 51: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 52: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 53: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 54: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 55: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 56: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 57: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 58: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 59: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 60: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 61: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 62: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 63: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 64: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 65: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 66: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 67: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 68: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 69: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 70: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 71: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 72: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 73: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 74: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 75: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 76: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 77: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 78: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 79: {
cycles += 1;
// bchg @r,#@n
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), lit(read4(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 80: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 81: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 82: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 83: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 84: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 85: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 86: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 87: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 88: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 89: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 90: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 91: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 92: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 93: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 94: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 95: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 96: {
cycles += 1;
// bchg @r,@s
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), alu_and8(get(r0),0x0f)));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 97: {
cycles += 1;
// bchg @r,@s
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), alu_and8(get(r1),0x0f)));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 98: {
cycles += 1;
// bchg @r,@s
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), alu_and8(get(r2),0x0f)));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 99: {
cycles += 1;
// bchg @r,@s
// Reference:  page 15

set(thereg, alu_bchg16(get(thereg), alu_and8(get(r3),0x0f)));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 100: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 101: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 102: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 103: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 104: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 105: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 106: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 107: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 108: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 109: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 110: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 111: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 112: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 113: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 114: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 115: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 116: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 117: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 118: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 119: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 120: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 121: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 122: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 123: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 124: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 125: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 126: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 127: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 128: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 129: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 130: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 131: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 132: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 133: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 134: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 135: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 136: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 137: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 138: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 139: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 140: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 141: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 142: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 143: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 144: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 145: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 146: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 147: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 148: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 149: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 150: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 151: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 152: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 153: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 154: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 155: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 156: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 157: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 158: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 159: {
cycles += 1;
// bclr @r,#@n
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 160: {
cycles += 1;
// bclr @r,@s
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), alu_and8(get(r0),0x0f)));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 161: {
cycles += 1;
// bclr @r,@s
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), alu_and8(get(r1),0x0f)));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 162: {
cycles += 1;
// bclr @r,@s
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), alu_and8(get(r2),0x0f)));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 163: {
cycles += 1;
// bclr @r,@s
// Reference:  page 16

set(thereg, alu_bclr16(get(thereg), alu_and8(get(r3),0x0f)));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 164: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 165: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 166: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 167: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 168: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 169: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 170: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 171: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 172: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 173: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 174: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 175: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 176: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 177: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 178: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 179: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 180: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 181: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 182: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 183: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 184: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 185: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 186: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 187: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 188: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 189: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 190: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 191: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 192: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 193: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 194: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 195: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 196: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 197: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 198: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 199: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 200: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 201: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 202: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 203: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 204: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 205: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 206: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 207: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 208: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 209: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 210: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 211: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 212: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 213: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 214: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 215: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 216: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 217: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 218: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 219: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 220: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 221: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 222: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 223: {
cycles += 1;
// bset @r,#@n
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), lit(read5(pc.getUnsigned() + (0)))));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 224: {
cycles += 1;
// bset @r,@s
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), alu_and8(get(r0),0x0f)));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 225: {
cycles += 1;
// bset @r,@s
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), alu_and8(get(r1),0x0f)));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 226: {
cycles += 1;
// bset @r,@s
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), alu_and8(get(r2),0x0f)));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 227: {
cycles += 1;
// bset @r,@s
// Reference:  page 16

set(thereg, alu_bset16(get(thereg), alu_and8(get(r3),0x0f)));
affectFlagZ();
pc.add(1);
 return cycles;
} break;
case 228: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 229: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 230: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 231: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 232: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 233: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 234: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 235: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 236: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 237: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 238: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 239: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 240: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 241: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 242: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 243: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 244: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 245: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 246: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 247: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 248: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 249: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 250: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 251: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 252: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 253: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 254: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
case 255: {
// Unknown instruction
pc.add(1);
 return cycles;
} break;
}
return 1;
}
// importEmulatorALU

/*
**
** State
**
*/

void getState(MegaState* pState) {
  pState->r0 = r0.getUnsigned();
  pState->r1 = r1.getUnsigned();
  pState->r2 = r2.getUnsigned();
  pState->r3 = r3.getUnsigned();
  pState->pc = pc.getUnsigned();
  pState->sp = sp.getUnsigned();
  pState->ix = ix.getUnsigned();
  pState->iy = iy.getUnsigned();
  pState->ps = ps.getUnsigned();
}
#if 0
function getState() {
gsRegisterR0.assign(getRegisterValueR0());
gsRegisterR1.assign(getRegisterValueR1());
gsRegisterR2.assign(getRegisterValueR2());
gsRegisterR3.assign(getRegisterValueR3());
gsRegisterPC.assign(getRegisterValuePC());
gsRegisterSP.assign(getRegisterValueSP());
gsRegisterIX.assign(getRegisterValueIX());
gsRegisterIY.assign(getRegisterValueIY());
gsRegisterPS.assign(getRegisterValuePS());
  return {
    flags: {
u: getFlagU(),
d: getFlagD(),
c: getFlagC(),
x: getFlagX(),
v: getFlagV(),
z: getFlagZ(),
n: getFlagN(),
i: getFlagI(),
    },

    registers: {
r0: gsRegisterR0 ,
r1: gsRegisterR1 ,
r2: gsRegisterR2 ,
r3: gsRegisterR3 ,
pc: gsRegisterPC ,
sp: gsRegisterSP ,
ix: gsRegisterIX ,
iy: gsRegisterIY ,
ps: gsRegisterPS ,
    },

    state: {
    },
  };
}

function setState(bool newState) {
// registers:
  if (typeof newState.registers.r0 !== typeof undefined) {
    setRegisterValueR0(newState.registers.r0);
}
  if (typeof newState.registers.r1 !== typeof undefined) {
    setRegisterValueR1(newState.registers.r1);
}
  if (typeof newState.registers.r2 !== typeof undefined) {
    setRegisterValueR2(newState.registers.r2);
}
  if (typeof newState.registers.r3 !== typeof undefined) {
    setRegisterValueR3(newState.registers.r3);
}
  if (typeof newState.registers.pc !== typeof undefined) {
    setRegisterValuePC(newState.registers.pc);
}
  if (typeof newState.registers.sp !== typeof undefined) {
    setRegisterValueSP(newState.registers.sp);
}
  if (typeof newState.registers.ix !== typeof undefined) {
    setRegisterValueIX(newState.registers.ix);
}
  if (typeof newState.registers.iy !== typeof undefined) {
    setRegisterValueIY(newState.registers.iy);
}
  if (typeof newState.registers.ps !== typeof undefined) {
    setRegisterValuePS(newState.registers.ps);
}

// Flags:
  if (typeof newState.flags.u !== typeof undefined) {
    changeFlagU(newState.flags.u);
}
  if (typeof newState.flags.d !== typeof undefined) {
    changeFlagD(newState.flags.d);
}
  if (typeof newState.flags.c !== typeof undefined) {
    changeFlagC(newState.flags.c);
}
  if (typeof newState.flags.x !== typeof undefined) {
    changeFlagX(newState.flags.x);
}
  if (typeof newState.flags.v !== typeof undefined) {
    changeFlagV(newState.flags.v);
}
  if (typeof newState.flags.z !== typeof undefined) {
    changeFlagZ(newState.flags.z);
}
  if (typeof newState.flags.n !== typeof undefined) {
    changeFlagN(newState.flags.n);
}
  if (typeof newState.flags.i !== typeof undefined) {
    changeFlagI(newState.flags.i);
}

// state
}


/*
**
** Expose this API
**
*/
  return {
    start,
    reset,
    update,
    getState,
    setState,
    processBytes,
    getRegisterValueR0,
    setRegisterValueR0,
    getRegisterValueR1,
    setRegisterValueR1,
    getRegisterValueR2,
    setRegisterValueR2,
    getRegisterValueR3,
    setRegisterValueR3,
    getRegisterValuePC,
    setRegisterValuePC,
    getRegisterValueSP,
    setRegisterValueSP,
    getRegisterValueIX,
    setRegisterValueIX,
    getRegisterValueIY,
    setRegisterValueIY,
    getRegisterValuePS,
    setRegisterValuePS,
    getRegisterValue,
    setRegisterValue,
    setFlagValue,
  }
  #endif

};
