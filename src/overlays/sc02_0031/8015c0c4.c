/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015C0C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80146CA0(void *a0);
extern s16 D_801152B0;
extern s16 D_801152B4;

void func_8015C0C4(s32 a0) {
    s32 t = D_801152B0 << 6;
    *(s32 *)(a0 + 0x238) = 0x80000;
    *(s32 *)(a0 + 0x234) = t;
    *(s32 *)(a0 + 0x23C) = D_801152B4 << 6;
    func_80154150(a0, 0x11);
    func_801553A8((s32 *)a0);
    func_80146CA0((void *)a0);
}
