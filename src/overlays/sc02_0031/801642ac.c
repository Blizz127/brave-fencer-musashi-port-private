/* SC02.CD FILE_031 / ov_SC02_031 retail span [801642AC,8016432C).
 * Offset 0x3C154 at overlay base 80128158. SHA256(span)=a8a73b7d559aedc0b0ee7254c8db7660970b8a9886b1c189514cafcdffe90743.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801642ac.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801642AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80164418();
extern s32 func_80013328(s32 a0, s32 a1);
extern s32 func_80146E98(s32 a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);
extern s32 func_80163764(s32 a0);

void func_801642AC(s32 a0) {
    s32 s1 = a0;
    s32 s0 = *(s32 *)(s1 + 0x4C);
    func_80164418();
    if (func_80013328(s0 + 4, s1 + 4) < 0x28 || func_80146E98(s1) != 0) {
        func_80146E90((s32 *)s1, 8);
        func_80147324(0x44A);
        func_80146CA0((void *)s1);
    }
    func_80163764(s1);
}
