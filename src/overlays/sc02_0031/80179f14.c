/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179F14,80179F44).
 * Offset 0x51DBC at overlay base 80128158. SHA256(span)=7c605c9d44acfa7a1e9fce1956ce853557494b528cf41679fd744b10200d2f12.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179f14.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80179F14 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80179B74(u16 *p);

void func_80179F14(s16 a0, s16 a1) {
    s16 sp[3];
    sp[0] = 0x13;
    sp[1] = a0;
    sp[2] = a1;
    func_80179B74(sp);
}
