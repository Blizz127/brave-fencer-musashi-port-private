/* SC02.CD member31 [80150C48,80150CA0); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80150C48 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80150480(s32 a0);
extern s32 D_800AE6B0;
extern u16 D_800AE6DC;

void func_80150C48(s32 a0) {
    if (func_80150480(a0) != 0) {
        s32 p = *(s32 *)(a0 + 0x1A4);
        D_800AE6B0 = *(s32 *)(p + 0xDC);
        p = *(s32 *)(a0 + 0x1A4);
        D_800AE6DC = *(u16 *)(p + 0xFC);
    }
}
