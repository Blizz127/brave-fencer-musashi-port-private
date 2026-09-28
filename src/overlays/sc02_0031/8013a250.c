/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013A250,8013A2BC).
 * Offset 0x120F8 at overlay base 80128158. SHA256(span)=bf0ea38a9b730bdbb4a65726db10a45142f7ad6bfeb317c4bcec1ab874d93112.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013a250.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013A250 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S8013A250 {
    u8 pad8[8];
    s32 unk8;      /* 0x8 */
    u8 unkC;       /* 0xC */
};
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);
extern void func_80138B88(s32 a0);

void func_8013A250(struct S8013A250 *a0) {
    if (a0->unkC != 0) {
        a0->unkC = a0->unkC - 1;
        func_80139A8C((s32)a0);
        if ((a0->unk8 & 0x80020) == 0) {
            func_80139B18((s32)a0);
            return;
        }
    }
    func_80138B88((s32)a0);
}
