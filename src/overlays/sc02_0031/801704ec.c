/* SC02.CD FILE_031 / ov_SC02_031 retail span [801704EC,8017051C).
 * Offset 0x48394 at overlay base 80128158. SHA256(span)=e3a13e33a61877cb80482a350f936331f2a31f6760c8281d3ad6f2de24759d48.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801704ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801704EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80171990(u8 *a0);
extern void func_8017051C(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_801704EC(u8 *a0) {
    func_80171990(a0);
    func_8017051C(a0);
}
