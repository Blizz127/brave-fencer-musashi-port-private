/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016A05C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC0;

void func_8016A05C(void *a0) {
    s32 v0;
    if (D_80078EC0 & 0x7F) {
        v0 = *(u16 *)((s32)a0 + 2) + 1;
    } else {
        v0 = 2;
    }
    *(s16 *)((s32)a0 + 2) = v0;
}
