/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A2F4,8012A304).
 * Offset 0x219C at overlay base 80128158. SHA256(span)=c475584f48b5ca97bb86e311cac4ca804ab22ffe1508ec7533a8f4b7f019893c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a2f4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A2F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s8 D_801152C0;

void func_8012A2F4(void) {
    D_801152C0 = 0;
}
