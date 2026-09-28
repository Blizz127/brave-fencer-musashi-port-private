/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012BD14,8012BD3C).
 * Offset 0x3BBC at overlay base 80128158. SHA256(span)=37cd07265e696dea55ca8bba2721a9e1215f86caf81fdeb1feb04b4fe38073e2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012bd14.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012BD14 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80013350(s32 a0, void *a1);
extern u8 D_80126B5C;

void func_8012BD14(s32 a0) {
    func_80013350(a0 + 4, &D_80126B5C);
}
