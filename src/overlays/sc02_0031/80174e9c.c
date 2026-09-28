/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174E9C,80174ED4).
 * Offset 0x4CD44 at overlay base 80128158. SHA256(span)=c2f8845c2a67b807aca5fd18b0d71176591bd385334989ae34db520d973110b8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174e9c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174E9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8012A018(s32 a, s32 b);
extern s32 D_8012697C;
extern u16 D_80126980;
extern s32 func_80174F28(void *a0);

void func_80174E9C(s32 a0) {
    D_8012697C = a0;
    D_80126980 = 0;
    func_8012A018((s32)func_80174F28, 0);
}
