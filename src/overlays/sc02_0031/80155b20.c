/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155B20,80155B9C).
 * Offset 0x2D9C8 at overlay base 80128158. SHA256(span)=c12ace7c8f1a07bb8427bea40be1c92cbfd204227ce65428ccb2b3811775ae7d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155b20.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80155B20 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_80161208();
extern void func_80146D80(s32 *a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern u8 D_800D4DA8[];

void func_80155B20(s32 *a0) {
    a0[0x44 / 4] |= 2;
    if (func_80161208() == 0) {
        if (*(u16 *)((char *)a0 + 0xB8) == 0x8000) {
            func_80146D80(a0);
            func_801477E8(a0, 0xFFF00000);
            func_80154274(a0, (s32)D_800D4DA8);
            func_80146CA0(a0);
        }
    }
}
