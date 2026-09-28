/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F288,8016F2A8).
 * Offset 0x47130 at overlay base 80128158. SHA256(span)=a70ed8ed9a2b4dc8650107018df668c5fcda1d8bd12a426339d13215d7463028.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f288.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F288 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80126D50;

void func_8016F288(void) {
    D_80126D50 = D_80126D50 | 0x1000000;
}
