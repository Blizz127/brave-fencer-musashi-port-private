/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013E22C,8013E298).
 * Offset 0x160D4 at overlay base 80128158. SHA256(span)=32cf9632f14fb7a86368fd2ca8d976a0e6605926fe4af1e7a01995e189c90c39.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013e22c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013E22C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct VecA {
    s16 unk0;
    s16 unk2;  /* x */
    s16 unk4;
    s16 unk6;  /* y */
    s16 unk8;
    s16 unkA;  /* z */
};
struct VecB {
    s16 unk0;  /* x */
    s16 unk2;  /* y */
    s16 unk4;  /* z */
};
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_800492FC(s32 *a0, s32 *a1);

s32 func_8013E22C(struct VecA *a0, struct VecB *a1) {
    s32 d[3];
    s32 sq[3];
    d[0] = a0->unk2 - a1->unk0;
    d[1] = a0->unk6 - a1->unk2;
    d[2] = a0->unkA - a1->unk4;
    func_800492FC(d, sq);
    return sq[0] + sq[1] + sq[2];
}
