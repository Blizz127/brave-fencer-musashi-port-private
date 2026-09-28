/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160F70,80160FE0).
 * Offset 0x38E18 at overlay base 80128158. SHA256(span)=b2226e4c2b244f0d1bb8599a77c3bd02e2ec638c507c0cb7bcc0ebb4b526221d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160f70.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160F70 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80146E98(s32 a0);
extern void func_800D0F4C(s32 a0);
extern void func_8014BB24(s32 a0, s32 a1, s32 a2);
extern void func_8014BD24(s32 a0, s32 a1);
extern s32 func_8013767C(s32 a0);
extern void func_80146CA0(void *a0);
extern u8 D_80110EC0;

void func_80160F70(s32 a0) {
    if (func_80146E98(a0) != 0) {
        func_800D0F4C(0xA);
        func_8014BB24(a0, 0x96, 0);
        func_8014BD24(a0, 0x96);
        *(s32 *)(a0 + 0x198) = func_8013767C(&D_80110EC0);
        func_80146CA0((void *)a0);
    }
}
