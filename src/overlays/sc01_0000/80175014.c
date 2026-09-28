/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175014 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_80175014(u8 *a0, u8 *a1, s32 a2) {
    a2 = (s16)a2;
    a1 = a1 + a2 * 14;
    if (*(s16 *)(a1 + 0xC) == 0x7FFF) {
        return 1;
    }
    *(s32 *)(a0 + 0x3C) = *(s16 *)(a1 + 0);
    *(s32 *)(a0 + 0x40) = *(s16 *)(a1 + 2);
    *(s32 *)(a0 + 0x44) = *(s16 *)(a1 + 4);
    *(s32 *)(a0 + 0x48) = *(s16 *)(a1 + 6);
    *(s32 *)(a0 + 0x4C) = *(s16 *)(a1 + 8);
    *(s32 *)(a0 + 0x50) = *(s16 *)(a1 + 0xA);
    *(s32 *)(a0 + 0x54) = *(s16 *)(a1 + 0xC) << 5;
    return 0;
}
