/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139DF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80139A8C(s32 a0);

void func_80139DF4(s32 a0) {
    s32 c;
    s32 v;
    c = *(u8 *)(a0 + 0xC);
    if (c != 0) {
        c = c - 1;
        *(s8 *)(a0 + 0xC) = (s8)c;
        if ((c & 0xFF) != 0) {
            goto calls;
        }
    }
    *(s16 *)(a0 + 0x4) = 2;
    return;
calls:
    func_80139A8C(a0);
    if (*(s32 *)(a0 + 0x8) & 0x20) {
        *(s16 *)(a0 + 0x4) = 2;
        v = *(s32 *)(a0 + 0x8);
        *(s8 *)(a0 + 0xC) = 0;
        if ((v & 0x20000) == 0) {
            *(s32 *)(a0 + 0x8) = v & -0x21;
        }
    }
}
