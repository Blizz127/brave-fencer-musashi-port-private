/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160E3C,80160E70).
 * Offset 0x38CE4 at overlay base 80128158. SHA256(span)=f1f8a2cd1b2cd5a0ff97c5101e996bb6f06fd88f3908a0a85edcc2eed04dcb92.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160e3c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160E3C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_80160F00();

void func_80160E3C(s32 *a0) {
    func_80147078(a0, 0x1E);
    func_80160F00(a0);
}
