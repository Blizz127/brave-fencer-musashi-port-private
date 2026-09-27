/* MAIN10 resident retail span [800CF8E4,800CF94C), offset 0x20AEC at base 800AEDF8. */
#include "psx_types.h"

s32 func_800D1714(void);
s32 func_800CFC5C(s32);
s32 func_800CFD68(s32);
void func_800CFDE8(s32);
extern s16 D_800B9A08;

void func_800CF8E4(void) {
    s32 s0;

    s0 = func_800D1714();
    if (func_800CFC5C(s0) == 0 && func_800CFC5C(D_800B9A08) == 0) {
        if (func_800CFD68(s0) != 0) {
            func_800CFDE8(s0);
        }
    }
}
