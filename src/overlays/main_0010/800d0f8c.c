/* MAIN10 resident retail span [800D0F8C,800D0FE0), offset 0x22194 at base 800AEDF8. */
#include "psx_types.h"

u8 func_800291B4(s32);

s32 func_800D0F8C(u8 arg0) {
    u32 i;

    for (i = 0x2F; i < 0x3B; i++) {
        if (func_800291B4(i) == arg0) {
            return i;
        }
    }
    return 0;
}
