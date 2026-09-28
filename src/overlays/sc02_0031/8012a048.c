/* Complete SC02 member31 [8012A048,8012A094). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A048 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s16 D_80126940;
extern s16 D_80126942;
extern s16 D_80126944;

void func_8012A048(void *a0, s32 a1, u8 a2) {
    *(s32 *)((s32)a0 + 0x0) = a1;
    *(u8 *)((s32)a0 + 0x4) = a2;
    *(s32 *)((s32)a0 + 0x9C) = 0;
    *(s16 *)((s32)a0 + 0xA0) = 0;
    *(s16 *)((s32)a0 + 0xA2) = 0;
    D_80126940 = D_80126B5E;
    D_80126942 = D_80126B62;
    D_80126944 = D_80126B66;
}
