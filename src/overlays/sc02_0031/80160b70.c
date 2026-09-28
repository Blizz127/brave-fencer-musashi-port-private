/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160B70,80160BB4).
 * Offset 0x38A18 at overlay base 80128158. SHA256(span)=e8d5374d0eb3f284d8c304d876a02c346a6549c0c14af0763872c50cb418fab2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160b70.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160B70 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104(void);
extern void func_80160BB4(s32 *a0);

void func_80160B70(s32 a0) {
    if (func_80161104()) {
        func_80160BB4(a0);
    } else {
        *(s32 *)(a0 + 0x1AC) = 0;
    }
}
