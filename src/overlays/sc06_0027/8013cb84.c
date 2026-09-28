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
extern s32 D_8019C088;
extern s32 D_8019C080;
extern s32 D_8019C084;
extern s32 D_8019C078;
extern s32 D_8019C07C;
extern void func_8013DBE4();
extern void func_8013D9B0();
extern void func_8013D330(void);
extern void func_8013D178(void);
extern void func_8013CF68(void);

void func_8013CB84(void) {

    extern u8 D_80078EAF;
    extern s32 D_8019C08C;
    extern s32 D_8019C098;
    extern s32 D_8019C0A0;
    extern s32 D_8019D3A0;
    extern s32 D_8019D320;
    extern s32 D_8019D314[];
    extern u8 D_8019D2E1;
    extern u8 D_8019D42E;
    extern u8 D_8019D39C;
    extern Rec12 D_8017E93C[];
    extern Rec9 D_8017E904[];
    extern u8 D_8019D378;  /* canonical (§8d); Rec9 block-move via cast-at-use */
    s32 loc = D_800B9A08;
    s32 s0 = D_80078EAF;
    s32 ta, tb, tc, t;

    D_8019D3A0 = 0;
    if (D_8019C088 == 0 && s0 != D_8019C080) {
        ta = D_8017E93C[s0].a;
        tb = D_8017E93C[s0].b;
        tc = D_8017E93C[s0].c;
        D_8019C080 = s0;
        D_8019D2E1 = tc;
        D_8019D42E = ta;
        D_8019D39C = tb;
        *(Rec9 *)&D_8019D378 = D_8017E904[s0];
        D_8019C084 = 1;
        D_8019C078 = 1;
        if (D_8019C098 & 2) {
            if (s0 == 4) { D_8019D314[0] = 0x100; D_8019D320 = 0x80; }
            if (s0 == 0) { D_8019D314[0] = 0x100; D_8019D320 = 0; }
        }
    }
    if (D_8019C084 != 0) {
        t = D_8019C078 - 1;
        D_8019C078 = t;
        if (t == 0) {
            if (D_8019C088 == 0) {
                if ((D_8019C098 & 2) && s0 == 4) {
                    if (D_8019C0A0 != 0) func_8013DBE4(6);
                    else func_8013D9B0(6);
                } else {
                    if (D_8019C0A0 != 0) func_8013DBE4(s0);
                    else func_8013D9B0(s0);
                }
                func_8013D330();
                func_8013D178();
                func_8013CF68();
                D_8019C078 = 2;
                if (D_8019C084 != 0) {
                    if (D_8019C098 & 2) {
                        if (s0 == 4) {
                            s32 *p = &D_8019D320;
                            t = *p - 8;
                            *p = t;
                            if (t < 0) *p = 0;
                        } else if (s0 == 0) {
                            s32 *p = &D_8019D320;
                            t = *p + 0x20;
                            *p = t;
                            if (t >= 0x81) *p = 0x80;
                        }
                    }
                } else if (D_8019C098 & 2) {
                    if (s0 == 4) D_8019D320 = 0;
                    if (s0 == 0) D_8019D320 = 0x80;
                }
            } else {
                if (D_8019C0A0 != 0) func_8013DBE4(5);
                else func_8013D9B0(5);
                D_8019C078 = 1;
            }
        }
    }
    D_8019C08C = 0;
    if (loc == 0x1010) {
        if (s0 == 3) {
            if (D_8019C084 != 0) D_8019C08C = D_8019C07C;
            else D_8019C08C = 0x1F;
        } else if (s0 == 4) {
            if (D_8019C084 != 0) D_8019C08C = 0x1F - D_8019C07C;
            else D_8019C08C = 0;
        }
    }
}
