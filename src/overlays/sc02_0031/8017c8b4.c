/* Complete SC02 retail span [8017C8B4,8017C9FC).
 * Sibling state handler.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017C8B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8001D074(s32 a0, s32 a1);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern void func_80049A1C(void *a0, void *a1);

void func_8017C8B4(s32 a0) {

    extern u8 D_801B7618;
    extern u8 D_801B7619;
    extern u8 D_801B761A;
    extern u8 D_801B761C;
    extern u8 D_801B761D;
    extern u8 D_801B761E;
    extern s32 D_801B781C[];
    s32 v0;
    u8 *p;
    s16 sp[8];

    v0 = ((s32 (*)(s32, s32))func_8001D074)(0x7E, 0x100);
    if (v0 == 0) {
        return;
    }

    p = &D_801B7618;
    *(s32 *)(a0 + 0xD0) = v0;
    func_8001CD50(v0, (s32)p);

    D_801B7619 = 0xFF;
    D_801B761A = 0xFF;
    *p = 0xFF;
    D_801B761E = 8;
    D_801B761C = 8;
    D_801B761D = 0x18;
    func_800233CC(p, 0x100);

    sp[0] = *(u16 *)(a0 + 0x6);
    sp[1] = *(u16 *)(a0 + 0xA) - 0x38;
    sp[2] = *(u16 *)(a0 + 0xE);
    func_800D20C0(&sp[0], &sp[4], 5);

    D_801B781C[0] = sp[0];
    D_801B781C[1] = sp[1];
    D_801B781C[2] = sp[2];
    func_800D23D0(&sp[4]);
    func_80049A1C(&sp[4], &D_801B781C[-5]);

    *(s32 *)(v0 + 0x34) = (s32)&D_801B781C[-5];
    *(s16 *)(v0 + 0x1A) = 0;
    *(s16 *)(v0 + 0x18) = 0;
    *(s32 *)(v0 + 0x4) |= 0x50000000;
    *(u16 *)(a0 + 0x2) += 1;
}
