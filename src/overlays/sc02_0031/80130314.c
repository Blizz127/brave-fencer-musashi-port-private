/* SC02.CD FILE_031 / ov_SC02_031 retail span [80130314,80130360).
 * Offset 0x81BC at overlay base 80128158. SHA256(span)=ed7a7d57704a070b254621493ec5b2a25bee7c0d9f820fccf853e88702fd050c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80130314.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80130314 - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_80130314(s32 a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x800) {
        func_80131340(a0);
    }
    func_80131CA8(a0, 0x2D);
}
