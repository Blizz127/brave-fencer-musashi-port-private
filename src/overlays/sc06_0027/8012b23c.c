/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B23C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012B23C(s32 a0) {
    *(s32 *)(a0 + 0x18) = 0;
    *(s32 *)(a0 + 0x14) = 0;
    *(s32 *)(a0 + 0x10) = 0;
    *(s32 *)(a0 + 0x4C) = 0;
    *(s32 *)(a0 + 0x44) = 0;
    *(s32 *)(a0 + 0x48) = 0x18000;
}
