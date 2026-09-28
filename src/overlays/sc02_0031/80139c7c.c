/* SC02.CD FILE_031 / ov_SC02_031 retail span [80139C7C,80139D04).
 * Offset 0x11B24 at overlay base 80128158. SHA256(span)=8145f2a838d51bbe59cd24054d5d75002025b703b7dd6330143da23e77ce7778.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80139c7c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
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
