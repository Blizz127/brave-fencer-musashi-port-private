/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C050 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_8011D030;

s32 func_8014C050(s32 a0, s32 a1) {
    u32 i = 0;
    s32 p = (s32)&D_8011D030;
    for (; i < 0x1E; i++) {
        if (*(u16 *)p == a1) {
            return p;
        }
        p += 0x58;
    }
    return 0;
}
