/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179F98,80179FEC).
 * Offset 0x51E40 at overlay base 80128158. SHA256(span)=101ab523d4e9c0ec0e8840db8c13667f8b6cfc1628293874bcd9339de76bf47f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179f98.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80179F98 - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_80179F98(u16 *a0) {
    s16 sp[5];
    sp[0] = 0x17;
    sp[1] = a0[0];
    sp[2] = a0[1];
    sp[3] = a0[2];
    sp[4] = a0[3];
    func_80179B74(sp);
}
