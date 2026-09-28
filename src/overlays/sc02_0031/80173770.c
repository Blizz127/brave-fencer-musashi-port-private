/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173770,801737B0).
 * Offset 0x4B618 at overlay base 80128158. SHA256(span)=2f6b2d359a60d047f30170ea4261c122ed8de66f5eca4a75de25ebfcb8618092.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173770.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80173770 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 D_80127508;
extern void func_801723C4(s32 a0, s32 a1);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);

void func_80173770(u8 *a0) {
    func_801723C4((s32)a0, D_80127508);
    func_80171A1C(a0);
    func_80174650((s32)a0);
}
