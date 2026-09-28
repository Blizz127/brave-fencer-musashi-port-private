/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E1CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016E3CC(s32 a0);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_8012A568(void (*a0)(void));

void func_8016E1CC(s32 a0) {
    s32 s1;
    s32 v;
    s1 = *(s32 *)(a0 + 0x20);
    func_8016E3CC(a0);
    v = *(s32 *)(a0 + 0x1C) - 1;
    *(s32 *)(a0 + 0x1C) = v;
    if (v != 0) {
        func_80146A6C(0x48, (void *)a0, 0, 0, 0, 0x8000, 0);
        *(s16 *)(s1 + 0x18) = *(u16 *)(s1 + 0x18) + 0x100;
        *(s16 *)(s1 + 0x1A) = *(u16 *)(s1 + 0x1A) + 0x140;
        return;
    }
    *(s32 *)(a0 + 0x1C) = 0x20;
    *(s16 *)(a0 + 0x2) = *(u16 *)(a0 + 0x2) + 1;
}
