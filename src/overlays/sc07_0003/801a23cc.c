/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A23CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_801A23CC(s32 arg0) {
    if (*(s16 *)(arg0 + 0x98) == 0 || (*(u16 *)(arg0 + 0x72) & 0x4000)) {
        return 1;
    }
    return 0;
}
