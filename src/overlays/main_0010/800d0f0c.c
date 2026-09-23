/* MAIN10 resident retail span [800D0F0C,800D0F4C), offset 0x22114 at base 800AEDF8. */
#include "psx_types.h"

void func_800291A0(s32, u8);
void func_800291C8(s32, s16);
extern s16 D_80078EAC;

void func_800D0F0C(s32 arg0, u8 arg1) {
    func_800291A0(arg0, arg1);
    func_800291C8((arg0 << 1) - 0x4A, D_80078EAC);
}
