/* MAIN10 resident retail span [800D1D24,800D1D94), offset 0x22F2C at base 800AEDF8. */
#include "psx_types.h"

extern u16 D_80078E50;
extern u16 D_800B9A0A;
extern u8 D_800B9A11;
extern u16 D_800B9A08;
extern u16 D_800B9A0C;
extern void func_8001C0C8(void);
extern void func_80015310(void);
extern void func_80129258(void);
extern void func_801378F0(void);

void func_800D1D24(void) {
    u16 temp = D_80078E50;

    D_800B9A11 = 1;
    D_800B9A08 = temp;
    D_800B9A0C = D_800B9A0A;
    D_800B9A0A = temp & 0xF000;
    func_8001C0C8();
    func_80015310();
    func_80129258();
    func_801378F0();
}
