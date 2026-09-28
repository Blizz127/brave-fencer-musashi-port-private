/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A0940 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A28AC(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8005C49C(void);
extern u16 D_801F1EC0[];

void func_801A0940(void *a0) {
    s32 d;

    func_801A28AC((s32)a0);
    *(s16 *)((s32)a0 + 0x2) = 0xA;
    *(s32 *)((s32)a0 + 0xE4) = 0x50;
    *(u16 *)((s32)a0 + 0x34) = 0;
    func_8012A828((s32)a0, D_801F1EC0);
    d = func_8005C49C();
    *(s32 *)((s32)a0 + 0x1C) = d % 64 + 0x40;
    *(s32 *)((s32)a0 + 0xE0) &= ~8;
}
