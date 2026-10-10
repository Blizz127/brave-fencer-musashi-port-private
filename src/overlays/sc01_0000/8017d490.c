/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017D490 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32  func_800149E0(s32);
extern void func_800D1724(s32);
extern void func_8017D164(u16 *arg0, u16 *arg1);
extern void func_8002D4C8(s32, s32);
extern void func_80174E9C(s32);
extern s32  func_80174ED4(void);
extern void func_8017DD04();
extern s32  func_8017E210();
extern void func_8017E3A0();
extern void func_8017E4A0(void);
extern void func_8017E594(s32 arg0, s32 arg1, s32 arg2, u8 arg3);
extern u8  D_80126948[];
extern s16 D_80182618[];
extern s16 D_8018263C[];
extern u8  D_801A1E94[];
extern u8  D_801A2770[];
extern s32 D_801A585C;
extern s32 D_801A5718;
extern u16 D_801A571A;
extern s32 D_801A571C;
extern u16 D_801A571E;
extern s32 D_801A5720;
#define D_801A5722 (*(s16 *)((u8 *)&D_801A5720 + 2))
extern u16 D_801A5724;
extern u16 D_801A5726;
extern s16 D_801A5728;
extern u16 D_801A572C;
extern u16 D_801A572E;
extern s16 D_801A5730;
extern s32 D_801A5734;
extern s32 D_801A5738;
extern s32 D_801A573C;
extern s32 D_801A5740;
extern s32 D_801A5744;
extern s32 D_801A5748;
extern s32 D_801A574C;
#define D_801A574E (*(s16 *)((u8 *)&D_801A574C + 2))
extern s32 D_801A5750;
#define D_801A5752 (*(s16 *)((u8 *)&D_801A5750 + 2))
extern s32 D_801A5754;
extern s32 D_801A5758;
extern s32 D_801A575C;
#define D_801A575E (*(s16 *)((u8 *)&D_801A575C + 2))
extern s32 D_801A5760;
#define D_801A5762 (*(s16 *)((u8 *)&D_801A5760 + 2))
extern s32 D_801A5764;
extern s32 D_801A5768;
extern s32 D_801A576C;
extern s32 D_801A5770;

void func_8017D490(void)
{
    register s32 v __asm__("$2");
    u16 *q0;
    u16 *q1;
    s32 *r0;
    s32 *r1;
    s32 *r2;
    s32 *r3;
    u8 *p;

    v = func_800149E0(0);
    p = D_80126948;
    if ((D_801A585C < 0xE) && (v & 0x840)) {
        func_800D1724((s32)D_8018263C);
        D_801A585C = 0xF;
    }

    switch (D_801A585C) {
    case 0:
        q0 = &D_801A5724;
        q1 = &D_801A572C;
        *(s32 *)(p + 8) = 0x190;
        D_801A5718 = 0xFB550000;
        D_801A571C = 0xFAC10000;
        *q0 = 0x4C8;
        D_801A5728 = -0x18C;
        *q1 = 0x151;
        D_801A5730 = -0x18C;
        D_801A5726 = D_801A571A;
        D_801A572E = D_801A571E;
        func_8017D164(q0, q1);
        D_801A5720 = 0;
        D_801A5734 = 0x16F8;
        func_8017DD04(0, D_801A5722);
        D_801A5738 = 0x3C;
        D_801A5740 = 0;
        func_8002D4C8(0xB5B, 0);
        D_801A585C++;
        break;
    case 1:
        func_8017DD04(0, D_801A5722);
        if (--D_801A5738 == 0) {
            D_801A585C++;
        }
        break;
    case 2:
        func_8017DD04(0, D_801A5722);
        func_8017E210(D_801A5740);
        D_801A5740 += 8;
        if (D_801A5740 >= 0x80) {
            D_801A5738 = 0x1E;
            D_801A585C++;
        }
        break;
    case 3:
        func_8017DD04(0, D_801A5722);
        func_8017E210(D_801A5740);
        if (--D_801A5738 == 0) {
            D_801A585C++;
        }
        break;
    case 4:
        func_8017DD04(0, D_801A5722);
        D_801A5740 -= 8;
        if (D_801A5740 <= 0) {
            D_801A5740 = 0;
            D_801A585C++;
        }
        func_8017E210(D_801A5740);
        break;
    case 5:
        func_8017DD04(0, D_801A5722);
        D_801A5734 -= 0x50;
        if (D_801A5734 <= 0x1000) {
            D_801A5734 = 0x1000;
            D_801A574C = 0xFF800000;
            D_801A5750 = 0xFF800000;
            D_801A5758 = -0x10;
            D_801A5754 = 0x200000;
            D_801A575C = 0x800000;
            D_801A5760 = 0x800000;
            D_801A5768 = 0x10;
            D_801A5764 = 0xFFE00000;
            D_801A576C = 0x10;
            D_801A585C++;
        }
        break;
    case 6:
        func_8017DD04(0, D_801A5722);
        r0 = &D_801A5750;
        r1 = &D_801A5754;
        *r0 += *r1;
        *r1 += 0xC0000;
        if (D_801A5752 >= 0x80) {
            D_801A5752 = 0x80;
        }
        func_8017E3A0(D_801A574E, D_801A5758, D_801A5752, D_801A5758, D_801A576C, 0);
        r2 = &D_801A5760;
        r3 = &D_801A5764;
        *r2 += *r3;
        *r3 -= 0xC0000;
        if (D_801A5762 < -0x7F) {
            D_801A5762 = -0x80;
            D_801A585C++;
        }
        func_8017E3A0(D_801A575E, D_801A5768, D_801A5762, D_801A5768, D_801A576C, 1);
        D_801A576C += 0x10;
        break;
    case 7:
        func_8017DD04(0, D_801A5722);
        D_801A576C += 0x10;
        if (D_801A576C >= 0x100) {
            D_801A576C = 0xFF;
            D_801A5770 = 0;
            D_801A5748 = 0x80;
            D_801A585C++;
        }
        func_8017E3A0(D_801A574E, D_801A5758, D_801A5752, D_801A5758, D_801A576C, 0);
        func_8017E3A0(D_801A575E, D_801A5768, D_801A5762, D_801A5768, D_801A576C, 1);
        break;
    case 8:
        func_8017DD04(0, D_801A5722);
        func_8017E3A0(D_801A574E, D_801A5758, D_801A5752, D_801A5758, D_801A576C, 0);
        func_8017E3A0(D_801A575E, D_801A5768, D_801A5762, D_801A5768, D_801A576C, 1);
        ((void (*)(s32, s32, s32, s32))func_8017E594)(D_801A5770, -0x10, 0x10, D_801A5748);
        D_801A5770++;
        if (D_801A5770 >= 0x10) {
            D_801A5738 = 0x3C;
            D_801A585C++;
        }
        break;
    case 9:
        func_8017DD04(0, D_801A5722);
        ((void (*)(s32, s32, s32, s32))func_8017E594)(D_801A5770, -0x10, 0x10, D_801A5748);
        if (--D_801A5738 == 0) {
            D_801A585C++;
        }
        break;
    case 10:
        func_8017DD04(0, D_801A5722);
        if (D_801A5748 != 0) {
            D_801A5748 -= 8;
            if (D_801A5748 <= 0) {
                D_801A5748 = 0;
                D_801A585C++;
                func_80174E9C((s32)D_801A1E94);
                D_801A5744 = 0;
                D_801A573C = 0;
            }
            ((void (*)(s32, s32, s32, s32))func_8017E594)(D_801A5770, -0x10, 0x10, D_801A5748);
        }
        break;
    case 11:
        func_8017DD04(0, D_801A5722);
        D_801A573C++;
        if (D_801A573C < 0xA0) {
            D_801A5720 += -0x18000;
        }
        if ((s16)func_80174ED4() != 0) {
            D_801A5738 = 0x3C;
            D_801A585C++;
        }
        break;
    case 12:
        func_8017DD04(0, D_801A5722);
        func_8017E4A0();
        if (--D_801A5738 == 0) {
            func_80174E9C((s32)D_801A2770);
            D_801A5738 = 0x2C;
            D_801A585C++;
        }
        break;
    case 13:
        func_8017DD04(0, D_801A5722);
        if (((s16)func_80174ED4() != 0) || (--D_801A5738 == 0)) {
            func_800D1724((s32)D_80182618);
            D_801A585C++;
        }
        break;
    case 14:
        func_8017DD04(0, D_801A5722);
        break;
    case 15:
        break;
    }
}
