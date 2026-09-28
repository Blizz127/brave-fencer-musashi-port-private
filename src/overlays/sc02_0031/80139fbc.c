/* SC02.CD FILE_031 / ov_SC02_031 retail span [80139FBC,80139FE8).
 * Offset 0x11E64 at overlay base 80128158. SHA256(span)=7590f66ead938872c85af603969e14fd3bb6ef8c74bdb40059b6512afd6c454b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80139fbc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139FBC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_80139FBC(struct obj *a0) {
    if (a0->unk8 & 0x800) {
        a0->unk8 &= ~0x800;
        a0->unk4 = 2;
    }
}
