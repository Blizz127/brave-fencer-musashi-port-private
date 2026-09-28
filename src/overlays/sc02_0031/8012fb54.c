/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012FB54,8012FC30).
 * Offset 0x79FC at overlay base 80128158. SHA256(span)=c781d8e87f9aa4bf40536cd7163f66de1d5263606aab58b86cfbe58619e90e68.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012fb54.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012FB54 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern s32 func_80143B6C(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80131CA8(int a0, int a1);

void func_8012FB54(s32 a0) {
    s32 s0 = a0;
    s32 v1;
    s32 p;
    if ((*(s32 *)(s0 + 0xB4) & 0x10000) != 0) {
        *(s32 *)(s0 + 0x4) = *(s32 *)(s0 + 0x4) + *(s32 *)(s0 + 0x10);
        *(s32 *)(s0 + 0x8) = *(s32 *)(s0 + 0x8) + *(s32 *)(s0 + 0x14);
        *(s32 *)(s0 + 0xC) = *(s32 *)(s0 + 0xC) + *(s32 *)(s0 + 0x18);
        v1 = *(s32 *)(s0 + 0x1C) - 1;
        *(s32 *)(s0 + 0x1C) = v1;
        if (v1 == 0) {
            func_801319E0(s0);
        } else {
            p = func_80143B6C(s0, 1);
            if (p != 0) {
                *(s16 *)(p + 0xA) = *(u16 *)(p + 0xA) + *(u16 *)(s0 + 0xAC);
            }
            if (*(s32 *)(s0 + 0x1C) == 0x13) {
                func_8002D4C8(0x8F2, 0);
            }
        }
    }
    func_80131CA8(s0, 0x36);
}
