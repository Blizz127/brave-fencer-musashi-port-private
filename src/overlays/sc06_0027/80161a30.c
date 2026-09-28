/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161A30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC0;

s32 func_80161A30(s32 a0) {
    if (*(s16*)(a0 + 0x1C8) != 0) {
        return ((D_80078EC0 & 0x7F) ^ 0x5) == 0;
    }
    return 0;
}
