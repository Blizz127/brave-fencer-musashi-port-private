/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E40C,8015E4B0).
 * Offset 0x362B4 at overlay base 80128158. SHA256(span)=aae7b5ccea1320e9c9f79660205bb7c43e5986251a0c622fb4fdf3c57b18f2ee.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e40c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015E40C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80148534(s32 a0, s32 a1);
extern void func_80149374(s32 a0, s32 a1);

void func_8015E40C(s32 a0) {
    s32 s1 = a0;
    s32 s0;
    s16 sp10[4];
    u16 sp18[4];
    s0 = *(s32 *)(s1 + 0x18C);
    if (s0 == 0) {
        return;
    }
    if (*(u16 *)(s0 + 0x0) == 0) {
        return;
    }
    func_80148534((s32)sp10, (s32)sp18);
    *(s16 *)(s0 + 0x6) = sp18[0] + *(u16 *)(*(s32 *)(s0 + 0x78) + 0xC);
    *(s16 *)(s0 + 0xA) = sp18[1] + *(u16 *)(*(s32 *)(s0 + 0x78) + 0xE);
    *(s16 *)(s0 + 0xE) = sp18[2] + *(u16 *)(*(s32 *)(s0 + 0x78) + 0x10);
    func_80149374(s1, s0 + 0x4);
}
