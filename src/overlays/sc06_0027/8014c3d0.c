/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C3D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8014C59C(void *a0, void *a1);
extern s32 func_8014C43C(void *a0, s32 a1, s32 a2, s32 a3, s16 a5);

s32 func_8014C3D0(void *a0, s32 a1, s32 a2, s32 a3) {
    s16 v = (s16)func_8014C59C(a0, a1);
    return func_8014C43C(a0, a1, a2, a3, v);
}
