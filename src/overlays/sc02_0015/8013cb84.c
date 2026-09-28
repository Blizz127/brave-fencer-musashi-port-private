/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013CB84 - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
typedef struct { s32 a, b, c; } Rec12;
typedef struct { s32 a, b; s8 c; } __attribute__((packed, aligned(1))) Rec9;
extern s16 currentLocationId;
extern short currentLocationId;
extern s32 D_8018F0FC;
extern s32 D_8018F0F0;
extern s32 D_8018F0F4;
extern s32 D_8018F100;
extern s32 D_8018F0F8;
extern void func_8013DBE4();
extern void func_8013D9B0();
extern void func_8013D330(void);
extern void func_8013D178(void);
extern void func_8013CF68(void);

void func_8013CB84(void) {

    extern u8 D_80078EAF;
    extern s32 D_8018F104;
    extern s32 D_8018F110;
    extern s32 D_8018F118;
    extern s32 D_80190610;
    extern s32 D_80190590;
    extern s32 D_80190584[];
    extern u8 D_80190551;
    extern u8 D_8019069E;
    extern u8 D_8019060C;
    extern Rec12 D_8017EBAC[];
    extern Rec9 D_8017EB74[];
    extern u8 D_801905E8;   
    s32 loc = currentLocationId;
    s32 s0 = D_80078EAF;
    s32 ta, tb, tc, t;

    D_80190610 = 0;
    if (D_8018F100 == 0 && s0 != D_8018F0F8) {
        ta = D_8017EBAC[s0].a;
        tb = D_8017EBAC[s0].b;
        tc = D_8017EBAC[s0].c;
        D_8018F0F8 = s0;
        D_80190551 = tc;
        D_8019069E = ta;
        D_8019060C = tb;
        *(Rec9 *)&D_801905E8 = D_8017EB74[s0];
        D_8018F0FC = 1;
        D_8018F0F0 = 1;
        if (D_8018F110 & 2) {
            if (s0 == 4) { D_80190584[0] = 0x100; D_80190590 = 0x80; }
            if (s0 == 0) { D_80190584[0] = 0x100; D_80190590 = 0; }
        }
    }
    if (D_8018F0FC != 0) {
        t = D_8018F0F0 - 1;
        D_8018F0F0 = t;
        if (t == 0) {
            if (D_8018F100 == 0) {
                if ((D_8018F110 & 2) && s0 == 4) {
                    if (D_8018F118 != 0) func_8013DBE4(6);
                    else func_8013D9B0(6);
                } else {
                    if (D_8018F118 != 0) func_8013DBE4(s0);
                    else func_8013D9B0(s0);
                }
                func_8013D330();
                func_8013D178();
                func_8013CF68();
                D_8018F0F0 = 2;
                if (D_8018F0FC != 0) {
                    if (D_8018F110 & 2) {
                        if (s0 == 4) {
                            s32 *p = &D_80190590;
                            t = *p - 8;
                            *p = t;
                            if (t < 0) *p = 0;
                        } else if (s0 == 0) {
                            s32 *p = &D_80190590;
                            t = *p + 0x20;
                            *p = t;
                            if (t >= 0x81) *p = 0x80;
                        }
                    }
                } else if (D_8018F110 & 2) {
                    if (s0 == 4) D_80190590 = 0;
                    if (s0 == 0) D_80190590 = 0x80;
                }
            } else {
                if (D_8018F118 != 0) func_8013DBE4(5);
                else func_8013D9B0(5);
                D_8018F0F0 = 1;
            }
        }
    }
    D_8018F104 = 0;
    if (loc == 0x1010) {
        if (s0 == 3) {
            if (D_8018F0FC != 0) D_8018F104 = D_8018F0F4;
            else D_8018F104 = 0x1F;
        } else if (s0 == 4) {
            if (D_8018F0FC != 0) D_8018F104 = 0x1F - D_8018F0F4;
            else D_8018F104 = 0;
        }
    }
}
