/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155518,8015554C).
 * Offset 0x2D3C0 at overlay base 80128158. SHA256(span)=16cc54d2c1e856887ed9ff0edffe37d01263fdb7226440458d9288b622718cf7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155518.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80155518 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_801555F4(void *a0);

void func_80155518(s32 *a0) {
    func_80147078(a0, 5);
    func_801555F4(a0);
}
