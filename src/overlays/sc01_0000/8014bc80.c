/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014BC80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_80078EB4;
extern u8 D_800B9A17;

void func_8014BC80(s32 a0, s32 a1) {
    s32 v;
    v = *(u16 *)&D_80078EB4;
    if (v < a1) {
        D_80078EB4 = 0;
        D_800B9A17 = 0;
    } else {
        D_80078EB4 = v - a1;
    }
}
