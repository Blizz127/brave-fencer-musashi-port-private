/* MAIN10 resident retail span [800D17B8,800D185C), offset 0x229C0 at base 800AEDF8. */
#include "psx_types.h"

extern s32 D_800AE6B4;
extern u8 D_800AE6BC;
extern s32 D_80114EA8;
extern s32 D_80159698;
extern void func_800D185C(s32);
extern void func_80011A3C(void);

s32 func_800D17B8(u32 arg0) {
    u32 *s0 = (u32 *)(arg0 & 0x80FFFFFF);
    if (s0 != 0) {
        func_800D185C((s32)s0);
        if (arg0 & 0x01000000) {
            D_800AE6B4 = (s32)&D_80159698;
            D_800AE6BC = 0;
        } else {
            s32 val = *(s32 *)((u32)s0 + 4);
            D_800AE6BC = 0;
            D_80114EA8 = 0;
            D_800AE6B4 = val;
        }

        func_80011A3C();
        return 1;
    }
    return 0;
}




