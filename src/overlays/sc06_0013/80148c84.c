/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80148C84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_80148C84(s32 a0, s32 a1) {
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) = (a1 + 0x600) & 0xFFF;
    return 1;
}
