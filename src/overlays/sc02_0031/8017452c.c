/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017452C,80174554).
 * Offset 0x4C3D4 at overlay base 80128158. SHA256(span)=dd1221df2efa82444c70b3125884dc23b794cdd5c8038c285c4d0a29fa05cdd7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017452c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017452C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80174684(void *);
extern void func_80174554();

void func_8017452C(void) {
    func_80174684(func_80174554);
}
