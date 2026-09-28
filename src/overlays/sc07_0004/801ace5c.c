/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ACE5C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_801ADD98(u8 *a0, volatile u8 *a1, volatile u8 *a2);
extern s32 func_8001D074(s32 a0, s32 a1);
extern void func_800233CC(void *a0, unsigned short a1);
extern void func_8001CD9C(s32 a0, s32 a1);
extern void func_8012AD50(void *a0);
extern u8 D_801F0C90[];
extern u8 D_801F8A78[];
extern u8 D_801F8AB8[];
extern u8 D_801F8AE8[];
extern s32 D_801F8D18;
extern s32 D_801F8D1C;
extern s32 D_801F8D58;
extern s32 D_801F8D5C;

void func_801ACE5C(void *a0) {
    /* §160a / §48-C2: align-1 4-byte block copy => lwl/lwr + swl/swr */
    typedef struct { char c[4]; } Blk4;
    extern s32 D_801A0218;
    extern s32 D_801A021C;
    extern s32 D_801A0220;

    s32 v0;
    s32 v1;
    s32 s1;
    s32 t;
    void *p;

    v0 = func_8012C1B8();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
        return;
    }
    func_8001C214(v0, (s32)D_801F0C90);

    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x2C) |= 0x10;
    *(s32 *)(*(s32 *)((s32)a0 + 0x20) + 0x4) |= 0x40;

    v1 = *(s32 *)((s32)a0 + 0x20);
    *(s16 *)(v1 + 0x1C) = 0x200;
    *(s16 *)(v1 + 0x18) = 0x200;

    *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1A) = 0x300;

    t = *(u16 *)(*(s32 *)((s32)a0 + 0x64) + 0xA);
    *(u16 *)((s32)a0 + 0xE) += 0x20;
    *(s16 *)((s32)a0 + 0x52) = -0x200 - t;
    func_801ADD98(D_801F8A78, D_801F8AB8, D_801F8AE8);

    s1 = func_8001D074(0x7E, 0x100);
    *(s32 *)((s32)a0 + 0xCC) = s1;
    if (s1 != 0) {
        p = (void *)&D_801F8D18;
        func_800233CC(p, 0x80);
        *(Blk4 *)p = *(Blk4 *)&D_801A0218;
        *(s32 *)((s32)a0 + 0xE0) = 0x20C;
        *(Blk4 *)&D_801F8D1C = *(Blk4 *)&D_801A021C;
        func_8001CD9C(s1, (s32)p);
        *(u16 *)(s1 + 0x2C) = 0xC100;
        *(s32 *)(s1 + 0x4) = 0x50000000;
    }

    s1 = func_8001D074(0x7E, 0x100);
    *(s32 *)((s32)a0 + 0xD0) = s1;
    if (s1 != 0) {
        p = (void *)&D_801F8D58;
        func_800233CC(p, 0x60);
        *(Blk4 *)p = *(Blk4 *)&D_801A0220;
        *(s32 *)((s32)a0 + 0xE4) = 0xC02;
        *(Blk4 *)&D_801F8D5C = *(Blk4 *)&D_801A021C;
        func_8001CD9C(s1, (s32)p);
        *(u16 *)(s1 + 0x2C) = 0xC100;
        *(s32 *)(s1 + 0x4) = 0x50000000;
    }

    *(s32 *)((s32)a0 + 0x1C) = 0x10;
    func_8012AD50(a0);
}
