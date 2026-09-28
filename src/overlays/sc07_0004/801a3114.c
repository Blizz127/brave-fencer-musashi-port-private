/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A3114 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A36F0(void *a0);
extern void func_8012AD44(s32 *a0, s16 a1);
extern void func_8012A860(void *a0, int a1);
extern u8 D_801EF9A8;

void func_801A3114(s32 *a0)
{
    s32 *s0 = a0;
    u16 v0;

    v0 = *(u16 *)((s32)s0 + 0x5C);
    *(u16 *)((s32)s0 + 0x5E) = 0;
    *(u8 *)((s32)s0 + 0xC1) = 0;
    *(u16 *)((s32)s0 + 0x5C) = v0 & 0xDFFE;
    func_801A36F0((void *)s0);
    func_8012AD44(s0, 12);
    if (*(s16 *)((s32)s0 + 0xE6) < 0) {
        *(u16 *)((s32)s0 + 0x34) = 2;
        func_8012A860((void *)s0, (int)&D_801EF9A8);
    }
}
