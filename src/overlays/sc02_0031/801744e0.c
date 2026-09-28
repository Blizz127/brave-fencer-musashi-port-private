/* SC02.CD FILE_031 / ov_SC02_031 retail span [801744E0,80174524).
 * Offset 0x4C388 at overlay base 80128158. SHA256(span)=8ba433cee5f6cc958872a8d13e009b94c400b1a1f033c9e657e6fbe6017beaea.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801744e0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801744E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_800D1724(s32 a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s32 D_80127508;

void func_801744E0(u8 *a0) {
    func_800D1724(D_80127508);
    func_80171A1C(a0);
    func_80174650((s32)a0);
}
