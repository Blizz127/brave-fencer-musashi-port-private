/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB3CC - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
#define RotMatrixYXZ func_80049A1C
extern void func_80146C3C(void);

void func_800CB3CC(void *arg0) {
    extern void func_800D2318(void);
    extern void RotMatrixYXZ();
    extern void ApplyMatrixSV();
    extern void func_800D1FC8();
    extern s32 func_800D21C4();
    extern void func_80128EA8();
    extern void func_80146C3C();
    extern u8 D_800CB8FC[];
    extern u8 D_800CB8BC[];
    s16 sp10[8];
    s16 sp20[16];
    s32 p;

    func_800D2318();
    sp10[0] = *(u16 *)((s32)arg0 + 0x12);
    sp10[1] = *(u16 *)((s32)arg0 + 0x16);
    sp10[2] = 0;
    RotMatrixYXZ(sp10, sp20);
    sp10[1] = -8;
    sp10[0] = 0;
    sp10[2] = -0x10;
    ApplyMatrixSV(sp20, sp10, sp10);
    *(s32 *)((s32)arg0 + 0x4C) = (s16)(*(u16 *)((s32)arg0 + 6) = *(u16 *)((s32)arg0 + 6) + (u16)sp10[0]);
    *(s32 *)((s32)arg0 + 0x50) = (s16)(*(u16 *)((s32)arg0 + 0xA) = *(u16 *)((s32)arg0 + 0xA) + (u16)sp10[1]);
    *(s32 *)((s32)arg0 + 0x54) = (s16)(*(u16 *)((s32)arg0 + 0xE) = *(u16 *)((s32)arg0 + 0xE) + (u16)sp10[2]);
    func_800D1FC8(arg0, 6);
    p = func_800D21C4(arg0, D_800CB8FC, 0x19);
    if (p != 0) {
        *(s32 *)((s32)arg0 + 0x20) = p;
        *(u16 *)(p + 0x1A) = 0x3000;
        *(u16 *)(p + 0x18) = 0x3000;
        *(s32 *)(p + 4) |= 0x50000000;
        func_80128EA8(p, (s32)arg0 + 0x24, D_800CB8BC);
        *(u16 *)((s32)arg0 + 2) = *(u16 *)((s32)arg0 + 2) + 1;
    } else {
        ((void (*)(s32))func_80146C3C)(arg0);
    }
}
