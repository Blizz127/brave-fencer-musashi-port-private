/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170B14,80170B48).
 * Offset 0x489BC at overlay base 80128158. SHA256(span)=e97098395fdd9b78c45af40198ab2f4e1f7d2ebe633b02897639573bfed16465.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170b14.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170B14 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_801719A4(int a0, int a1);
extern void func_80170B48(int a0);

void func_80170B14(int a0) {
    func_801719A4(a0, 1);
    func_80170B48(a0);
}
