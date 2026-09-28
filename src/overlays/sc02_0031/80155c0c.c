/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80155C0C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern u8 D_800D4DD4[];

void func_80155C0C(s32 *a0) {
    u8 sp10[0x40];
    (void)sp10;
    a0[0x44 / 4] |= 2;
    if (*(u16 *)((u8 *)a0 + 0xB8) == 0x8000) {
        func_80154274(a0, (s32)D_800D4DD4);
        func_80146CA0(a0);
    }
}
