/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012F91C,8012F968).
 * Offset 0x77C4 at overlay base 80128158. SHA256(span)=059acd0c77fe561288529916c2fb956232677580fe821eaf2275dd8075010b0b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012f91c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012F91C - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_8012F91C(s32 a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x80) {
        func_80131340(a0);
    }
    func_80131CA8(a0, 0x17);
}
