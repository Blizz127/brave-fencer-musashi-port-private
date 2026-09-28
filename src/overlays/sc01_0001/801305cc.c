/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801305CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80131A34(s32, s32);
extern void func_80131CA8(int a0, int a1);

void func_801305CC(u8 *a0) {
    *(u8 *)(a0 + 0xC1) = 0xC;
    if (*(s32 *)(a0 + 0xB4) & 0x1000) {
        *(s32 *)(a0 + 0x1C) = 0x3C;
        *(s32 *)(a0 + 0xC4) = *(s32 *)(a0 + 0xC4) & ~4;
        if (func_80131A34((s32)a0, 0x20)) {
            *(s32 *)(a0 + 0xC4) = *(s32 *)(a0 + 0xC4) | 4;
        } else {
            *(u16 *)(a0 + 0x98) = 0;
        }
    }
    func_80131CA8((int)a0, 0x22);
}
