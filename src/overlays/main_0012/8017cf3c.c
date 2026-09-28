/* Overlay range [8017CF3C,8017D2A4) from MAIN.CD member 0012.
 * SHA256(span)=b1a71e69b71551b42bba9ff10989c0a9ae31109378c44dcf36d1f96886be8b6f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017CF3C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern void func_8002B00C(void *);
extern void func_8017DF40(s32);
extern void func_80029774(s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32  func_8002AF48(s32);
extern s32  func_8002AF60(void);
extern void func_8017D730(void);

s32 func_8017CF3C(void)
{
    extern s32 D_80185AEC;
    extern s16 D_8011512C;
    extern u8  D_80185ADD;
    extern u8  D_801857F8[];
    extern u16 D_80115118;
    extern u16 D_8011511A;
    extern s32 D_801826D8;
    extern s16 D_801150D4;
    extern s32 D_80185AD4;
    extern u8  D_80185AE5;
    extern u8  D_80185ADC[];
    extern u8  D_80185AE4[];
    extern u8  D_80185AE0[];
    extern s32 D_80185AF0[];
    extern s32 D_80182638;

    s32 ret;
    short i;

    ret = 0;
    if (D_80185AEC != 0) {
        if (D_80185AEC == 1) {
            s16 *p = &D_8011512C;

            if (*p == 3 && D_80185ADD == 8) {
                func_8002B00C(D_801857F8);
                func_8017DF40(0);
                func_80029774(0);
                *p = 4;
                D_80115118 = 0x4B;
                D_801826D8 = 0x15;
                D_801150D4 = D_8011511A;
                func_8002D4C8(0xB3B, 0);
            } else {
                *p = 0;
            }
        } else {
            D_8011512C = 0xA;
            D_801826D8 = 0x1B;
            D_80115118 = 0x4B;
            D_80185AD4 = 0;
            return;
        }
        D_80185AD4 = 0;
        D_80185AE5 = 0xFF;
    }

    if (D_8011512C == 4 || D_8011512C == 0xA) {
        return;
    }
    if (D_80185ADD == D_80185AE5) {
        return;
    }

    for (i = 0; i < 8; i++) {
        D_80185AE4[i] = D_80185ADC[i];
    }

    switch (D_80185ADD) {
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
        if ((D_80185AE0[0] | D_80185AE0[1] | D_80185AE0[2] | D_80185AE0[3]) == 0) {
            goto reset_state;
        }
        for (i = 0; i < 4; i++) {
            if (D_80185AE0[i] == 1) {
                D_80185AF0[i] = func_8002AF48(i);
            } else {
                D_80185AF0[i] = 0;
            }
        }
        if (D_80185AF0[0] == 0 && D_80185AF0[1] == 0 && D_80185AF0[2] == 0 &&
            D_80185AF0[3] == 0) {
            goto reset_state;
        }
        D_8011512C = 1;
        D_8011511A = (func_8002AF60() & 3) + 1;
        func_8017D730();
        break;
    }

    if (ret != 0) {
        D_80182638 = ret;
    }
}
