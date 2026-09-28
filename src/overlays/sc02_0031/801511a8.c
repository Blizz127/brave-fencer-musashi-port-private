/* SC02.CD FILE_031 / ov_SC02_031 retail span [801511A8,801511C4).
 * Offset 0x29050 at overlay base 80128158. SHA256(span)=88a5f51c9e9ff26f0b86b67107761973b4db13fc5fb509acf6903ccf0e601471.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801511a8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801511A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801511A8(u8 *a0) {
    u16 v = *(u16 *)(a0 + 0x3C);
    *(s16 *)(a0 + 0x3E) = 0;
    *(s16 *)(a0 + 0x40) = 0;
    *(s16 *)(a0 + 0x42) = 0;
    *(u16 *)(a0 + 0x3C) = v & 0xFFFE;
}
