/* MAIN10 resident retail span [800D11F0,800D128C), offset 0x223F8 at base 800AEDF8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D11F0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_800291B4();
extern s32 func_800291DC(s32 arg0);
extern s16 D_80078EAC;
extern s32 func_800D128C(s32 arg0, s32 arg1);
extern void func_800291A0(s32 arg0, s32 arg1);

s32 func_800D11F0(s32 arg0) {
    s32 s1 = arg0 & 0xFF;
    s32 s2 = s1 + 0x2F;
    s32 s0 = func_800291B4(s2) & 0xFF;
    s32 v0;
    s32 r;

    if (s0 == 0) {
        return 0;
    }

    v0 = (s16)func_800291DC(s1 * 2 + 0x14);
    r = (s16)func_800D128C(s0, (s16)((u16)D_80078EAC - v0));
    if (r > 0) {
        func_800291A0(s2, 0);
    }
    return r;
}
