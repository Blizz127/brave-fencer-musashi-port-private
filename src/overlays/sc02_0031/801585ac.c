/* SC02.CD FILE_031 / ov_SC02_031 retail span [801585AC,801585EC).
 * Offset 0x30454 at overlay base 80128158. SHA256(span)=ed53efcc6bf0ff69bbcb2633dc9e5fa537a1f7c7ad97db3a75255a0a1bbe664d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801585ac.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801585AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 func_80148800(s32 *a0);

s32 func_801585AC(s32 *a0) {
    u16 r = func_80148800(a0);
    u16 v = *(u16 *)((u8 *)a0 + 0x244) | r;
    s32 m;
    *(u16 *)((u8 *)a0 + 0x244) = v;
    m = v & 0x10;
    return m != 0;
}
