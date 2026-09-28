/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012931C,80129350).
 * Offset 0x11C4 at overlay base 80128158. SHA256(span)=8ba7a8502e27791f8b1444b8d8f5f268230990dbe4372e0a27587eb9b2b6ea56.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012931c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012931C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_8012931C(struct vec *a0) {
    a0->unk4 += a0->unk10;
    a0->unk8 += a0->unk14;
    a0->unkC += a0->unk18;
}
