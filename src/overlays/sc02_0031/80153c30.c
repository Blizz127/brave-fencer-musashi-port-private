/* SC02.CD FILE_031 / ov_SC02_031 retail span [80153C30,80153C44).
 * Offset 0x2BAD8 at overlay base 80128158. SHA256(span)=b3996c84dc96e1973ea5f146e529c95af79ac45f5dda75abe0fe9054f52a5a58.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80153c30.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153C30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_8011F748;

void func_80153C30(void)
{
    D_8011F748 = 1;
}
