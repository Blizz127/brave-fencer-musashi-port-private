/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E22C,8015E288).
 * Offset 0x360D4 at overlay base 80128158. SHA256(span)=8187bb72598a52a40ae7a4caf12fe13056a828bb5e7ffaabf1698ebc2b5e2fcc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e22c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015E22C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80146CA0(void *a0);
extern u8 D_800D4FF4[];

void func_8015E22C(s32 a0) {
    func_80154274((s32 *)a0, (s32)D_800D4FF4);
    *(s32 *)(a0 + 0x234) = 0;
    func_80146994(5, a0, 0xA, 0);
    *(s32 *)(a0 + 0x44) |= 2;
    func_80146CA0((void *)a0);
}
