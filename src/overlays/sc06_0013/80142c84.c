/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80142C84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_80142C84(s32 a0) {
    *(s32 *)(a0 + 0x14) = 0xFFF40000;
    *(s32 *)(a0 + 0x48) = 0x20000;
    *(s16 *)(a0 + 0x102) = 0;
}
