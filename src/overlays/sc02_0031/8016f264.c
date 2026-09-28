/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F264,8016F288).
 * Offset 0x4710C at overlay base 80128158. SHA256(span)=6af71a3c21cad53b704606398c126b5ea36d4afd9ac0ef88ab95f652038921cf.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f264.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F264 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80126D50;

void func_8016F264(void) {
    D_80126D50 &= 0xFEFFFFFF;
}
