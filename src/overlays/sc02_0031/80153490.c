/* SC02.CD FILE_031 / ov_SC02_031 retail span [80153490,801534D8).
 * Offset 0x2B338 at overlay base 80128158. SHA256(span)=b4e0e0850664001251e336a14153896e02d9a233c0b4c827e284a10650c755e1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80153490.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153490 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149020(s32 *a0);
extern s32 func_801536DC(s32 a0);
extern void func_80146CA0(void *a0);

void func_80153490(s32 a0) {
    func_80149020((s32 *)a0);
    if (!func_801536DC(a0)) {
        *(s8 *)(a0 + 0xDE) = 1;
        *(s8 *)(a0 + 0xDF) = 0;
        func_80146CA0((void *)a0);
    }
}
