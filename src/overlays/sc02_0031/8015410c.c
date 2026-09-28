/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015410C,80154134).
 * Offset 0x2BFB4 at overlay base 80128158. SHA256(span)=c11d33d71490dbc0056f98881fd942e6768c77960a4e489d437ae49d0c396e96.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015410c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015410C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80151664(void);
extern s32 D_80127518;

void func_8015410C(void) {
    D_80127518 = 0;
    func_80151664();
}
