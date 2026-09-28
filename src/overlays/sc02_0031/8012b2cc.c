/* Complete SC02 retail span [8012B2CC,8012B370); callee of 80181938; C recovery pending */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B2CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80049CAC(s32 a0, s32 a1);

void func_8012B2CC(s32 a0)
{
    s32 a1;
    s32 p;
    s16 v;
    a1 = *(s32 *)(a0 + 0x20);
    if (a1 != 0) {
        func_80049CAC(a1 + 0x10, a1 + 0x34);
        p = *(s32 *)(a0 + 0x20);
        v = *(u16 *)(a0 + 0x6) + *(u16 *)(a0 + 0x50);
        *(s16 *)(p + 0x8) = v;
        *(s32 *)(p + 0x48) = v;
        v = *(u16 *)(a0 + 0xA) + *(u16 *)(a0 + 0x52);
        *(s16 *)(p + 0xA) = v;
        *(s32 *)(p + 0x4C) = v;
        v = *(u16 *)(a0 + 0xE) + *(u16 *)(a0 + 0x54);
        *(s16 *)(p + 0xC) = v;
        *(u16 *)(p + 0x2C) = *(u16 *)(p + 0x2C) | 1;
        *(s32 *)(p + 0x50) = v;
    }
}
