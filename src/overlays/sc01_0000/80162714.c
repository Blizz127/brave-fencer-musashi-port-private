/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80162714 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_800291DC(s32);
extern s32 func_800D0D7C(s32, s32);
extern void func_800291C8(s32, s32);

void func_80162714(void) {
    s32 v0;
    if ((s16)func_800291DC(0x12) == 0) {
        v0 = func_800D0D7C(0xC, 0);
        func_800291C8(0x12, (s16)(v0 | 0x8000));
    }
}
