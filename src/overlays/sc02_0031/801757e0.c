/* SC02.CD FILE_031 / ov_SC02_031 retail span [801757E0,80175820).
 * Offset 0x4D688 at overlay base 80128158. SHA256(span)=ba4bc21a2a19f8a6373e3bc217eacc85b69eecfff0b8f6f5e00a874898832caa.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801757e0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801757E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80176734(s32 a0);
extern void func_80176218(s32 a0);
extern void func_80176D00(s32 a0);

void func_801757E0(s32 a0) {
    s32 v = (s16)a0;
    func_80176734(v);
    func_80176218(v);
    func_80176D00(v);
}
