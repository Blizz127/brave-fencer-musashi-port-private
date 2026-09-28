/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F0A9C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801F0A9C(void) {
    extern s32 D_801F9DB8;
    extern s32 D_801F9DA0;
    extern u8 D_801F9DA8[];
    extern u8 D_801F9DA9;
    extern u8 D_801F9DAC[];
    extern u8 D_801F9DB0[];
    extern u8 D_801F9DB1;
    extern s32 D_801F9DBC[];
    extern s16 D_8011512C;
    extern unsigned short D_80115118;
    extern u16 D_8011511A;
    extern u16 D_801150D4;
    extern s32 D_801F3380;
    extern s32 D_801F32E0;
    extern void func_80029774(s32 a0);
    extern s32 func_8002D4C8(s32, s32);
    extern s32 func_8002AF48(s32 a0);
    extern s32 func_8002AF60(void);
    extern void func_801F0F28(void);

    s32 ret;
    s16 i;
    s16 *p;

    ret = 0;
    if (D_801F9DB8 != 0) {
        if (D_801F9DB8 == 1) {
            p = &D_8011512C;
            if (*p == 3) {
                if (D_801F9DA9 == 8) {
                    func_80029774(0);
                    *p = 4;
                    D_80115118 = 0x4B;
                    D_801150D4 = 0;
                    D_801F3380 = 0xF;
                    ((void (*)(s32, s32))func_8002D4C8)(0xB3B, 0);
                } else {
                    *p = 0;
                }
            } else {
                if (D_801F9DA9 == 6) {
                    *p = 7;
                    D_80115118 = 0x4B;
                    D_801F3380 = 0x18;
                } else {
                    *p = 0;
                }
            }
        } else {
            if ((D_801F9DA0 & 3) == 1) {
                D_8011512C = 0xB;
                D_801F3380 = 0x12;
            } else {
                D_8011512C = 0xC;
                D_801F3380 = 0x1C;
            }
            D_80115118 = 0x4B;
        }
        D_801F9DA0 = 0;
        D_801F9DB1 = 0xFF;
    }

    if (D_8011512C == 0xB || D_8011512C == 0xC) {
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
            D_801F9DBC[i] = 0;
        }
        D_8011511A = 1;
        func_801F0F28();
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
            if (D_801F9DAC[i] == 1) {
                D_801F9DBC[i] = func_8002AF48(i);
            } else {
                D_801F9DBC[i] = 0;
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
            if ((D_801F9DBC[0] == 0) && (D_801F9DBC[1] == 0) && (D_801F9DBC[2] == 0) &&
                (D_801F9DBC[3] == 0)) {
                D_801150D4 = 0;
                D_8011511A = 1;
            }
        }
        func_801F0F28();
        break;
    }
    }

    if (ret != 0) {
        D_801F32E0 = ret;
    }
}
