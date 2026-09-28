/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015B8F8,8015B950).
 * Offset 0x337A0 at overlay base 80128158. SHA256(span)=14e4f16788957fc1996316229c8df6d1a8361e4ac4260a64ceecfba95e402c85.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015b8f8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015B8F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801542DC(s32 *a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern s32 D_800D4A9C;
extern s32 D_800D4B48;

void func_8015B8F8(s32 *a0) {
    s32 v = *(s32 *)((s32)a0 + 0x23C);
    if (v == (s32)&D_800D4A9C || v == (s32)&D_800D4B48) {
        ((void (*)(s32 *, s32, s32))func_801542DC)(a0, v, *(u8 *)((s32)a0 + 0x244));
    } else {
        func_80154150((s32)a0, 0xF);
    }
}
