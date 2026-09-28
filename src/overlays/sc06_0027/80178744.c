/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80178744 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

void func_80178744(s32 a0, s32 a1) {
    s32 v0;
    s16 sv;
    if (*(s32 *)(a0 + 0x6C) != 0) {
        func_80178744(*(s32 *)(a0 + 0x6C), a1);
    }
    v0 = *(s32 *)(a0 + 0x20);
    sv = a1;
    *(s16 *)(v0 + 0x1C) = sv;
    *(s16 *)(v0 + 0x1A) = sv;
    *(s16 *)(v0 + 0x18) = sv;
    if (a1 == 0x1000) {
        s32 v1 = *(s32 *)(a0 + 0x20);
        *(u16 *)(v1 + 0x2C) = *(u16 *)(v1 + 0x2C) & 0xFFEF;
    } else {
        s32 v1 = *(s32 *)(a0 + 0x20);
        *(u16 *)(v1 + 0x2C) = *(u16 *)(v1 + 0x2C) | 0x10;
    }
}
