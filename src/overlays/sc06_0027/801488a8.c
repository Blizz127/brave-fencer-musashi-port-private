/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801488A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_801488A8(u8 *a0) {
    u8 c;
    s32 v0;
    u32 h;
    s32 lo;
    c = a0[0xA9];
    switch (c) {
    case 0x41:
        v0 = *(u16 *)(a0 + 0xAA) & 0xF000;
        break;
    case 0x53:
    case 0x73:
        h = *(u16 *)(a0 + 0xAE);
        lo = h & 0xFF;
        if (lo != 0x80) {
            return 1;
        }
        if ((s32)(h >> 8) != lo) {
            return 1;
        }
        v0 = 0;
        break;
    default:
        v0 = 0;
        break;
    }
    return v0;
}
