/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171A1C,80171A34).
 * Offset 0x498C4 at overlay base 80128158. SHA256(span)=cbcdc56256facabaaa414ecec4e6262b153ac9c767b43af3bd5f9131217a48ad.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171a1c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171A1C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

void func_80171A1C(u8 *a0) {
    a0[0x215] = 0;
    a0[0x216] = 0;
    a0[0x214] = a0[0x214] + 1;
}
