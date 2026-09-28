/* MAIN10 resident retail span [800D1B80,800D1BD8), offset 0x22D88 at base 800AEDF8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D1B80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_800D1B80(u8 *arg0) {
    extern s32 func_800D1BD8();
    register s32 zr __asm__("$0");
    s32 (*fp)(void);
    u8 *p;

    fp = *(s32 (**)(void)) (arg0 + 0xC);
    if (fp() != 0) {
        p = arg0 + zr;
        p[0x14] = arg0[0x14] + 1;
        return func_800D1BD8(p);
    }
    return 0;
}
