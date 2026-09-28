/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170C44,80170C74).
 * Offset 0x48AEC at overlay base 80128158. SHA256(span)=5877c0599ca48badfc74ed2f3c96b37b5f2d4ee98debaa7c15e7ec5ec212e2ff.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170c44.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170C44 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80147060(u8 *a0);
extern void func_80171928(void *a0);

void func_80170C44(u8 *a0) {
    func_80147060(a0);
    func_80171928(a0);
}
