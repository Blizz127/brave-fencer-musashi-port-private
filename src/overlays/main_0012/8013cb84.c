/* Overlay range [8013CB84,8013CF68) from MAIN.CD member 0012.
 * SHA256(span)=98173c3cb468079b71fa4ea282b5abd3bc843494f58ad3f59ede091c8e3cc4ca.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013CB84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define currentLocationId D_800B9A08

/* File-scope declarations from the vendor translation unit. */
typedef struct { s32 a, b, c; } Rec12;
typedef struct { s32 a, b; s8 c; } __attribute__((packed, aligned(1))) Rec9;

extern s16 currentLocationId;

extern void func_8013DBE4();
extern void func_8013D9B0();
extern void func_8013D330(void);
extern void func_8013D178(void);
extern void func_8013CF68(void);

void func_8013CB84(void) {

    extern u8 D_80078EAF;
    extern s32 D_801841C0;
    extern s32 D_801841B8;
    extern s32 D_801841BC;
    extern s32 D_801841B0;
    extern s32 D_801841B4;
    extern s32 D_801841C4;
    extern s32 D_801841D0;
    extern s32 D_801841D8;
    extern s32 D_80185BF0;
    extern s32 D_80185B70;
    extern s32 D_80185B64[];
    extern u8 D_80185B31;
    extern u8 D_80185C7E;
    extern u8 D_80185BEC;
    extern Rec12 D_8017ECE8[];
    extern Rec9 D_8017ECB0[];
    extern u8 D_80185BC8;  /* canonical (§8d); Rec9 block-move via cast-at-use */
    s32 loc = currentLocationId;
    s32 s0 = D_80078EAF;
    s32 ta, tb, tc, t;

    D_80185BF0 = 0;
    if (D_801841C0 == 0 && s0 != D_801841B8) {
        ta = D_8017ECE8[s0].a;
        tb = D_8017ECE8[s0].b;
        tc = D_8017ECE8[s0].c;
        D_801841B8 = s0;
        D_80185B31 = tc;
        D_80185C7E = ta;
        D_80185BEC = tb;
        *(Rec9 *)&D_80185BC8 = D_8017ECB0[s0];
        D_801841BC = 1;
        D_801841B0 = 1;
        if (D_801841D0 & 2) {
            if (s0 == 4) { D_80185B64[0] = 0x100; D_80185B70 = 0x80; }
            if (s0 == 0) { D_80185B64[0] = 0x100; D_80185B70 = 0; }
        }
    }
    if (D_801841BC != 0) {
        t = D_801841B0 - 1;
        D_801841B0 = t;
        if (t == 0) {
            if (D_801841C0 == 0) {
                if ((D_801841D0 & 2) && s0 == 4) {
                    if (D_801841D8 != 0) func_8013DBE4(6);
                    else func_8013D9B0(6);
                } else {
                    if (D_801841D8 != 0) func_8013DBE4(s0);
                    else func_8013D9B0(s0);
                }
                func_8013D330();
                func_8013D178();
                func_8013CF68();
                D_801841B0 = 2;
                if (D_801841BC != 0) {
                    if (D_801841D0 & 2) {
                        if (s0 == 4) {
                            s32 *p = &D_80185B70;
                            t = *p - 8;
                            *p = t;
                            if (t < 0) *p = 0;
                        } else if (s0 == 0) {
                            s32 *p = &D_80185B70;
                            t = *p + 0x20;
                            *p = t;
                            if (t >= 0x81) *p = 0x80;
                        }
                    }
                } else if (D_801841D0 & 2) {
                    if (s0 == 4) D_80185B70 = 0;
                    if (s0 == 0) D_80185B70 = 0x80;
                }
            } else {
                if (D_801841D8 != 0) func_8013DBE4(5);
                else func_8013D9B0(5);
                D_801841B0 = 1;
            }
        }
    }
    D_801841C4 = 0;
    if (loc == 0x1010) {
        if (s0 == 3) {
            if (D_801841BC != 0) D_801841C4 = D_801841B4;
            else D_801841C4 = 0x1F;
        } else if (s0 == 4) {
            if (D_801841BC != 0) D_801841C4 = 0x1F - D_801841B4;
            else D_801841C4 = 0;
        }
    }
}
