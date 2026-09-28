/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE8A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801EE8A4(void *a0) {
    extern s32 D_801F5200;
    extern s32 D_801F5204;
    s32 p0 = D_801F5200;
    s32 p1 = D_801F5204;

    *(s16 *)((s32)a0 + 0xFC) = 0;
    *(s16 *)(p0 + 0xFC) = 0;
    *(s16 *)(p1 + 0xFC) = 0;
}
