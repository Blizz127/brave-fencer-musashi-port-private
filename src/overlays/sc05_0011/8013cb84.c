/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013CB84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 a, b, c; } Rec12;
typedef struct { s32 a, b; s8 c; } __attribute__((packed, aligned(1))) Rec9;
extern s16 D_800B9A08;
extern s32 D_8019BE38;
extern s32 D_8019BE30;
extern s32 D_8019BE34;
extern s32 D_8019BE28;
extern s32 D_8019BE2C;
extern void func_8013DBE4();
extern void func_8013D9B0();
extern void func_8013D330(void);
extern void func_8013D178(void);
extern void func_8013CF68(void);

void func_8013CB84(void) {

    extern u8 D_80078EAF;
    extern s32 D_8019BE3C;
    extern s32 D_8019BE48;
    extern s32 D_8019BE50;
    extern s32 D_8019D150;
    extern s32 D_8019D0D0;
    extern s32 D_8019D0C4[];
    extern u8 D_8019D091;
    extern u8 D_8019D1DE;
    extern u8 D_8019D14C;
    extern Rec12 D_8017E680[];
    extern Rec9 D_8017E648[];
    extern u8 D_8019D128;  /* canonical (§8d); Rec9 block-move via cast-at-use */
    s32 loc = D_800B9A08;
    s32 s0 = D_80078EAF;
    s32 ta, tb, tc, t;

    D_8019D150 = 0;
    if (D_8019BE38 == 0 && s0 != D_8019BE30) {
        ta = D_8017E680[s0].a;
        tb = D_8017E680[s0].b;
        tc = D_8017E680[s0].c;
        D_8019BE30 = s0;
        D_8019D091 = tc;
        D_8019D1DE = ta;
        D_8019D14C = tb;
        *(Rec9 *)&D_8019D128 = D_8017E648[s0];
        D_8019BE34 = 1;
        D_8019BE28 = 1;
        if (D_8019BE48 & 2) {
            if (s0 == 4) { D_8019D0C4[0] = 0x100; D_8019D0D0 = 0x80; }
            if (s0 == 0) { D_8019D0C4[0] = 0x100; D_8019D0D0 = 0; }
        }
    }
    if (D_8019BE34 != 0) {
        t = D_8019BE28 - 1;
        D_8019BE28 = t;
        if (t == 0) {
            if (D_8019BE38 == 0) {
                if ((D_8019BE48 & 2) && s0 == 4) {
                    if (D_8019BE50 != 0) func_8013DBE4(6);
                    else func_8013D9B0(6);
                } else {
                    if (D_8019BE50 != 0) func_8013DBE4(s0);
                    else func_8013D9B0(s0);
                }
                func_8013D330();
                func_8013D178();
                func_8013CF68();
                D_8019BE28 = 2;
                if (D_8019BE34 != 0) {
                    if (D_8019BE48 & 2) {
                        if (s0 == 4) {
                            s32 *p = &D_8019D0D0;
                            t = *p - 8;
                            *p = t;
                            if (t < 0) *p = 0;
                        } else if (s0 == 0) {
                            s32 *p = &D_8019D0D0;
                            t = *p + 0x20;
                            *p = t;
                            if (t >= 0x81) *p = 0x80;
                        }
                    }
                } else if (D_8019BE48 & 2) {
                    if (s0 == 4) D_8019D0D0 = 0;
                    if (s0 == 0) D_8019D0D0 = 0x80;
                }
            } else {
                if (D_8019BE50 != 0) func_8013DBE4(5);
                else func_8013D9B0(5);
                D_8019BE28 = 1;
            }
        }
    }
    D_8019BE3C = 0;
    if (loc == 0x1010) {
        if (s0 == 3) {
            if (D_8019BE34 != 0) D_8019BE3C = D_8019BE2C;
            else D_8019BE3C = 0x1F;
        } else if (s0 == 4) {
            if (D_8019BE34 != 0) D_8019BE3C = 0x1F - D_8019BE2C;
            else D_8019BE3C = 0;
        }
    }
}
