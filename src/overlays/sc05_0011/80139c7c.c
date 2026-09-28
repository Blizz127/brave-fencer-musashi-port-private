/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139C7C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_80139C7C(u8 *a0) {
    s32 a1;
    if (*(u8 *)(a0 + 0x20) != 0) {
        if (*(u8 *)(a0 + 0x22) & 0x8) {
            a1 = (*(s16 *)(a0 + 0x34) + 0x28) >> 1;
        } else {
            a1 = ((*(s16 *)(a0 + 0x34) + 0x28) >> 1) - 0x28;
        }
    } else {
        a1 = (s32)(*(u16 *)(a0 + 0x34) << 16) >> 17;
    }
    *(s16 *)(a0 + 0x30) = *(u16 *)(a0 + 0x24) - a1;
    *(s16 *)(a0 + 0x32) = *(u16 *)(a0 + 0x26) - ((s32)(*(u16 *)(a0 + 0x36) << 16) >> 17);
}
