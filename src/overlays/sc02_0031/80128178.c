/* SC02.CD FILE_031 / ov_SC02_031 retail span [80128178,80128198).
 * Offset 0x20 at overlay base 80128158. SHA256(span)=4a5ccfebeb75aa8509d2e24a116b4c377e1591c955e77133fb1fa2e2f13218cd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80128178.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80128178 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801285E4(void);

void func_80128178(void) {
    func_801285E4();
}
