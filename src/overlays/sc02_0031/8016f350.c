/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F350,8016F374).
 * Offset 0x471F8 at overlay base 80128158. SHA256(span)=407d2ff48e0b34717e0e0e3d15b60fa71cf839f93a2d3319fa363a43e43c1439.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f350.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F350 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80126D50;

void func_8016F350(void) {
    D_80126D50 &= 0xEFFFFFFF;
}
