/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174F64 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80175014(u8 *a0, u8 *a1, s32 a2);

void func_80174F64(u8 *a0) {
    s32 r;
    u16 *p = (u16 *)(a0 + 0x38);
    r = func_80175014(a0, *(u8 **)(a0 + 0x34), *p & 0x7FFF);
    if (r != 0) {
        *p = *p | 0x8000;
    } else {
        *p = *p + 1;
    }
}
