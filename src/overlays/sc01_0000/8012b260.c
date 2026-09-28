/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B260 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012B260(u8 *a0) {
    u8 *a1;
    s32 a, b, c;
    u16 t;
    a1 = *(u8 **)(a0 + 0x20);
    a = (u16)*(u16 *)(a0 + 6) + (u16)*(u16 *)(a0 + 0x50);
    *(u16 *)(a1 + 8) = a;
    *(s32 *)(a1 + 0x48) = (s16)a;
    b = (u16)*(u16 *)(a0 + 0xA) + (u16)*(u16 *)(a0 + 0x52);
    *(u16 *)(a1 + 0xA) = b;
    *(s32 *)(a1 + 0x4C) = (s16)b;
    c = (u16)*(u16 *)(a0 + 0xE);
    t = *(u16 *)(a1 + 0x2C) | 1;
    c = c + (u16)*(u16 *)(a0 + 0x54);
    *(u16 *)(a1 + 0xC) = c;
    *(u16 *)(a1 + 0x2C) = t;
    *(s32 *)(a1 + 0x50) = (s16)c;
}
