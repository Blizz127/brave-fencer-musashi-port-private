/* MAIN10 resident retail span [800D0F4C,800D0F8C), offset 0x22154 at base 800AEDF8. */
#include "psx_types.h"

s32 func_800D0F8C(u8);
void func_800D0FE0(s32);

s32 func_800D0F4C(u8 arg0) {
    s32 s0 = func_800D0F8C(arg0);

    if (s0 != 0) {
        func_800D0FE0(s0);
        return s0;
    }
    return 0;
}
