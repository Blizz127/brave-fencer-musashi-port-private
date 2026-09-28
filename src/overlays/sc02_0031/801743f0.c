/* SC02.CD FILE_031 / ov_SC02_031 retail span [801743F0,80174430).
 * Offset 0x4C298 at overlay base 80128158. SHA256(span)=26b637a7ec5f914932ed3c9d2062a9b5533b82c125ad22f5363899593f4d4bea.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801743f0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801743F0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80172658(s32 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);

void func_801743F0(u8 * a0)
{
    if (func_80172658(a0)) {
        func_80171A1C((u8 *)a0);
        func_80174650((s32)a0);
    }
}
