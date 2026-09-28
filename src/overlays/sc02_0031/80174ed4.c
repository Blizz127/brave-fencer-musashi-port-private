/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174ED4,80174EF0).
 * Offset 0x4CD7C at overlay base 80128158. SHA256(span)=3d0381c08dd4c9fe6ebe00d248b0e6128ee25045ba56382abcd7339202510ea9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174ed4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174ED4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_80126980;

s32 func_80174ED4(void) {
    return (s16)(D_80126980 & 0x8000);
}
