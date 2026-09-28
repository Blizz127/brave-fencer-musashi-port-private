/* SC02.CD FILE_031 / ov_SC02_031 retail span [80153C74,80153C8C).
 * Offset 0x2BB1C at overlay base 80128158. SHA256(span)=e2a3948ec956746158324482669fff2fda0abeb02fca34c4dde12a7ababc3283.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80153c74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153C74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_8011DB0C;
extern s16 D_8011DB1A;

void func_80153C74(s16 a0, s16 a1) {
    D_8011DB0C = a0;
    D_8011DB1A = a1;
}
