/* SC02.CD FILE_031 / ov_SC02_031 retail span [801511C4,801511E0).
 * Offset 0x2906C at overlay base 80128158. SHA256(span)=f6e6864f3814bfa3c378ae754fca99c11d3374b7aff9a2781ddd2f88bdc962f8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801511c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801511C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801511C4(u8 *a0) {
    *(u16 *)(a0 + 0xF0) = *(u16 *)(a0 + 0x3E);
    *(u16 *)(a0 + 0xF2) = *(u16 *)(a0 + 0x40);
    *(u16 *)(a0 + 0xF4) = *(u16 *)(a0 + 0x42);
}
