/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A060C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A828(s32 a0, void *a1);
extern u8 D_801F0008[];

void func_801A060C(s32 arg0) {
    *(s16 *)(arg0 + 0x02) = 4;
    *(s32 *)(arg0 + 0x1C) = 0x40;
    *(s32 *)(arg0 + 0xE4) = 0x50;
    func_8012A828(arg0, D_801F0008);
}
