/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015CC0C,8015CC40).
 * Offset 0x34AB4 at overlay base 80128158. SHA256(span)=0c3438516d31d1fb372e5ba2dad197a4c901e45d590da10b9647b0c3d7ff3f4f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015cc0c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015CC0C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_8015CCD0();

void func_8015CC0C(s32 *param_1) {
    func_80147078(param_1, 0xB);
    func_8015CCD0(param_1);
}
