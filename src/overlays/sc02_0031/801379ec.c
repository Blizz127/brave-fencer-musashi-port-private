/* SC02.CD FILE_031 / ov_SC02_031 retail span [801379EC,801379FC).
 * Offset 0xF894 at overlay base 80128158. SHA256(span)=bed47cddca2cc72c0856bae7c0f868f26409c471b669fc3ae76312531faf00cb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801379ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801379EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_8012752E;

void func_801379EC(void) {
    D_8012752E = 0;
}
