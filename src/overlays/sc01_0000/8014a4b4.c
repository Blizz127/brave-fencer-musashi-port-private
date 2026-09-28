/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014A4B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029178(s32 a0);

s32 func_8014A4B4(void *a0) {
    if ((func_80029178(0x1E) & 0xFF) != 0) {
        u32 v = *(u16 *)((s32)a0 + 0xAC) & 0x40;
        return v != 0;
    }
    return 0;
}
