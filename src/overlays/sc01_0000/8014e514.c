/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014E514 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);

s32 func_8014E514(u8 *a0, s32 a1, s32 a2) {
    u8 *p;
    s32 q;
    p = *(u8 **)(a0 + 0x17C);
    if (*(u16 *)p != 0 &&
        (*(u16 *)(p + 0x5C) & 0x40) != 0 &&
        (q = *(s32 *)(p + 0x58)) != 0 &&
        func_80135888(*(s32 *)(p + 0x20), q, a1, a2) != 0) {
        goto success;
    }
    *(s32 *)(a0 + 0x17C) = 0;
    return 0;
success:
    *(u16 *)(a0 + 6) = *(u16 *)(p + 6);
    *(u16 *)(a0 + 0xE) = *(u16 *)(p + 0xE);
    return 1;
}
