/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175624 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s16 D_800B9A02;
extern void func_801757A0(s32);

void func_80175624(void *a0) {
    func_801757A0(D_800B9A02);
    *((u8 *)a0 + 1) = *((u8 *)a0 + 1) + 1;
}
