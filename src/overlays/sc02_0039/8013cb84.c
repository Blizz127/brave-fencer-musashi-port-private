/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013CB84 - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
typedef struct { s32 a, b, c; } Rec12;
typedef struct { s32 a, b; s8 c; } __attribute__((packed, aligned(1))) Rec9;
extern s16 currentLocationId;
extern short currentLocationId;
extern s32 D_8019FA54;
extern s32 D_8019FA48;
extern s32 D_8019FA4C;
extern s32 D_8019FA58;
extern s32 D_8019FA50;
extern void func_8013DBE4();
extern void func_8013D9B0();
extern void func_8013D330(void);
extern void func_8013D178(void);
extern void func_8013CF68(void);

void func_8013CB84(void) {

    extern u8 D_80078EAF;
    extern s32 D_8019FA5C;
    extern s32 D_8019FA68;
    extern s32 D_8019FA70;
    extern s32 D_801A0D70;
    extern s32 D_801A0CF0;
    extern s32 D_801A0CE4[];
    extern u8 D_801A0CB1;
    extern u8 D_801A0DFE;
    extern u8 D_801A0D6C;
    extern Rec12 D_8017FA64[];
    extern Rec9 D_8017FA2C[];
    extern u8 D_801A0D48;   
    s32 loc = currentLocationId;
    s32 s0 = D_80078EAF;
    s32 ta, tb, tc, t;

    D_801A0D70 = 0;
    if (D_8019FA58 == 0 && s0 != D_8019FA50) {
        ta = D_8017FA64[s0].a;
        tb = D_8017FA64[s0].b;
        tc = D_8017FA64[s0].c;
        D_8019FA50 = s0;
        D_801A0CB1 = tc;
        D_801A0DFE = ta;
        D_801A0D6C = tb;
        *(Rec9 *)&D_801A0D48 = D_8017FA2C[s0];
        D_8019FA54 = 1;
        D_8019FA48 = 1;
        if (D_8019FA68 & 2) {
            if (s0 == 4) { D_801A0CE4[0] = 0x100; D_801A0CF0 = 0x80; }
            if (s0 == 0) { D_801A0CE4[0] = 0x100; D_801A0CF0 = 0; }
        }
    }
    if (D_8019FA54 != 0) {
        t = D_8019FA48 - 1;
        D_8019FA48 = t;
        if (t == 0) {
            if (D_8019FA58 == 0) {
                if ((D_8019FA68 & 2) && s0 == 4) {
                    if (D_8019FA70 != 0) func_8013DBE4(6);
                    else func_8013D9B0(6);
                } else {
                    if (D_8019FA70 != 0) func_8013DBE4(s0);
                    else func_8013D9B0(s0);
                }
                func_8013D330();
                func_8013D178();
                func_8013CF68();
                D_8019FA48 = 2;
                if (D_8019FA54 != 0) {
                    if (D_8019FA68 & 2) {
                        if (s0 == 4) {
                            s32 *p = &D_801A0CF0;
                            t = *p - 8;
                            *p = t;
                            if (t < 0) *p = 0;
                        } else if (s0 == 0) {
                            s32 *p = &D_801A0CF0;
                            t = *p + 0x20;
                            *p = t;
                            if (t >= 0x81) *p = 0x80;
                        }
                    }
                } else if (D_8019FA68 & 2) {
                    if (s0 == 4) D_801A0CF0 = 0;
                    if (s0 == 0) D_801A0CF0 = 0x80;
                }
            } else {
                if (D_8019FA70 != 0) func_8013DBE4(5);
                else func_8013D9B0(5);
                D_8019FA48 = 1;
            }
        }
    }
    D_8019FA5C = 0;
    if (loc == 0x1010) {
        if (s0 == 3) {
            if (D_8019FA54 != 0) D_8019FA5C = D_8019FA4C;
            else D_8019FA5C = 0x1F;
        } else if (s0 == 4) {
            if (D_8019FA54 != 0) D_8019FA5C = 0x1F - D_8019FA4C;
            else D_8019FA5C = 0;
        }
    }
}
