/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E8DF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801E8DF4(void) {
    extern s32 D_801F2488;
    extern s16 D_8011512C;
    extern u8  D_801F2479;
    extern void func_8002B00C(void *);
    extern void func_801E9DF8(s32);
    extern void func_80029774(s32);
    extern s16 D_80115118;
    extern s32 D_801EBA50;
    extern s16 D_801150D4;
    extern s32 func_8002D4C8(s32, s32);
    extern u16 D_8011511A;
    extern s32 D_801F2470;
    extern u8  D_801F2481;
    extern u8  D_801F2478[];
    extern u8  D_801F2480[];
    extern u8  D_801F247C[];
    extern u8  D_801F247D;
    extern u8  D_801F247E;
    extern u8  D_801F247F;
    extern s32 D_801F248C[];
    extern s32 D_801F2490;
    extern s32 D_801F2494;
    extern s32 D_801F2498;
    extern s32 func_8002AF48(s32);
    extern s32 func_8002AF60(void);
    extern void func_801E95E8(void);
    extern void *D_801EB9B0;
    extern s8  D_801F2194;

    s32 ret;
    short i;

    ret = 0;
    if (D_801F2488 != 0) {
        if (D_801F2488 == 1) {
            s16 *p = &D_8011512C;

            if (*p == 3 && D_801F2479 == 8) {
                func_8002B00C(&D_801F2194);
                func_801E9DF8(0);
                func_80029774(0);
                *p = 4;
                D_80115118 = 0x4B;
                D_801EBA50 = 0x15;
                D_801150D4 = D_8011511A;
                func_8002D4C8(0xB3B, 0);
            } else {
                *p = 0;
            }
        } else {
            D_8011512C = 0xA;
            D_801EBA50 = 0x1B;
            D_80115118 = 0x4B;
            D_801F2470 = 0;
            return;
        }
        D_801F2470 = 0;
        D_801F2481 = 0xFF;
    }

    if (D_8011512C == 4) {
        return;
    }
    __asm__ __volatile__("");
    if (D_8011512C == 0xA) {
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
    case 3:
        ret = 0x1F;
        D_801150D4 = 0;
        D_8011512C = 8;
        break;
    case 4:
    case 5:
    case 6:
    reset_state:
        ret = 0x13;
        D_801150D4 = 0;
        D_8011512C = 8;
        break;
    case 7:
        ret = 0xA;
        break;
    case 8:
        ret = 0xC;
        if ((D_801F247C[0] | D_801F247D | D_801F247E | D_801F247F) == 0) {
            goto reset_state;
        }
        for (i = 0; i < 4; i++) {
            if (D_801F247C[i] == 1) {
                D_801F248C[i] = func_8002AF48(i);
            } else {
                D_801F248C[i] = 0;
            }
        }
        if (D_801F248C[0] == 0 && D_801F248C[1] == 0 && D_801F248C[2] == 0 &&
            D_801F248C[3] == 0) {
            goto reset_state;
        }
        D_8011512C = 1;
        D_8011511A = (func_8002AF60() & 3) + 1;
        func_801E95E8();
        break;
    }

    if (ret != 0) {
        D_801EB9B0 = (void *)ret;
    }
}
