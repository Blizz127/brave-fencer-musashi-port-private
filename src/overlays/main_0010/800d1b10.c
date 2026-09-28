/* MAIN10 resident retail span [800D1B10,800D1B80), offset 0x22D18 at base 800AEDF8. */
#include "psx_types.h"

extern u8 D_800B9A10;
extern void func_80029124(s32, s32);
extern void func_8002D4C8(s32, s32);

s32 func_800D1B10(u8 *arg0) {
    func_80029124(0x119, 0);
    func_8002D4C8(4, 0x448);
    func_8002D4C8(4, 0x449);
    func_8002D4C8(4, 0x8ED);
    D_800B9A10 = 0;
    arg0[0x15] = 0;
    arg0[0x14]++;
    return 0;
}
