/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EEC54 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_801EEC54(void)
{
    extern s32 D_801F8310;
    extern s16 D_8011512C;
    extern u8  D_801F8301;
    extern u8  D_801F8300[];
    extern s16 D_80115118;
    extern u16 D_8011511A;
    extern s32 D_801F18D8;
    extern s16 D_801150D4;
    extern s32 D_801F82F8;
    extern u8  D_801F8309;
    extern u8  D_801F8308[];
    extern u8  D_801F8304[];
    extern u8  D_801F8305;
    extern u8  D_801F8306;
    extern u8  D_801F8307;
    extern s32 D_801F8314[];
    extern s32 D_801F1838;
    extern char D_801F801C;
    extern void func_8002B00C(void *);
    extern void func_801EFC58(s32);
    extern void func_80029774(s32);
    extern s32 func_8002D4C8(s32, s32);
    extern s32 func_8002AF48(s32);
    extern s32 func_8002AF60(void);
    extern void func_801EF448(void);

    s32 ret;
    short i;

    ret = 0;
    if (D_801F8310 != 0) {
        if (D_801F8310 == 1) {
            s16 *p = &D_8011512C;

            if (*p == 3 && D_801F8301 == 8) {
                func_8002B00C(&D_801F801C);
                func_801EFC58(0);
                func_80029774(0);
                *p = 4;
                D_80115118 = 0x4B;
                D_801F18D8 = 0x15;
                D_801150D4 = D_8011511A;
                func_8002D4C8(0xB3B, 0);
            } else {
                *p = 0;
            }
        } else {
            D_8011512C = 0xA;
            D_801F18D8 = 0x1B;
            D_80115118 = 0x4B;
            D_801F82F8 = 0;
            return;
        }
        D_801F82F8 = 0;
        D_801F8309 = 0xFF;
    }

    if (D_8011512C == 4 || D_8011512C == 0xA) {
        return;
    }
    if (D_801F8301 == D_801F8309) {
        return;
    }

    for (i = 0; i < 8; i++) {
        D_801F8308[i] = D_801F8300[i];
    }

    switch (D_801F8301) {
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
        if ((D_801F8304[0] | D_801F8305 | D_801F8306 | D_801F8307) == 0) {
            goto reset_state;
        }
        for (i = 0; i < 4; i++) {
            if (D_801F8304[i] == 1) {
                D_801F8314[i] = func_8002AF48(i);
            } else {
                D_801F8314[i] = 0;
            }
        }
        if (D_801F8314[0] == 0 && D_801F8314[1] == 0 && D_801F8314[2] == 0 &&
            D_801F8314[3] == 0) {
            goto reset_state;
        }
        D_8011512C = 1;
        D_8011511A = (func_8002AF60() & 3) + 1;
        func_801EF448();
        break;
    }

    if (ret != 0) {
        D_801F1838 = ret;
    }
}
