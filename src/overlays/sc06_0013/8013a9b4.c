/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013A9B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8013A9F8(s32 a0, s32 a1);

void func_8013A9B4(s32 a0, s32 a1) {
    *(s16 *)(a1 + 0x2) = 0;
    *(s32 *)(a1 + 0x4) = a0;
    *(s32 *)(a0 + 0x40) = a1;
    *(s16 *)(a1 + 0x0) = 1;
    *(s16 *)(a1 + 0xC) = 0;
    *(s16 *)(a1 + 0xE) = 0;
    func_8013A9F8(a1, *(u16 *)(a0 + 0x18));
}
