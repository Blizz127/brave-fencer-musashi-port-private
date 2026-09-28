/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F6B0,8016F6E0).
 * Offset 0x47558 at overlay base 80128158. SHA256(span)=ab21b2bd06e66229278826a871e3835a00dc04327a245b04cc227f55c8111a22.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f6b0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F6B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016F330(void);
extern void func_80171928(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016F6B0(void *a0) {
    func_8016F330();
    func_80171928(a0);
}
