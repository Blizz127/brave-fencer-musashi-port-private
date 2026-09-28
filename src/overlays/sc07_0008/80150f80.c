/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80150F80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80151184(s32 a0, s32 a1, s32 a2);
extern u8 D_80078EC1;

void func_80150F80(s32 a0) {
    if (D_80078EC1 != 0xC) {
        func_80151184(a0, 0xC007, 0x20);
    }
}
