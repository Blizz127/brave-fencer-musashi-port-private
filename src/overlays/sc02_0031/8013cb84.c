/* SC02 resident image [8013CB84,8013CF68) at overlay base 0x80128158.
 * SHA256(span)=40455a4fde6075149c137b10cefe25b5a8d1edcd31c082afcc4ec13b1e0bb869.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
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
extern s32 D_801B6378;
extern s32 D_801B6370;
extern s32 D_801B6374;
extern s32 D_801B6368;
extern s32 D_801B636C;
extern void func_8013DBE4();
extern void func_8013D9B0();
extern void func_8013D330(void);
extern void func_8013D178(void);
extern void func_8013CF68(void);

void func_8013CB84(void) {

    extern u8 D_80078EAF;
    extern s32 D_801B637C;
    extern s32 D_801B6388;
    extern s32 D_801B6390;
    extern s32 D_801B7A80;
    extern s32 D_801B7A00;
    extern s32 D_801B79F4[];
    extern u8 D_801B79C1;
    extern u8 D_801B7B0E;
    extern u8 D_801B7A7C;
    extern Rec12 D_801855D8[];
    extern Rec9 D_801855A0[];
    extern u8 D_801B7A58;  /* canonical (§8d); Rec9 block-move via cast-at-use */
    s32 loc = D_800B9A08;
    s32 s0 = D_80078EAF;
    s32 ta, tb, tc, t;

    D_801B7A80 = 0;
    if (D_801B6378 == 0 && s0 != D_801B6370) {
        ta = D_801855D8[s0].a;
        tb = D_801855D8[s0].b;
        tc = D_801855D8[s0].c;
        D_801B6370 = s0;
        D_801B79C1 = tc;
        D_801B7B0E = ta;
        D_801B7A7C = tb;
        *(Rec9 *)&D_801B7A58 = D_801855A0[s0];
        D_801B6374 = 1;
        D_801B6368 = 1;
        if (D_801B6388 & 2) {
            if (s0 == 4) { D_801B79F4[0] = 0x100; D_801B7A00 = 0x80; }
            if (s0 == 0) { D_801B79F4[0] = 0x100; D_801B7A00 = 0; }
        }
    }
    if (D_801B6374 != 0) {
        t = D_801B6368 - 1;
        D_801B6368 = t;
        if (t == 0) {
            if (D_801B6378 == 0) {
                if ((D_801B6388 & 2) && s0 == 4) {
                    if (D_801B6390 != 0) func_8013DBE4(6);
                    else func_8013D9B0(6);
                } else {
                    if (D_801B6390 != 0) func_8013DBE4(s0);
                    else func_8013D9B0(s0);
                }
                func_8013D330();
                func_8013D178();
                func_8013CF68();
                D_801B6368 = 2;
                if (D_801B6374 != 0) {
                    if (D_801B6388 & 2) {
                        if (s0 == 4) {
                            s32 *p = &D_801B7A00;
                            t = *p - 8;
                            *p = t;
                            if (t < 0) *p = 0;
                        } else if (s0 == 0) {
                            s32 *p = &D_801B7A00;
                            t = *p + 0x20;
                            *p = t;
                            if (t >= 0x81) *p = 0x80;
                        }
                    }
                } else if (D_801B6388 & 2) {
                    if (s0 == 4) D_801B7A00 = 0;
                    if (s0 == 0) D_801B7A00 = 0x80;
                }
            } else {
                if (D_801B6390 != 0) func_8013DBE4(5);
                else func_8013D9B0(5);
                D_801B6368 = 1;
            }
        }
    }
    D_801B637C = 0;
    if (loc == 0x1010) {
        if (s0 == 3) {
            if (D_801B6374 != 0) D_801B637C = D_801B636C;
            else D_801B637C = 0x1F;
        } else if (s0 == 4) {
            if (D_801B6374 != 0) D_801B637C = 0x1F - D_801B636C;
            else D_801B637C = 0;
        }
    }
}
