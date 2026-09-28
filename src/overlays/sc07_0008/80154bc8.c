/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154BC8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80154BC8(void *a0, s32 a1, s32 a2) {
    *(s32 *)((s32)a0 + 0xD0) = a1;
    *(s16 *)((s32)a0 + 0xD6) = 1;
    *(s16 *)((s32)a0 + 0xD4) = 1;
    *(s8 *)((s32)a0 + 0xD8) = a2;
    *(s8 *)((s32)a0 + 0xD9) = a2;
}
