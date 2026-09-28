/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012F87C,8012F8C8).
 * Offset 0x7724 at overlay base 80128158. SHA256(span)=e8d6a62c27860c5a97e9050f912d96391f2ea121eeffa1bef7fcb0ab1216144a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012f87c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012F87C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80131340(s32 a0);
extern void func_80131CA8(int a0, int a1);

void func_8012F87C(s32 a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x8) {
        func_80131340(a0);
    }
    func_80131CA8(a0, 0xA);
}
