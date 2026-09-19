/* MAIN10 resident retail span [800D1754,800D17B8), offset 0x2295C at base 800AEDF8. */
#include "psx_types.h"

extern s32 D_800AE6B0;
extern s32 D_800AE6A8;
extern s32 func_800D17B8(s32);

void func_800D1754(void) {
    s32 *ptr = &D_800AE6A8;
    if (func_800D17B8(D_800AE6B0) == 0) {
        s32 val = *ptr;
        if (val != 0) {
            *ptr = 0;
            D_800AE6B0 = val;
            func_800D17B8(val);
        }
    }
}


