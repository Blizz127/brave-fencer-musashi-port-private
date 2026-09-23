/* MAIN10 resident retail span [800D1078,800D109C), offset 0x22280 at base 800AEDF8. */
#include "psx_types.h"

extern u8 D_8010EDEC[];

s16 func_800D1078(u8 arg0) {
    return *(s16 *)(&D_8010EDEC[arg0 * 12]);
}
