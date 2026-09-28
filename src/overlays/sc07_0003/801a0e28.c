/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A0E28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
} Vec8_801A0E28;
extern u16 D_801F43C0;
extern u8 D_801A68D4[];
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern u16 D_801F4310[];
extern u16 D_801F4312;
extern u16 D_801F4314;
extern s32 func_8005C49C(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012C51C(void *a0, s32 a1);
extern void func_8012BD14(s32 a0);
extern void func_8012EC04(s32 a0, s32 a1, s32 *a2);
extern s32 func_8012BA10(s32 a0, s32 a1);
extern void func_80184E20(void *a0);
extern void func_80184E98();
extern void func_8018503C(void);
extern s32 func_801A3054(s32 a0, s32 a1, s32 a2);

void func_801A0E28(s32 a0) {
    s32 s1 = a0;
    s32 sp10[8];                /* 0x10: 32-byte matrix */
    Vec8_801A0E28 sp30;         /* 0x30 */
    u16 sp38[8];                /* 0x38: 16 bytes, fields at +2/+6/+10 */
    struct {
        u16 f0;                 /* 0x48 */
        u16 f2;
        u16 f4;
        u16 f6;
        u16 f8;
        u16 fA;
        u16 fC;
        u16 fE;
        s32 f10;                /* 0x58 */
    } sp48;                     /* 20 bytes -> 24 of frame (S54 law 24) */
    s32 st;

    if (*(s32 *)(s1 + 0x94) < 0x23) {
        s32 r = func_8012BA10(s1, 8);
        s32 p = *(s32 *)(s1 + 0x20);
        s32 k = D_801F43C0;

        *(s16 *)(p + 0x12) = *(u16 *)(p + 0x12) + r;
        func_8012EC04(s1, k, sp10);
        func_8012F14C((s32)sp10, (s32)D_801A68D4, (s32)&sp30);
        sp38[1] = sp30.a;
        sp38[3] = sp30.b;
        sp38[5] = sp30.c;
        func_80184E20(sp38);
        if ((*(s32 *)(s1 + 0x94) & 1) == 0) {
            func_80184E98(func_8005C49C() & 0xFF0, 0x40);
        }
        func_8018503C();
    }

    st = *(s32 *)(s1 + 0x94);
    if (st == 0x23) {
        if (((s32 (*)(s32))func_8012BD14)(s1) > 0x23FFF) {
            sp30.a = sp30.b = 0;
            *(s16 *)&sp30.c = -0x180;
            func_8012F214(s1, (s32)&sp30, (s32)&sp30);
            if (func_801A3054(s1, (s32)&sp30, 0x200) != 0) {
                D_801F4310[0] = D_80126B5E;
                D_801F4312 = D_80126B62;
                D_801F4314 = D_80126B66;
            } else {
                /* S54 law 22 (S193-C): the shared tail is written in BOTH arms so
                   cross_jump merges the scheduled common suffix, leaving each arm's
                   own `$a1` setup ($s0 copy vs a fresh addiu) above the merge point. */
                sp30.a = sp30.b = 0;
                *(s16 *)&sp30.c = -0x200;
                func_8012F214(s1, (s32)&sp30, (s32)&sp30);
                *(Vec8_801A0E28 *)D_801F4310 = sp30;
            }
        } else {
            sp30.a = sp30.b = 0;
            *(s16 *)&sp30.c = -0x200;
            func_8012F214(s1, (s32)&sp30, (s32)&sp30);
            *(Vec8_801A0E28 *)D_801F4310 = sp30;
        }
        st = *(s32 *)(s1 + 0x94);
    }

    if (st == 0x2F || st == 0x40 || st == 0x51) {
        func_8012EC04(s1, D_801F43C0, sp10);
        func_8012F14C((s32)sp10, (s32)D_801A68D4, (s32)&sp30);
        sp48.f0 = sp30.a;
        sp48.f2 = sp30.b;
        sp48.f4 = sp30.c;
        sp48.f6 = 0x378;
        sp48.f8 = sp48.fA = 0;
        sp48.fE = sp48.f10 = 0;
        sp48.fC = 0x7FFF;
        func_8012C51C(&sp48, s1);
        sp48.f8 = 0x8000;
        func_8012C51C(&sp48, s1);
        *(s32 *)(s1 + 0xE0) |= 4;
        func_8002D4C8(0xB54, 0);
    }

    if (*(s16 *)(s1 + 0x98) == 0) {
        *(s16 *)(s1 + 2) = 0x13;
    }
}
