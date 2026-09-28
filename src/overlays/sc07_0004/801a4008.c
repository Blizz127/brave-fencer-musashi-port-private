/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4008 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80143970(s32 a0);

void func_801A4008(s32 a0) {
    *(s32 *)(*(s32 *)(a0 + 0x20) + 4) &= 0x7FFFFFFF;
    if (*(s32 *)(a0 + 0xD0) == 0) {
        *(s32 *)(a0 + 0xD0) = func_80143970(a0);
    }
}
