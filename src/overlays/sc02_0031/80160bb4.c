/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160BB4,80160C28).
 * Offset 0x38A5C at overlay base 80128158. SHA256(span)=2fb1ec4fc8e65d3155653075682ddda3d42216a7a2bac5db480756e7db898b45.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160bb4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160BB4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801553A8(s32 *a0);
extern void func_80155440(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);

void func_80160BB4(s32 *a0) {
    s32 *v1;
    a0[0x44 / 4] |= 0x80;
    func_801553A8(a0);
    func_80155440(a0);
    func_80154150((s32)a0, 0x26);
    func_80154A74((s32)a0, 0x1E);
    v1 = (s32 *)a0[0x20 / 4];
    a0[0x234 / 4] = 0;
    *(s16 *)((u8 *)v1 + 0x10) = 0xFE9;
    a0[0x238 / 4] = 0;
    func_80146CA0(a0);
}
