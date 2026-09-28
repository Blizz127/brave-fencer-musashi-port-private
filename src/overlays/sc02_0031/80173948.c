/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173948,80173980).
 * Offset 0x4B7F0 at overlay base 80128158. SHA256(span)=ecde7676b4da16f5d31f557b05fe027f73a5ac780fa8a0240ea6c038460e71d2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173948.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80173948 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80173980(u8 *a0);

void func_80173948(u8 *a0) {
    func_80147060(a0);
    func_80171A1C(a0);
    func_80173980(a0);
}
