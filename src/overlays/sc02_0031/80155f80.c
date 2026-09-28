/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155F80,80155FB0).
 * Offset 0x2DE28 at overlay base 80128158. SHA256(span)=192c3ee4a67404d330ad5190396da4ca848861c899446a5fabb90edd3b36b407.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155f80.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80155F80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154A74(s32 a0, s32 a1);

s32 func_80155F80(s32 a0)
{
    *(u32 *)(a0 + 0x44) = *(u32 *)(a0 + 0x44) & ~2;
    func_80154A74(a0, 0x11);
}
