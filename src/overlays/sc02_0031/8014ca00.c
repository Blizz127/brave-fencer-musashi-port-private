/* SC02.CD member31 [8014CA00,8014CA14); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014CA00 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_8014CA00(s32 a0) {
    s32 *p = *(s32 **)((s32)a0 + 0x78);
    return *(s16*)((s32)p + 0x2C);
}
