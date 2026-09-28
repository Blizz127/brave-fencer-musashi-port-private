/* Complete SC02 retail span [80147718,80147788).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80147718 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80013F3C(s32 a0);
extern void func_800126C4(s32 a0, s32 a1);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800123F0(s32 a0, s32 a1);

void func_80147718(s32 a0) {
    s32 s1 = *(s32 *)(a0 + 0x20);
    s32 s0 = s1 + 0x34;
    func_80013F3C(s0);
    func_800126C4(s0, *(s16 *)(s1 + 0x10));
    func_80012558(s0, *(s16 *)(s1 + 0x12));
    func_800123F0(s0, *(s16 *)(s1 + 0x14));
    *(u16 *)(s1 + 0x2C) |= 1;
}
