/* Complete SC02 retail span [8017F24C,8017F3C0).
 * Live STOP 7ECB0 cluster; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017F24C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80178B18(s32 param_1, s32 param_2);
extern s32 func_8012E778(s32 param_1, s32 param_2);
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
extern s32 func_801439C0(s32 a0);
extern void func_8012C218(void*);

void func_8017F24C(s32 a0)
{

    extern u8 D_80078E78[];
    extern s32 D_80188BF4;
    s32 s0 = a0;
    u8 *v1 = D_80078E78;
    s32 v0;

    if (*(s16 *)((u8 *)s0 + 0x100) != 0) {
        goto L_8017D524;
    }

    if (*(u16 *)((u8 *)s0 + 0x5E) == 0) {
        goto L_8017D524;
    }

    func_80178B18(s0, (s32)&D_80188BF4);
    *(s16 *)((u8 *)s0 + 0x100) = 1;
    *(s16 *)((u8 *)s0 + 0x2) = 8;
    return;

L_8017D524:
    v0 = (s32)*(u16 *)((u8 *)v1 + 0x1A);
    v0 = v0 - 0x12C;

    if (((u16)v0) < 0x3FC) {
        goto L_8017D57C;
    }

    if (func_8012E778(s0, 0x9000B8) != 0) {
        goto L_8017D57C;
    }

    if (func_8012C658(0x1F8, *(s16 *)((u8 *)s0 + 0x70), s0) == 0) {
        return;
    }

    func_801439C0(*(s32 *)((u8 *)s0 + 0xCC));
    ((void (*)(s32))func_8012C218)(s0);

L_8017D57C:
    if (*(u16 *)((u8 *)s0 + 0x5E) == 0) {
        return;
    }

    v0 = *(s32 *)((u8 *)s0 + 0x1C);
    v0 = v0 + 1;
    *(s32 *)((u8 *)s0 + 0x1C) = v0;

    if (v0 < 0x10) {
        return;
    }

    *(u16 *)((u8 *)s0 + 0x5E) = 0;
    *(s32 *)((u8 *)s0 + 0x1C) = 0;
}
