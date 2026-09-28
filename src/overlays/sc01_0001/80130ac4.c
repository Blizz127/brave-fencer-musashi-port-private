/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80130AC4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_80130AC4(s32 a0) {
    s16 v0;
    v0 = *(u16*)(a0 + 0xAC) - 1;
    *(u16*)(a0 + 0xAC) = v0;
    if (v0 == 0) {
        *(u8*)(a0 + 0xC1) = 0;
        *(s16*)(a0 + 0x5E) = 0;
    }
}
