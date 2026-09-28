/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C0C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801202A0[];

s32 func_8014C0C8(s32 a0_unused, s32 a1, s32 a2) {
    s32 i = 0;
    s32 key = (s16)a2;
    u8 *p = D_801202A0;
    do {
        if (*(u16 *)(p + 0x0) == a1) {
            if (*(s16 *)(p + 0xFC) == key) {
                return (s32)p;
            }
        }
        i += 1;
        p += 0x10C;
    } while ((u32)i < 0x60);
    return 0;
}
