/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80131E38 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80131CA8(int a0, int a1);

void func_80131E38(u8 *a0) {
    *(s8 *)(a0 + 0xC1) = 0xF;
    if (*(s32 *)(a0 + 0xB4) & 0x40000) {
        *(s32 *)(a0 + 0x1C) = 6;
        *(s16 *)(a0 + 0x5C) = 0;
    }
    func_80131CA8((int)a0, 0x39);
}
