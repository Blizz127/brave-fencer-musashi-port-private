/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801847AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80029124(s32, s32);

void func_801847AC(void *a0) {

    extern s32 D_801AAE88[];
    u16 idx = *(u16 *)(*(s32 *)(a0 + 0xDC) + 0xA);
    func_80029124(D_801AAE88[idx], 1);
}
