/* SC02.CD FILE_031 / ov_SC02_031 retail span [80158288,801582C0).
 * Offset 0x30130 at overlay base 80128158. SHA256(span)=47352db0931a2c42bf0c65cc814161207535b6739c5d957ffda6b8e4294b3f80.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80158288.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158288 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104();
extern void func_801582C0(void *);

void func_80158288(void *a0) {
    if (func_80161104(a0)) {
        func_801582C0(a0);
    }
}
