/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161488,801614E4).
 * Offset 0x39330 at overlay base 80128158. SHA256(span)=4f210483d38dbcb322e5c52f5403fcc42cb74e8fae2e56702332f548664ad007.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161488.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161488 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801615C4(void *a0, s32 a1);
extern s32 func_80161774(int param_1, u32 param_2);
extern s32 func_8016197C(s32 a0, s32 a1);

s32 func_80161488(void *a0) {
    s32 v0 = func_801615C4(a0, 0);
    if (*(u8 *)((u8 *)a0 + 0x1C6) == 0) {
        func_80161774(a0, v0);
    } else {
        return func_8016197C((s32)a0, v0) & -0x8;
    }
    /* fall off end: returns clobbered v0 (matches original) */
}
