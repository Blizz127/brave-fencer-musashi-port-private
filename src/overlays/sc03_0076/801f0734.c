/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F0734 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801F0734(void) {
    extern s32 D_801F9DB8;
    extern s16 D_8011512C;
    extern u8  D_801F9DA9;
    extern void func_8002B00C(void *);
    extern void func_801F1738(s32);
    extern void func_80029774(s32);
    extern s16 D_80115118;
    extern u16 D_8011511A;
    extern s32 D_801F3380;
    extern s16 D_801150D4;
    extern s32 func_8002D4C8(s32, s32);
    extern s32 D_801F9DA0;
    extern u8  D_801F9DB1;
    extern u8  D_801F9DA8[];
    extern u8  D_801F9DB0[];
    extern s32 D_801F32E0;
    extern s32 D_801F9AC4;
    extern u8  D_801F9DAC[];
    extern u8  D_801F9DAD;
    extern u8  D_801F9DAE;
    extern u8  D_801F9DAF;
    extern s32 func_8002AF48(s32);
    extern void *D_801F9DBC[];
    extern s32 D_801F9DC0;
    extern s32 D_801F9DC4;
    extern s32 D_801F9DC8;
    extern s32 func_8002AF60(void);
    extern void func_801F0F28(void);

    s32 ret;
    short i;

    ret = 0;
    if (D_801F9DB8 != 0) {
        if (D_801F9DB8 == 1) {
            s16 *p = &D_8011512C;

            if (*p == 3 && D_801F9DA9 == 8) {
                func_8002B00C(&D_801F9AC4);
                func_801F1738(0);
                func_80029774(0);
                *p = 4;
                D_80115118 = 0x4B;
                D_801F3380 = 0x15;
                D_801150D4 = D_8011511A;
                func_8002D4C8(0xB3B, 0);
            } else {
                *p = 0;
            }
        } else {
            D_8011512C = 0xA;
            D_801F3380 = 0x1B;
            D_80115118 = 0x4B;
            D_801F9DA0 = 0;
            return;
        }
        D_801F9DA0 = 0;
        D_801F9DB1 = 0xFF;
    }

    if (D_8011512C == 4 || D_8011512C == 0xA) {
        return;
    }
    if (D_801F9DA9 == D_801F9DB1) {
        return;
    }

    for (i = 0; i < 8; i++) {
        D_801F9DB0[i] = D_801F9DA8[i];
    }

    switch (D_801F9DA9) {
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
        if ((D_801F9DAC[0] | D_801F9DAD | D_801F9DAE | D_801F9DAF) == 0) {
            goto reset_state;
        }
        for (i = 0; i < 4; i++) {
            if (D_801F9DAC[i] == 1) {
                ((s32 *)D_801F9DBC)[i] = func_8002AF48(i);
            } else {
                ((s32 *)D_801F9DBC)[i] = 0;
            }
        }
        if (((s32 *)D_801F9DBC)[0] == 0 && ((s32 *)D_801F9DBC)[1] == 0 && ((s32 *)D_801F9DBC)[2] == 0 &&
            ((s32 *)D_801F9DBC)[3] == 0) {
            goto reset_state;
        }
        D_8011512C = 1;
        D_8011511A = (func_8002AF60() & 3) + 1;
        func_801F0F28();
        break;
    }

    if (ret != 0) {
        D_801F32E0 = ret;
    }
}
