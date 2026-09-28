/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012EF34,8012EF70).
 * Offset 0x6DDC at overlay base 80128158. SHA256(span)=4cb13accf1934c32192d833a34a46be0cc01885b0ceca1603f82feaabaa09caf.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012ef34.c (recovery=assembly, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012EF34 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012EFB8(s32 a0);

void func_8012EF34(s32 a0, s32 a1) {
    s32 sp10;
    register s32 v1 __asm__("$3");
    func_8012EFB8(a0);
    {
        register s32 *p __asm__("$3") = &sp10;
        __asm__ __volatile__("swc2 $19, 0(%0)" : : "r"(p) : "memory");
    }
    v1 = sp10;
    *(s16 *)(a1 + 4) = v1;
}
