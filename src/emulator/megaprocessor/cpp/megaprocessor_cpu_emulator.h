#pragma once

struct MegaState{
  int r0, r1, r2, r3;
  int pc, sp, ix, iy;
  int ps;
};

// new/alternate format
struct CPUState
{
// Registers
u16 rr0;
u16 rr1;
u16 rr2;
u16 rr3;
u16 rpc;
u16 rsp;
u16 rix;
u16 riy;
u8 rps;
// Flags
bool fU;
bool fD;
bool fC;
bool fX;
bool fV;
bool fZ;
bool fN;
bool fI;
};