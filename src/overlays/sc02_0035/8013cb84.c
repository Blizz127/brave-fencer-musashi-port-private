/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013CB84 - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
typedef struct { s32 a, b, c; } Rec12;
typedef struct { s32 a, b; s8 c; } __attribute__((packed, aligned(1))) Rec9;
extern s16 currentLocationId;
extern short currentLocationId;
extern s32 D_801BD6A4;
extern s32 D_801BD698;
extern s32 D_801BD69C;
extern s32 D_801BD6A8;
extern s32 D_801BD6A0;
extern void func_8013DBE4();
extern void func_8013D9B0();
extern void func_8013D330(void);
extern void func_8013D178(void);
extern void func_8013CF68(void);

void func_8013CB84(void) {

    extern u8 D_80078EAF;
    extern s32 D_801BD6AC;
    extern s32 D_801BD6B8;
    extern s32 D_801BD6C0;
    extern s32 D_801BE9B8;
    extern s32 D_801BE938;
    extern s32 D_801BE92C[];
    extern u8 D_801BE8F9;
    extern u8 D_801BEA46;
    extern u8 D_801BE9B4;
    extern Rec12 D_80184E38[];
    extern Rec9 D_80184E00[];
    extern u8 D_801BE990;   
    s32 loc = currentLocationId;
    s32 s0 = D_80078EAF;
    s32 ta, tb, tc, t;

    D_801BE9B8 = 0;
    if (D_801BD6A8 == 0 && s0 != D_801BD6A0) {
        ta = D_80184E38[s0].a;
        tb = D_80184E38[s0].b;
        tc = D_80184E38[s0].c;
        D_801BD6A0 = s0;
        D_801BE8F9 = tc;
        D_801BEA46 = ta;
        D_801BE9B4 = tb;
        *(Rec9 *)&D_801BE990 = D_80184E00[s0];
        D_801BD6A4 = 1;
        D_801BD698 = 1;
        if (D_801BD6B8 & 2) {
            if (s0 == 4) { D_801BE92C[0] = 0x100; D_801BE938 = 0x80; }
            if (s0 == 0) { D_801BE92C[0] = 0x100; D_801BE938 = 0; }
        }
    }
    if (D_801BD6A4 != 0) {
        t = D_801BD698 - 1;
        D_801BD698 = t;
        if (t == 0) {
            if (D_801BD6A8 == 0) {
                if ((D_801BD6B8 & 2) && s0 == 4) {
                    if (D_801BD6C0 != 0) func_8013DBE4(6);
                    else func_8013D9B0(6);
                } else {
                    if (D_801BD6C0 != 0) func_8013DBE4(s0);
                    else func_8013D9B0(s0);
                }
                func_8013D330();
                func_8013D178();
                func_8013CF68();
                D_801BD698 = 2;
                if (D_801BD6A4 != 0) {
                    if (D_801BD6B8 & 2) {
                        if (s0 == 4) {
                            s32 *p = &D_801BE938;
                            t = *p - 8;
                            *p = t;
                            if (t < 0) *p = 0;
                        } else if (s0 == 0) {
                            s32 *p = &D_801BE938;
                            t = *p + 0x20;
                            *p = t;
                            if (t >= 0x81) *p = 0x80;
                        }
                    }
                } else if (D_801BD6B8 & 2) {
                    if (s0 == 4) D_801BE938 = 0;
                    if (s0 == 0) D_801BE938 = 0x80;
                }
            } else {
                if (D_801BD6C0 != 0) func_8013DBE4(5);
                else func_8013D9B0(5);
                D_801BD698 = 1;
            }
        }
    }
    D_801BD6AC = 0;
    if (loc == 0x1010) {
        if (s0 == 3) {
            if (D_801BD6A4 != 0) D_801BD6AC = D_801BD69C;
            else D_801BD6AC = 0x1F;
        } else if (s0 == 4) {
            if (D_801BD6A4 != 0) D_801BD6AC = 0x1F - D_801BD69C;
            else D_801BD6AC = 0;
        }
    }
}
