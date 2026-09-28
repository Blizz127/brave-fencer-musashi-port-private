/* Complete SC02 retail span [80182AB4,80182B64).
 * SC02 820xx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80182AB4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u8 D_800D387C[];
extern u8 D_800D3888[];
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern u8 *func_801290DC(s32 a0, u8 *a1);

s32 func_80182AB4(s32 a0, s16 a1, s32 a2) {
    register s32 ret __asm__("$2");
    u8 *p;
    s32 s0;
    s32 t;

    s0 = func_801290DC(0x34, a0);
    t = s0 + 0x24;
    if (s0 == 0) {
        ret = 0;
        return ret;
    }
    p = *(u32 *)(s0 + 0x20);
    *(u32 *)(p + 0x20) = (u32)&D_800D387C;
    *(u8 *)(p + 0x27) = 0x9C;
    *(u16 *)(p + 0x1A) = a1;
    *(u16 *)(p + 0x18) = a1;
    *(u32 *)(p + 4) = *(u32 *)(p + 4) | 0x50000000;
    __asm__("" ::: "memory");
    *(u32 *)(p + 4) = *(u32 *)(p + 4) | 0x80000000;
    func_80128EA8((s32)p, t, (s32)&D_800D3888);
    ret = s0;
    *(u32 *)(ret + 0x1C) = a2;
    return ret;
}
