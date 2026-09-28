/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017A11C,8017A144).
 * Offset 0x51FC4 at overlay base 80128158. SHA256(span)=1a82c71a01d3653a8e5720312d29b0e842b83939d86afa9de70c27add7b11bdd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017a11c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017A11C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80179B74(u16 *p);

void func_8017A11C(void) {
    short sp10;
    sp10 = 0x8;
    func_80179B74(&sp10);
}
