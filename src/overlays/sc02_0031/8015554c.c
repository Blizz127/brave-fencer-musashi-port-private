/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015554C,80155580).
 * Offset 0x2D3F4 at overlay base 80128158. SHA256(span)=6cb15fbe27ad5978a8f58a8cc76c4f8243ba543c2b43001bb4f34f90d2d288d4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015554c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015554C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_80155580(void *a0);

void func_8015554C(s32 *a0) {
    func_80147078(a0, 5);
    func_80155580(a0);
}
