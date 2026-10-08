/* SC02.CD FILE_031 / ov_SC02_031 retail span [801555BC,801555F4).
 * Offset 0x2D464 at overlay base 80128158. SHA256(span)=75add6aa9eea02ca063b3a82ad50c364ca994c3e9821f257ec08a3b3476cf26c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801555bc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801555BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104();
extern void func_801555F4(void *);

void func_801555BC(void *a0) {
    if (func_80161104(a0)) {
        func_801555F4(a0);
    }
}
