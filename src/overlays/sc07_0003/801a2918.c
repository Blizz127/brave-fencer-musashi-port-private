/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A2918 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_801A2918(s32 arg0) {
    register s32 r __asm__("$2");
    s32 p;
    r = 1;
    p = *(s32 *)(arg0 + 0xD8);
    if (p != 0) {
        r = *(s32 *)(p + 0xE0) != 0;
    }
    return r;
}
