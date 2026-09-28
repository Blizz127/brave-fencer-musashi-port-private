/* SC02.CD FILE_031 / ov_SC02_031 retail span [80130650,80130740).
 * Offset 0x84F8 at overlay base 80128158. SHA256(span)=fcd5ee43bbb4dfd7142543982f3e93f165f75f6e2ead7727c7cf2b07d53f0af5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80130650.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80130650 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_801319E0(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012CBF4(s32);
extern s32 func_80131D68(s32 a0, s32 a1);
extern void func_80131C78(s32 a0);
extern void func_80131CA8(int a0, int a1);

void func_80130650(s32 a0) {
    s32 s1;
    if (*(s32 *)(a0 + 0xB4) & 0x1000) {
        if (*(s16 *)(a0 + 0xA) >= 0x10) {
            func_801319E0(a0);
            return;
        }
        if (func_8012BEE8(a0) != 0) {
            func_801319E0(a0);
            return;
        }
        if (*(s32 *)(a0 + 0xC4) & 0x4) {
            s32 v1 = *(s32 *)(a0 + 0x20);
            *(s16 *)(v1 + 0x10) = *(u16 *)(v1 + 0x10) - 0x100;
        }
        s1 = ((s32 (*)(s32))func_8012CBF4)(a0);
        if (func_80131D68(a0, s1) == 1) {
            return;
        }
        if (s1 & 0x2000) {
            func_80131C78(a0);
        }
    }
    func_80131CA8(a0, 0x23);
}
