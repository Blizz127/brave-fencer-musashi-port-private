/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179B28,80179B74).
 * Offset 0x519D0 at overlay base 80128158. SHA256(span)=22c55799b84cd85e387a220afb6edb591027ca4dd0663d99df955f94d27e51c6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179b28.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80179B28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80139914(s32 a0);

void func_80179B28(s32 a0) {
    s32 v1;
    if (a0 == 0) return;
    if (*(s32 *)a0 == 0) return;
    v1 = *(s16 *)(a0 + 4);
    if (v1 == 0) return;
    if (v1 == 0xE) return;
    func_80139914(a0);
}
