/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80144988 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_80144988(s32 a0) {
    s32 t;
    *(u16*)(a0 + 0xA) = *(u16*)(a0 + 0xA) - 0x40;
    *(s32*)(a0 + 0x10) = *(s32*)(*(s32*)(a0 + 0x64) + 0x10);
    *(s32*)(a0 + 0x14) = *(s32*)(*(s32*)(a0 + 0x64) + 0x14);
    t = *(s32*)(*(s32*)(a0 + 0x64) + 0x18);
    *(u16*)(a0 + 0x2) = *(u16*)(a0 + 0x2) + 1;
    *(s32*)(a0 + 0x18) = t;
}
