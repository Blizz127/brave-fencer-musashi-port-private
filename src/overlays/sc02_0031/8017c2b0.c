/* Complete SC02 retail span [8017C2B0,8017C63C).
 * STOP state handler.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017C2B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { u16 f0; s16 f2; u16 f4; u16 f6; u16 f8; u16 fA; } Rec027_8017C2B0;
typedef struct { Rec027_8017C2B0 r[9]; } Blk027_8017C2B0;
extern void func_8012A568(void (*a0)(void));
extern s32 func_800291B4(s32 arg);
extern void func_8012CAE4(void *a0);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8001D074(s32 a0, s32 a1);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);

void func_8017C2B0(s32 a0) {

    extern u8 D_80188698[];
    extern u8 D_801886D4[];
    extern s32 D_801AC368;
    extern u16 D_801152BA;
    extern s16 D_80115214;
    extern s32 D_801B75A8;
    extern u8 D_801B75B4;
    extern u8 D_801B75B5;
    extern u8 D_801B75B6;
    extern u8 D_801B75C4;
    extern u8 D_801B75C5;
    extern u8 D_801B75C6;
    extern u8 D_801B75D5;
    extern u8 D_801B75D6;
    extern u8 D_801B75D8;
    extern u8 D_801B75D9;
    extern u8 D_801B75DA;
    extern u8 D_801B75DC;
    extern u8 D_801B75DD;
    extern u8 D_801B75DE;
    extern u8 D_801B75E4;
    /* 9 x 12-byte records = 0x6C bytes, alignment 2 */
    extern Blk027_8017C2B0 D_801AC390;
    extern Blk027_8017C2B0 D_801B7658[];

    u8 *v1;
    s32 s1;
    u8 *p;
    s32 t;
    s16 i;
    Blk027_8017C2B0 *dst;
    Blk027_8017C2B0 *tbl2;
    s32 idx;
    Blk027_8017C2B0 *tbl;
    s32 u;
    s32 w;

    v1 = *(u8 **)(a0 + 0xDC);
    if ((func_800291B4(v1[0] + 0x3A) & 0xFF) != 0) {
        func_8012CAE4((void *)a0);
        return;
    }

    if (*(s32 *)(a0 + 0x20) == 0) {
        if (func_8012C354(a0, (s32)D_80188698) == 0) {
            return;
        }
        func_8001C810(*(s32 *)(a0 + 0x20), (s32)&D_801AC368);
        func_8012A828(a0, (void *)&D_801886D4[(s16)D_801152BA * 16]);
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x2C) |= 0x20;
        *(s32 *)(*(s32 *)(a0 + 0x20) + 0x80) = (s32)&D_801B75A8;
        *(s32 *)(*(s32 *)(a0 + 0x20) + 0x4) |= 0x40000000;
        *(s16 *)(a0 + 0xAE) = -3;
    }

    s1 = ((s32 (*)(s32, s32))func_8001D074)(0x7E, 0x100);
    if (s1 == 0) {
        return;
    }

    p = &D_801B75D8;
    *(s32 *)(a0 + 0xCC) = s1;
    func_8001CD50(s1, (s32)p);

    D_801B75DA = 0x80;
    *p = 0x80;
    D_801B75D9 = 0xE0;
    D_801B75DD = 0;
    D_801B75DC = 0;
    D_801B75DE = 0;
    func_800233CC(p, 0x38);

    tbl = D_801B7658;
    idx = (s16)D_801152BA;
    dst = &tbl[idx];
    *(s16 *)(s1 + 0x10) = 0x400;
    *(s16 *)(s1 + 0x8) = *(u16 *)(a0 + 0x6);
    t = *(u16 *)(a0 + 0xA) - 4;
    *(u16 *)(a0 + 0xA) = t;
    *(s16 *)(s1 + 0xA) = t;
    *(s16 *)(s1 + 0xC) = *(u16 *)(a0 + 0xE);
    *(s32 *)(s1 + 0x4) |= 0x50000000;

    D_801B75D6 = 0xFF;
    D_801B75E4 = 0xFF;
    D_801B75C6 = 0xFF;
    D_801B75C4 = 0xFF;
    D_801B75B6 = 0xFF;
    D_801B75B4 = 0xFF;
    D_801B75D5 = 0x80;
    D_801B75C5 = 0x80;
    D_801B75B5 = 0x80;

    *dst = D_801AC390;

    i = 5;
    tbl2 = D_801B7658;
    *(s32 *)(a0 + 0xD8) = (s32)&tbl2[(s16)D_801152BA];

    while (i < 0x28) {
        if ((func_800291B4(i + 0x3B) & 0xFF) != 0) {
            break;
        }
        i++;
    }
    if (i != 0x28) {
        *(s16 *)(a0 + 0x10A) = 1;
    }

    w = D_801152BA + 1;
    u = *(u16 *)(a0 + 0x2) + 1;
    D_80115214 = 0;
    D_801152BA = w;
    *(u16 *)(a0 + 0x2) = u;
}
