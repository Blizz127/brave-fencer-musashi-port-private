/* SC02.CD FILE_031 / ov_SC02_031 retail span [801281B8,801281D8).
 * Offset 0x60 at overlay base 80128158. SHA256(span)=a1f738ca401ee1cbca9c8895e61d5856f8a1c6a6f82471b2bfd1271374b272f0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801281b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801281B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80128714(void);

void func_801281B8(void) {
    func_80128714();
}
