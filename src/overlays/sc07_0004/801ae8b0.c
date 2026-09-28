/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AE8B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801ADA10();

void func_801AE8B0(s32 a0) {
    if (--*(s32 *)(a0 + 0x1C) == 0) {
        *(u16 *)(a0 + 2) += 1;
    }
    if (*(s32 *)(a0 + 0x1C) & 1) {
        func_801ADA10(a0);
    }
}
