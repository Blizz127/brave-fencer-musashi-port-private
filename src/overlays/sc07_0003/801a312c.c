/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A312C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801A312C(s32 a0) {
    extern void func_8002D4C8(s32 a1, s32 a2);

    if (*(s32 *)(a0 + 0x94) == 0xA) {
        if ((*(s32 *)(a0 + 0x1C) & 1) == 0) {
            func_8002D4C8(0xC31, 0);
        } else {
            func_8002D4C8(0xC32, 0);
        }
        *(s32 *)(a0 + 0x1C) = *(s32 *)(a0 + 0x1C) + 1;
    }
}
