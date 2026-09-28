/* SC02.CD FILE_031 / ov_SC02_031 retail span [801699D0,80169A4C).
 * Offset 0x41878 at overlay base 80128158. SHA256(span)=2aeb80a4d36bd304f2e8705fa948350326320e93bdad663aac737089eb4c063d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801699d0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801699D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80169A4C(s32 a0, s32 a1);
extern void func_800D22E4(s32 a0);
extern void func_80146C3C();

void func_801699D0(void *arg0) {
    s32 temp_v1;
    temp_v1 = *(s32 *)((u8 *)arg0 + 0x1C);
    if (temp_v1 < 0xF) {
        *(s32 *)((u8 *)arg0 + 0x30) = 0xC0 - temp_v1 * 8;
        func_80169A4C((s32)arg0, (s32)arg0 + 0x38);
        func_800D22E4((s32)arg0);
        *(s32 *)((u8 *)arg0 + 0x14) = *(s32 *)((u8 *)arg0 + 0x14) + 0x10000;
        *(s32 *)((u8 *)arg0 + 0x1C) = *(s32 *)((u8 *)arg0 + 0x1C) + 1;
    } else {
        ((void (*)(s32))func_80146C3C)((s32)arg0);
    }
}
