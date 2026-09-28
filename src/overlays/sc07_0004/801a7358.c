/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A7358 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char c[4]; } Blk4_801A7358;
extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C2C4(s32 a0);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8004945C(s32, s32, void*);
extern s32 func_8001D074(s32, s32);
extern void func_800233CC(void *a0, unsigned short a1);
extern void func_8001CD9C(s32, s32);
extern int func_801AF9C8(short *pos, int a1, int a2);
extern void func_8012AD50(void *a0);
extern u8 D_801B0360[];
extern Blk4_801A7358 *D_801B0358[];
extern Blk4_801A7358 D_801A01E8;
extern Blk4_801A7358 D_801F88B8;
extern Blk4_801A7358 D_801F88BC;
extern Blk4_801A7358 D_801F88F8;
extern Blk4_801A7358 D_801F88FC;
extern Blk4_801A7358 D_801F8938;
extern Blk4_801A7358 D_801F893C;

void func_801A7358(u8 *s2)
{
    Blk4_801A7358 *s3;
    register s32 s1 __asm__("$17");
    register void *s0 __asm__("$16");
    s32 v0;
    s32 t;
    u16 idx;
    s32 p;
    u16 sv[4];
    s32 flag;

    v0 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)(s2 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(s2);
        return;
    }

    func_8001C2C4(v0);
    t = *(s32 *)(s2 + 0x20);
    *(s16 *)(t + 0x1A) = 0x400;
    *(s16 *)(t + 0x18) = 0x400;
    func_8004914C((void *)(*(s32 *)(*(s32 *)(s2 + 0x64) + 0x20) + 0x34));
    func_800491AC((void *)(*(s32 *)(*(s32 *)(s2 + 0x64) + 0x20) + 0x34));
    ((void (*)(void *, void *, void *))func_8004945C)(D_801B0360, sv, &flag);
    *(u16 *)(s2 + 0x6) = sv[0];
    *(u16 *)(s2 + 0xA) = sv[1];
    *(u16 *)(s2 + 0xE) = sv[2];
    idx = *(u16 *)(s2 + 0x70) & 1;
    *(u16 *)(s2 + 0x70) = idx;
    s3 = D_801B0358[idx];

    s1 = ((s32 (*)(s32, s32))func_8001D074)(0x7E, 0x100);
    if (s1 != 0) {
        *(s32 *)(s2 + 0xCC) = s1;
        s0 = &D_801F88B8;
        func_800233CC(s0, 0x80);
        D_801F88B8 = s3[0];
        D_801F88BC = D_801A01E8;
        ((void (*)(s32, void *))func_8001CD9C)(s1, s0);
        *(u16 *)(s1 + 0x2C) = 0xC020;
        *(s32 *)(s1 + 4) = 0x50000000;
    }

    s1 = ((s32 (*)(s32, s32))func_8001D074)(0x7E, 0x100);
    if (s1 != 0) {
        *(s32 *)(s2 + 0xD0) = s1;
        s0 = &D_801F88F8;
        func_800233CC(s0, 0x60);
        D_801F88F8 = s3[1];
        D_801F88FC = D_801A01E8;
        ((void (*)(s32, void *))func_8001CD9C)(s1, s0);
        *(u16 *)(s1 + 0x2C) = 0xC020;
        *(s32 *)(s1 + 4) = 0x50000000;
    }

    s1 = ((s32 (*)(s32, s32))func_8001D074)(0x7E, 0x100);
    if (s1 != 0) {
        *(s32 *)(s2 + 0xD4) = s1;
        s0 = &D_801F8938;
        func_800233CC(s0, 0xB0);
        D_801F8938 = s3[2];
        D_801F893C = s3[2];
        ((void (*)(s32, void *))func_8001CD9C)(s1, s0);
        *(u16 *)(s1 + 0x2C) = 0xC01E;
        *(s32 *)(s1 + 4) = 0x50000000;
        *(s16 *)(s1 + 0x1E) = 0xD00;
    }

    sv[3] = 0x1A;
    p = func_801AF9C8((short *)sv, 0, 0x404040);
    if (p != 0) {
        *(s32 *)(s2 + 0xD8) = p;
        *(s16 *)(*(s32 *)(p + 0x20) + 0x18) = 0x1C00;
    }
    *(s32 *)(s2 + 0x14) = 0xFFE00000;
    *(s32 *)(s2 + 0x1C) = 0x18;
    func_8012AD50(s2);
}
