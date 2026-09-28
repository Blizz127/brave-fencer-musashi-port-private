/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AEAAC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_801AEAAC(void) {

    extern u8 D_801F8EB8[];
    s32 a0;
    s32 v1;
    v1 = (s32)D_801F8EB8;
    for (a0 = 0; a0 < 0x20; a0++, v1 += 0x24) {
        if (*(u16 *)v1 == 0) {
            return v1;
        }
    }
    return 0;
}
