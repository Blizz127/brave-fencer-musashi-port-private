/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80130088 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012BCCC(s32 a0);
extern s32 func_80131AC8(void *a0);

void func_80130088(void *a0) {
    s32 v0 = func_8012BCCC((s32)a0);
    if (v0 <= 0x8FFF) {
        if (((s32 (*)(void *, s32))func_80131AC8)(a0, 0x32)) {
            return;
        }
        ((s32 (*)(void *, s32))func_80131AC8)(a0, 0x33);
    } else {
        if (((s32 (*)(void *, s32))func_80131AC8)(a0, 0x33)) {
            return;
        }
        ((s32 (*)(void *, s32))func_80131AC8)(a0, 0x32);
    }
}
