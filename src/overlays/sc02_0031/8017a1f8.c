/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017A1F8,8017A220).
 * Offset 0x520A0 at overlay base 80128158. SHA256(span)=e9749687d9e90103df183d04b908a64a40b3b5638e51a17c2c05e0eb7068c143.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017a1f8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017A1F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80179B74(u16 *p);

void func_8017A1F8(void) {
    short sp10;
    sp10 = 0xC;
    func_80179B74(&sp10);
}
