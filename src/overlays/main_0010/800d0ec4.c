/* MAIN10 resident retail span [800D0EC4,800D0F0C), offset 0x220CC at base 800AEDF8. */
#include "psx_types.h"

u8 func_800291B4(s32);

s32 func_800D0EC4(void) {
    u32 i;

    for (i = 0x2F; i < 0x3B; i++) {
        if (func_800291B4(i) == 0) {
            return i;
        }
    }
    return 0;
}
