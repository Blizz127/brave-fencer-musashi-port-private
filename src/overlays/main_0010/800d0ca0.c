/* MAIN10 resident retail span [800D0CA0,800D0CE0), offset 0x21EA8 at base 800AEDF8. */
#include "psx_types.h"

void func_8002D4C8(s32, u16);
extern s32 D_800A654C;
extern s32 D_801151F8;
extern s32 D_80127500;

void func_800D0CA0(u16 arg0) {
    func_8002D4C8(1, arg0);
    D_800A654C = 0;
    D_801151F8 = 3;
    D_80127500 = 3;
}
