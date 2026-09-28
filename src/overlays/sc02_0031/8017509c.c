/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017509C,80175114).
 * Offset 0x4CF44 at overlay base 80128158. SHA256(span)=b63f894860695c7811dc11ae1857ae6aa0512782c066c42152f930793a57a222.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017509c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017509C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_8017509C(u8 *a0, s32 a1, u8 *a2, u8 *a3) {
    a1 = (s16)a1;
    a0 = a0 + a1 * 14;
    if (*(s16 *)(a0 + 0xC) == 0x7FFF) {
        return 1;
    }
    *(u16 *)(a2 + 0) = *(u16 *)(a0 + 0);
    *(u16 *)(a2 + 2) = *(u16 *)(a0 + 2);
    *(u16 *)(a2 + 4) = *(u16 *)(a0 + 4);
    *(u16 *)(a3 + 0) = *(u16 *)(a0 + 6);
    *(u16 *)(a3 + 2) = *(u16 *)(a0 + 8);
    *(u16 *)(a3 + 4) = *(u16 *)(a0 + 0xA);
    return 0;
}
