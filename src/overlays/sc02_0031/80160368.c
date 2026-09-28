/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160368,8016039C).
 * Offset 0x38210 at overlay base 80128158. SHA256(span)=b08d3dbb2886cf0dfe8b16c89cd3018cae12a074bc49297ddac0b370747ceb75.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160368.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160368 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8016039C();

void func_80160368(s32 *a0) {
    func_80147078(a0, 0x1B);
    func_8016039C(a0);
}
