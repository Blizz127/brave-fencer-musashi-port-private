/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161888 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80161D20(int param_1, u32 param_2);
extern void func_80161D20();

s32 func_80161888(s32 a0, u32 a1)
{
    s32 s0 = a0;
    if (a1 & 1) {
        func_8014C010(s0, 1);
        func_80161D20(s0, *(u16*)(s0 + 0x16E));
        return 1;
    }
    if (a1 & 0x4000) {
        func_8014C010(s0, 1);
        func_80161D20(s0, *(u16*)(s0 + 0x16E));
        return 2;
    }
    if (a1 & 0x2000) {
        func_8014C010(s0, 1);
        func_80161D20(s0, *(u16*)(s0 + 0x16E));
        return 4;
    }
    return 0;
}
