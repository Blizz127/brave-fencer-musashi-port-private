/* SC02.CD FILE_031 / ov_SC02_031 retail span [801601AC,801601E4).
 * Offset 0x38054 at overlay base 80128158. SHA256(span)=c01cdd4b11d44921a5f74be65884bbd0dc59ca74764d32617dc3404d95f9f6c3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801601ac.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801601AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154150(s32 a0, s32 a1);
extern void func_80146C98(s32 *a0, s16 a1);

void func_801601AC(s32 *a0) {
    func_80154150((s32)a0, 0x21);
    func_80146C98(a0, 1);
}
