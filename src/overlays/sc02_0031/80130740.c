/* SC02.CD FILE_031 / ov_SC02_031 retail span [80130740,801307B0).
 * Offset 0x85E8 at overlay base 80128158. SHA256(span)=fd4f52484dd380823c2d3402c49351f0ad6de298ad64921d249fcb3017d69ff4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80130740.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80130740 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_80130740(void *a0, u16 *a1) {
    u16 *p = (u16 *)a0;
    func_80146A6C(0x10, a0,
                  (s16)(p[3] + a1[0]),
                  (s16)(p[5] + a1[1]),
                  (s16)(p[7] + a1[2]),
                  0, 0);
}
