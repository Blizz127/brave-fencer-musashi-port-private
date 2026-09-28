/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801684B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80146C3C();
extern s32 func_80166994(s32 a0, s32 a1, s32 a2, s32 a3);

void func_801684B4(s32 a0) {
    if ((*(s32 *)(*(s32 *)(a0 + 0x34) + 0x44) & 0x2) == 0) {
        func_80146C3C();
    } else {
        s16 v0 = *(u16 *)(a0 + 0x2A) - 1;
        *(s16 *)(a0 + 0x2A) = v0;
        if (v0 == 0) {
            func_80166994(a0, 0, 2, 0);
            *(s16 *)(a0 + 0x2) = *(u16 *)(a0 + 0x2) + 1;
        }
    }
}
