/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174764,80174774).
 * Offset 0x4C60C at overlay base 80128158. SHA256(span)=f7d91d83d490682bf449428cd7e74099a52ee73cd23669d3b71ab216ca889ae8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174764.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174764 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_8011F9C8;

s16 func_80174764(void) {
    return D_8011F9C8;
}
