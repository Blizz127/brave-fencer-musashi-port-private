/* SC02.CD FILE_031 / ov_SC02_031 retail span [801726A0,801726AC).
 * Offset 0x4A548 at overlay base 80128158. SHA256(span)=912aced3db7096fd80fe1a6654663cc047b7e8f028544893938c913b2eed2923.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801726a0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801726A0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_801726A0(s32 *a0) {
    return *(s32*)((s32)a0 + 0x1F4) & 0x40;
}
