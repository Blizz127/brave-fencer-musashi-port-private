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
extern s32 D_801953A8;
extern s32 D_801953A0;
extern s32 D_801953A4;
extern s32 D_80195398;
extern s32 D_8019539C;
extern void func_8013DBE4();
extern void func_8013D9B0();
extern void func_8013D330(void);
extern void func_8013D178(void);
extern void func_8013CF68(void);

void func_8013CB84(void) {

    extern u8 D_80078EAF;
    extern s32 D_801953AC;
    extern s32 D_801953B8;
    extern s32 D_801953C0;
    extern s32 D_801966B8;
    extern s32 D_80196638;
    extern s32 D_8019662C[];
    extern u8 D_801965F9;
    extern u8 D_80196746;
    extern u8 D_801966B4;
    extern Rec12 D_8017DC68[];
    extern Rec9 D_8017DC30[];
    extern u8 D_80196690;  /* canonical (§8d); Rec9 block-move via cast-at-use */
    s32 loc = D_800B9A08;
    s32 s0 = D_80078EAF;
    s32 ta, tb, tc, t;

    D_801966B8 = 0;
    if (D_801953A8 == 0 && s0 != D_801953A0) {
        ta = D_8017DC68[s0].a;
        tb = D_8017DC68[s0].b;
        tc = D_8017DC68[s0].c;
        D_801953A0 = s0;
        D_801965F9 = tc;
        D_80196746 = ta;
        D_801966B4 = tb;
        *(Rec9 *)&D_80196690 = D_8017DC30[s0];
        D_801953A4 = 1;
        D_80195398 = 1;
        if (D_801953B8 & 2) {
            if (s0 == 4) { D_8019662C[0] = 0x100; D_80196638 = 0x80; }
            if (s0 == 0) { D_8019662C[0] = 0x100; D_80196638 = 0; }
        }
    }
    if (D_801953A4 != 0) {
        t = D_80195398 - 1;
        D_80195398 = t;
        if (t == 0) {
            if (D_801953A8 == 0) {
                if ((D_801953B8 & 2) && s0 == 4) {
                    if (D_801953C0 != 0) func_8013DBE4(6);
                    else func_8013D9B0(6);
                } else {
                    if (D_801953C0 != 0) func_8013DBE4(s0);
                    else func_8013D9B0(s0);
                }
                func_8013D330();
                func_8013D178();
                func_8013CF68();
                D_80195398 = 2;
                if (D_801953A4 != 0) {
                    if (D_801953B8 & 2) {
                        if (s0 == 4) {
                            s32 *p = &D_80196638;
                            t = *p - 8;
                            *p = t;
                            if (t < 0) *p = 0;
                        } else if (s0 == 0) {
                            s32 *p = &D_80196638;
                            t = *p + 0x20;
                            *p = t;
                            if (t >= 0x81) *p = 0x80;
                        }
                    }
                } else if (D_801953B8 & 2) {
                    if (s0 == 4) D_80196638 = 0;
                    if (s0 == 0) D_80196638 = 0x80;
                }
            } else {
                if (D_801953C0 != 0) func_8013DBE4(5);
                else func_8013D9B0(5);
                D_80195398 = 1;
            }
        }
    }
    D_801953AC = 0;
    if (loc == 0x1010) {
        if (s0 == 3) {
            if (D_801953A4 != 0) D_801953AC = D_8019539C;
            else D_801953AC = 0x1F;
        } else if (s0 == 4) {
            if (D_801953A4 != 0) D_801953AC = 0x1F - D_8019539C;
            else D_801953AC = 0;
        }
    }
}
