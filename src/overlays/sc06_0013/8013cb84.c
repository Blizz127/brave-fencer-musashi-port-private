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
extern s32 D_80199860;
extern s32 D_80199858;
extern s32 D_8019985C;
extern s32 D_80199850;
extern s32 D_80199854;
extern void func_8013DBE4();
extern void func_8013D9B0();
extern void func_8013D330(void);
extern void func_8013D178(void);
extern void func_8013CF68(void);

void func_8013CB84(void) {

    extern u8 D_80078EAF;
    extern s32 D_80199864;
    extern s32 D_80199870;
    extern s32 D_80199878;
    extern s32 D_8019AB78;
    extern s32 D_8019AAF8;
    extern s32 D_8019AAEC[];
    extern u8 D_8019AAB9;
    extern u8 D_8019AC06;
    extern u8 D_8019AB74;
    extern Rec12 D_8017F534[];
    extern Rec9 D_8017F4FC[];
    extern u8 D_8019AB50;  /* canonical (§8d); Rec9 block-move via cast-at-use */
    s32 loc = D_800B9A08;
    s32 s0 = D_80078EAF;
    s32 ta, tb, tc, t;

    D_8019AB78 = 0;
    if (D_80199860 == 0 && s0 != D_80199858) {
        ta = D_8017F534[s0].a;
        tb = D_8017F534[s0].b;
        tc = D_8017F534[s0].c;
        D_80199858 = s0;
        D_8019AAB9 = tc;
        D_8019AC06 = ta;
        D_8019AB74 = tb;
        *(Rec9 *)&D_8019AB50 = D_8017F4FC[s0];
        D_8019985C = 1;
        D_80199850 = 1;
        if (D_80199870 & 2) {
            if (s0 == 4) { D_8019AAEC[0] = 0x100; D_8019AAF8 = 0x80; }
            if (s0 == 0) { D_8019AAEC[0] = 0x100; D_8019AAF8 = 0; }
        }
    }
    if (D_8019985C != 0) {
        t = D_80199850 - 1;
        D_80199850 = t;
        if (t == 0) {
            if (D_80199860 == 0) {
                if ((D_80199870 & 2) && s0 == 4) {
                    if (D_80199878 != 0) func_8013DBE4(6);
                    else func_8013D9B0(6);
                } else {
                    if (D_80199878 != 0) func_8013DBE4(s0);
                    else func_8013D9B0(s0);
                }
                func_8013D330();
                func_8013D178();
                func_8013CF68();
                D_80199850 = 2;
                if (D_8019985C != 0) {
                    if (D_80199870 & 2) {
                        if (s0 == 4) {
                            s32 *p = &D_8019AAF8;
                            t = *p - 8;
                            *p = t;
                            if (t < 0) *p = 0;
                        } else if (s0 == 0) {
                            s32 *p = &D_8019AAF8;
                            t = *p + 0x20;
                            *p = t;
                            if (t >= 0x81) *p = 0x80;
                        }
                    }
                } else if (D_80199870 & 2) {
                    if (s0 == 4) D_8019AAF8 = 0;
                    if (s0 == 0) D_8019AAF8 = 0x80;
                }
            } else {
                if (D_80199878 != 0) func_8013DBE4(5);
                else func_8013D9B0(5);
                D_80199850 = 1;
            }
        }
    }
    D_80199864 = 0;
    if (loc == 0x1010) {
        if (s0 == 3) {
            if (D_8019985C != 0) D_80199864 = D_80199854;
            else D_80199864 = 0x1F;
        } else if (s0 == 4) {
            if (D_8019985C != 0) D_80199864 = 0x1F - D_80199854;
            else D_80199864 = 0;
        }
    }
}
