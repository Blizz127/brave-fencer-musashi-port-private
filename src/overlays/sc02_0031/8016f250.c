/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F250,8016F264).
 * Offset 0x470F8 at overlay base 80128158. SHA256(span)=e05b0957d80780e28de2d266b0c5d898861f853189062f192f5aa2fd649a73c1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f250.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F250 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80126D1A;

void func_8016F250(void)
{
    D_80126D1A = 1;
}
