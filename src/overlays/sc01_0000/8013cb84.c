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
extern s32 D_801A44E8;
extern s32 D_801A44E0;
extern s32 D_801A44E4;
extern s32 D_801A44D8;
extern s32 D_801A44DC;
extern void func_8013DBE4();
extern void func_8013D9B0();
extern void func_8013D330(void);
extern void func_8013D178(void);
extern void func_8013CF68(void);

void func_8013CB84(void) {

    extern u8 D_80078EAF;
    extern s32 D_801A44EC;
    extern s32 D_801A44F8;
    extern s32 D_801A4500;
    extern s32 D_801A5858;
    extern s32 D_801A57D8;
    extern s32 D_801A57CC[];
    extern u8 D_801A5799;
    extern u8 D_801A58E6;
    extern u8 D_801A5854;
    extern Rec12 D_8017F570[];
    extern Rec9 D_8017F538[];
    extern u8 D_801A5830;  /* canonical (§8d); Rec9 block-move via cast-at-use */
    s32 loc = D_800B9A08;
    s32 s0 = D_80078EAF;
    s32 ta, tb, tc, t;

    D_801A5858 = 0;
    if (D_801A44E8 == 0 && s0 != D_801A44E0) {
        ta = D_8017F570[s0].a;
        tb = D_8017F570[s0].b;
        tc = D_8017F570[s0].c;
        D_801A44E0 = s0;
        D_801A5799 = tc;
        D_801A58E6 = ta;
        D_801A5854 = tb;
        *(Rec9 *)&D_801A5830 = D_8017F538[s0];
        D_801A44E4 = 1;
        D_801A44D8 = 1;
        if (D_801A44F8 & 2) {
            if (s0 == 4) { D_801A57CC[0] = 0x100; D_801A57D8 = 0x80; }
            if (s0 == 0) { D_801A57CC[0] = 0x100; D_801A57D8 = 0; }
        }
    }
    if (D_801A44E4 != 0) {
        t = D_801A44D8 - 1;
        D_801A44D8 = t;
        if (t == 0) {
            if (D_801A44E8 == 0) {
                if ((D_801A44F8 & 2) && s0 == 4) {
                    if (D_801A4500 != 0) func_8013DBE4(6);
                    else func_8013D9B0(6);
                } else {
                    if (D_801A4500 != 0) func_8013DBE4(s0);
                    else func_8013D9B0(s0);
                }
                func_8013D330();
                func_8013D178();
                func_8013CF68();
                D_801A44D8 = 2;
                if (D_801A44E4 != 0) {
                    if (D_801A44F8 & 2) {
                        if (s0 == 4) {
                            s32 *p = &D_801A57D8;
                            t = *p - 8;
                            *p = t;
                            if (t < 0) *p = 0;
                        } else if (s0 == 0) {
                            s32 *p = &D_801A57D8;
                            t = *p + 0x20;
                            *p = t;
                            if (t >= 0x81) *p = 0x80;
                        }
                    }
                } else if (D_801A44F8 & 2) {
                    if (s0 == 4) D_801A57D8 = 0;
                    if (s0 == 0) D_801A57D8 = 0x80;
                }
            } else {
                if (D_801A4500 != 0) func_8013DBE4(5);
                else func_8013D9B0(5);
                D_801A44D8 = 1;
            }
        }
    }
    D_801A44EC = 0;
    if (loc == 0x1010) {
        if (s0 == 3) {
            if (D_801A44E4 != 0) D_801A44EC = D_801A44DC;
            else D_801A44EC = 0x1F;
        } else if (s0 == 4) {
            if (D_801A44E4 != 0) D_801A44EC = 0x1F - D_801A44DC;
            else D_801A44EC = 0;
        }
    }
}
