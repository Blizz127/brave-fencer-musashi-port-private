/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172760,80172780).
 * Offset 0x4A608 at overlay base 80128158. SHA256(span)=7959c3a433d3bf2bec37caa2a838757b04d9684b29bd17feaae0d19c44e026b7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172760.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172760 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80174650(s32);

s32 func_80172760(s32 a0) {
    return func_80174650(a0);
}
