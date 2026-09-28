/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80148038 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80148038(s32 a0, s32 a1) {
    s32 v1 = *(s32*)(a0 + 0x34);
    if (v1 < 0) {
        if (a1 < 0) {
            if ((s32)0xFFE10000 < v1) {
            } else {
                a1 = 0;
            }
        }
    } else {
        if (a1 > 0) {
            if (0x1EFFFF < v1) {
                a1 = 0;
            }
        }
    }
    *(s32*)(a0 + 0x34) += a1;
}
