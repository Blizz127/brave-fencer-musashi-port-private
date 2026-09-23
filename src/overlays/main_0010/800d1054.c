/* MAIN10 resident retail span [800D1054,800D1078), offset 0x2225C at base 800AEDF8. */
#include "psx_types.h"

extern u8 D_8010EDEC[];

s32 func_800D1054(u8 arg0) {
    return *(s32 *)(&D_8010EDEC[arg0 * 12 - 4]);
}
