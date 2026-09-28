/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016236C,801623B8).
 * Offset 0x3A214 at overlay base 80128158. SHA256(span)=ed2a2f3a9f3819472a67366fb4e3ab93514c15766ba0e9d3e20669d11d6a1fac.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016236c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016236C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014706C(void *a0);
extern s32 D_80126B58;

s32 func_8016236C(u8 *a0) {
    func_8014706C(&D_80126B58);
    *(s32 *)(a0 + 0x28) = 0xA;
    *(u8 *)(a0 + 0x15) += 1;
    return 0;
}
