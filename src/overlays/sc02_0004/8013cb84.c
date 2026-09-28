/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013CB84 - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
typedef struct { s32 a, b, c; } Rec12;
typedef struct { s32 a, b; s8 c; } __attribute__((packed, aligned(1))) Rec9;
extern s16 currentLocationId;
extern short currentLocationId;
extern s32 D_80195024;
extern s32 D_80195018;
extern s32 D_8019501C;
extern s32 D_80195028;
extern s32 D_80195020;
extern void func_8013DBE4();
extern void func_8013D9B0();
extern void func_8013D330(void);
extern void func_8013D178(void);
extern void func_8013CF68(void);

void func_8013CB84(void) {

    extern u8 D_80078EAF;
    extern s32 D_8019502C;
    extern s32 D_80195038;
    extern s32 D_80195040;
    extern s32 D_80196338;
    extern s32 D_801962B8;
    extern s32 D_801962AC[];
    extern u8 D_80196279;
    extern u8 D_801963C6;
    extern u8 D_80196334;
    extern Rec12 D_8017E644[];
    extern Rec9 D_8017E60C[];
    extern u8 D_80196310;   
    s32 loc = currentLocationId;
    s32 s0 = D_80078EAF;
    s32 ta, tb, tc, t;

    D_80196338 = 0;
    if (D_80195028 == 0 && s0 != D_80195020) {
        ta = D_8017E644[s0].a;
        tb = D_8017E644[s0].b;
        tc = D_8017E644[s0].c;
        D_80195020 = s0;
        D_80196279 = tc;
        D_801963C6 = ta;
        D_80196334 = tb;
        *(Rec9 *)&D_80196310 = D_8017E60C[s0];
        D_80195024 = 1;
        D_80195018 = 1;
        if (D_80195038 & 2) {
            if (s0 == 4) { D_801962AC[0] = 0x100; D_801962B8 = 0x80; }
            if (s0 == 0) { D_801962AC[0] = 0x100; D_801962B8 = 0; }
        }
    }
    if (D_80195024 != 0) {
        t = D_80195018 - 1;
        D_80195018 = t;
        if (t == 0) {
            if (D_80195028 == 0) {
                if ((D_80195038 & 2) && s0 == 4) {
                    if (D_80195040 != 0) func_8013DBE4(6);
                    else func_8013D9B0(6);
                } else {
                    if (D_80195040 != 0) func_8013DBE4(s0);
                    else func_8013D9B0(s0);
                }
                func_8013D330();
                func_8013D178();
                func_8013CF68();
                D_80195018 = 2;
                if (D_80195024 != 0) {
                    if (D_80195038 & 2) {
                        if (s0 == 4) {
                            s32 *p = &D_801962B8;
                            t = *p - 8;
                            *p = t;
                            if (t < 0) *p = 0;
                        } else if (s0 == 0) {
                            s32 *p = &D_801962B8;
                            t = *p + 0x20;
                            *p = t;
                            if (t >= 0x81) *p = 0x80;
                        }
                    }
                } else if (D_80195038 & 2) {
                    if (s0 == 4) D_801962B8 = 0;
                    if (s0 == 0) D_801962B8 = 0x80;
                }
            } else {
                if (D_80195040 != 0) func_8013DBE4(5);
                else func_8013D9B0(5);
                D_80195018 = 1;
            }
        }
    }
    D_8019502C = 0;
    if (loc == 0x1010) {
        if (s0 == 3) {
            if (D_80195024 != 0) D_8019502C = D_8019501C;
            else D_8019502C = 0x1F;
        } else if (s0 == 4) {
            if (D_80195024 != 0) D_8019502C = 0x1F - D_8019501C;
            else D_8019502C = 0;
        }
    }
}
