/* SC02.CD FILE_031 / ov_SC02_031 retail span [801379D8,801379EC).
 * Offset 0xF880 at overlay base 80128158. SHA256(span)=1564c18fe9af03fcfdafcfeea0d209014c837a9f549c4361b260fc73f27f4f4d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801379d8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801379D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_8012752E;

void func_801379D8(void) {
    D_8012752E = 1;
}
