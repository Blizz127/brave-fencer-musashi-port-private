/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013E410,8013E448).
 * Offset 0x162B8 at overlay base 80128158. SHA256(span)=5747f55c211b729438027f8db9372596b483e2569b430901eca2ef51c0e21a12.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013e410.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013E410 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_801202A0[];

s32 func_8013E410(void) {
    s32 a0;
    s32 v1;
    v1 = (s32)D_801202A0;
    for (a0 = 0; a0 < 0x60; a0++, v1 += 0x10C) {
        if (*(u16 *)v1 == 0) {
            return v1;
        }
    }
    return 0;
}
