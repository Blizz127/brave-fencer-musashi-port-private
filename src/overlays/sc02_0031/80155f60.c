/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155F60,80155F80).
 * Offset 0x2DE08 at overlay base 80128158. SHA256(span)=969f9d5f3a4620be0c4792404967a1d38fead94f844bb5822987d935cd11315b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155f60.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80155F60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80155F80();

s32 func_80155F60(void) {
    return func_80155F80();
}
