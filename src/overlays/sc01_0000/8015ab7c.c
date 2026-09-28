/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015AB7C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800D48DC;

s32 func_8015AB7C(s32 a0) {
    u8 v1;
    if (*(s32*)(a0 + 0xB4) == (s32)&D_800D48DC) {
        v1 = *(u8*)(a0 + 0xDC);
        if (v1 < 6) {
            return 0x10;
        }
        if (v1 < 0xB) {
            return 0x12;
        }
        if (v1 < 0x10) {
            return 0x7;
        }
        return 0x9;
    }
    return *(u8*)(a0 + 0xBC);
}
