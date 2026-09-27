/* MAIN10 resident retail span [800D10C8,800D10EC), offset 0x222D0 at base 800AEDF8. */
#include "psx_types.h"

extern u8 D_8010EDEC[];

s16 func_800D10C8(u8 arg0) {
    return *(s16 *)(&D_8010EDEC[arg0 * 12 + 2]);
}
