/* SC02.CD FILE_031 / ov_SC02_031 retail span [801685EC,80168640).
 * Offset 0x40494 at overlay base 80128158. SHA256(span)=c1bacffacf0cb151cda0a3d0fcadbffc31471bb8afe4b6db72ffc43cbd808a03.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801685ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801685EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80166994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80166690();
extern void func_80146C3C();

void func_801685EC(s32 a0) {
    func_80166994(a0, 2, 2, 0);
    if ((short)func_80166690(2, 1) == 0) {
        ((void (*)(s32))func_80146C3C)(a0);
    }
}
