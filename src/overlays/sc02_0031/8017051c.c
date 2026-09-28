/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017051C,80170548).
 * Offset 0x483C4 at overlay base 80128158. SHA256(span)=3f094c4d97f80e6def3c3b920f5976a9126d0c4310ed91868b676e5d11fef8d4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017051c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017051C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_800AE6DC;
extern void func_80171928(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_8017051C(void *a0) {
    *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) = D_800AE6DC;
    func_80171928(a0);
}
