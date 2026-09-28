/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80149DD8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801202A0[];
extern s32 func_80149F2C(s32 a0, s32 a1);

s32 func_80149DD8(s32 a0) {
    u8 *p;
    if (*(s32 *)(a0 + 0x178) != 0) {
        return 0;
    }
    if (*(s32 *)(a0 + 0x44) & 0x404) {
        return 0;
    }
    if ((*(u16 *)(a0 + 0xAC) & 0x80) == 0) {
        return 0;
    }
    *(s32 *)(a0 + 0x190) = 0;
    for (p = D_801202A0; p < D_801202A0 + 0x6480; p += 0x10C) {
        if (func_80149F2C(a0, (s32)p) != 0) {
            return 1;
        }
    }
    return 0;
}
