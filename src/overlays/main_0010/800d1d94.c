/* MAIN10 resident retail span [800D1D94,800D1DB0), offset 0x22F9C at base 800AEDF8. */
#include "psx_types.h"

extern u16 D_80078E50;

s32 func_800D1D94(void) {
    return (s16)(D_80078E50 & 0xF000);
}
