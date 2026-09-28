/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB0C8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80161208();
extern s32 func_800CB170(s32 a0);

void func_800CB0C8(void *a0) {
    extern s32 D_800CC580;
    extern void func_800CB1A0(void);
    extern s32 func_80161208();
    extern void func_80165A78(s32 a0);
    extern void func_80159B3C(void *a0);
    extern s32 func_800CB170(s32 a0);
    s32 v0;
    s32 p;

    p = *(s32 *)((s32)a0 + 0x20);
    *(u16 *)(p + 0x2C) |= 0x20;
    p = *(s32 *)((s32)a0 + 0x20);
    *(s32 *)(p + 0x80) = (s32)&D_800CC580;
    func_800CB1A0();
    *(u32 *)((s32)a0 + 0x44) |= 2;
    v0 = func_80161208((s32)a0);
    if (v0 != 0) {
        func_800CB170((s32)a0);
        return;
    }
    p = *(u8 *)((s32)a0 + 0xBE);
    v0 = p + 0xFF;
    *(u8 *)((s32)a0 + 0xBE) = v0;
    if (p == 0) {
        func_800CB170((s32)a0);
        func_80165A78((s32)a0);
        func_80159B3C(a0);
    }
}
