/* SC02.CD FILE_031 / ov_SC02_031 retail span [801659B8,801659CC).
 * Offset 0x3D860 at overlay base 80128158. SHA256(span)=316524b043875f0988d2a8c3053d34ea546def849ec90e6800cd66399168b012.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801659b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801659B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80126B08;

void func_801659B8(void)
{
    D_80126B08 = 1;
}
