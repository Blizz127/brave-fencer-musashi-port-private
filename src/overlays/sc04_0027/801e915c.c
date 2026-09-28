/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E915C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801E915C(void) {
    extern s32 D_801F2488;
    extern s32 D_801F2470;
    extern u8 D_801F2478[];
    extern u8 D_801F2479;
    extern u8 D_801F247C[];
    extern u8 D_801F2480[];
    extern u8 D_801F2481;
    extern s32 D_801F248C[];
    extern s32 D_801F2490;
    extern s32 D_801F2494;
    extern s32 D_801F2498;
    extern s16 D_8011512C;
    extern s16 D_80115118;
    extern u16 D_8011511A;
    extern u16 D_801150D4;
    extern s32 D_801EBA50;
    extern void *D_801EB9B0;
    extern void func_80029774(s32 a0);
    extern s32 func_8002D4C8(s32 a0, s32 a1);
    extern s32 func_8002AF48(s32 a0);
    extern s32 func_8002AF60(void);
    extern void func_801E95E8(void);

    s32 ret;
    s16 i;
    s16 *p;

    ret = 0;
    if (D_801F2488 != 0) {
        if (D_801F2488 == 1) {
            p = &D_8011512C;
            if (*p == 3) {
                if (D_801F2479 == 8) {
                    func_80029774(0);
                    *p = 4;
                    D_80115118 = 0x4B;
                    D_801150D4 = 0;
                    D_801EBA50 = 0xF;
                    func_8002D4C8(0xB3B, 0);
                } else {
                    *p = 0;
                }
            } else {
                if (D_801F2479 == 6) {
                    *p = 7;
                    D_80115118 = 0x4B;
                    D_801EBA50 = 0x18;
                } else {
                    *p = 0;
                }
            }
        } else {
            if ((D_801F2470 & 3) == 1) {
                D_8011512C = 0xB;
                D_801EBA50 = 0x12;
            } else {
                D_8011512C = 0xC;
                D_801EBA50 = 0x1C;
            }
            D_80115118 = 0x4B;
        }
        D_801F2470 = 0;
        D_801F2481 = 0xFF;
    }

    if (D_8011512C == 0xB || D_8011512C == 0xC) {
        return;
    }
    if (D_801F2479 == D_801F2481) {
        return;
    }

    for (i = 0; i < 8; i++) {
        D_801F2480[i] = D_801F2478[i];
    }

    switch (D_801F2479) {
    case 0:
        break;
    case 1:
        ret = 0xA;
        D_8011512C = 0;
        D_8011511A = 0;
        break;
    case 2:
        ret = 0xB;
        D_801150D4 = 0;
        D_8011512C = 0;
        D_8011511A = 0;
        break;
    case 3: {
        s16 *q = &D_8011512C;
        D_801150D4 = 0;
        if (((struct { s16 h; } *)q)->h != 0xC) {
            ret = 0x11;
            *q = 5;
        }
        break;
    }
    case 4:
        D_801150D4 = 0;
        D_8011512C = 8;
        ret = 0xB;
        break;
    case 5:
        D_8011512C = 8;
        ret = 0x10;
        break;
    case 6: {
        s16 *q = &D_8011512C;
        D_801150D4 = 0;
        if ((*q != 6) && (*q != 7) && (*q != 0xB)) {
            ret = 0xD;
            *q = 1;
        }
        for (i = 0; i < 4; i++) {
            D_801F248C[i] = 0;
        }
        D_8011511A = 1;
        func_801E95E8();
        break;
    }
    case 7:
        ret = 0xA;
        break;
    case 8: {
        s16 *q;
        if ((D_8011512C != 0xB) && (D_8011512C != 3) && (D_8011512C != 4)) {
            ret = 0xD;
        }
        for (i = 0; i < 4; i++) {
            if (D_801F247C[i] == 1) {
                D_801F248C[i] = func_8002AF48(i);
            } else {
                D_801F248C[i] = 0;
            }
        }
        q = &D_8011512C;
        if (*q == 0) {
            *q = 1;
            if ((u32)(D_801150D4 - 1) < 4) {
                D_8011511A = D_801150D4;
            } else {
                D_8011511A = (func_8002AF60() & 3) + 1;
            }
            if ((D_801F248C[0] == 0) && (D_801F2490 == 0) && (D_801F2494 == 0) &&
                (D_801F2498 == 0)) {
                D_801150D4 = 0;
                D_8011511A = 1;
            }
        }
        func_801E95E8();
        break;
    }
    }

    if (ret != 0) {
        D_801EB9B0 = (void *)ret;
    }
}
