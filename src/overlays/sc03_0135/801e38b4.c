/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E38B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8002B00C(void *);
extern void func_801E48B8(s32);
extern void func_80029774(s32);
extern s32 func_8002D4C8(s32, s32);
extern s32  func_8002AF48(s32);
extern s32  func_8002AF60(void);
extern void func_801E40A8(void);

s32 func_801E38B4(void)
{
    extern s32 D_801EAC54;
    extern s16 D_8011512C;
    extern u8  D_801EAC45;
    extern u8  D_801EA960[];
    extern u16 D_80115118;
    extern u16 D_8011511A;
    extern s32 D_801E64E8;
    extern s16 D_801150D4;
    extern s32 D_801EAC3C;
    extern u8  D_801EAC4D;
    extern u8  D_801EAC44[];
    extern u8  D_801EAC4C[];
    extern u8  D_801EAC48[];
    extern void *D_801EAC58[];
    extern s32 D_801E6448;

    s32 ret;
    short i;

    ret = 0;
    if (D_801EAC54 != 0) {
        if (D_801EAC54 == 1) {
            s16 *p = &D_8011512C;

            if (*p == 3 && D_801EAC45 == 8) {
                func_8002B00C(D_801EA960);
                func_801E48B8(0);
                func_80029774(0);
                *p = 4;
                D_80115118 = 0x4B;
                D_801E64E8 = 0x15;
                D_801150D4 = D_8011511A;
                ((void (*)(s32, s32))func_8002D4C8)(0xB3B, 0);
            } else {
                *p = 0;
            }
        } else {
            D_8011512C = 0xA;
            D_801E64E8 = 0x1B;
            D_80115118 = 0x4B;
            D_801EAC3C = 0;
            return;
        }
        D_801EAC3C = 0;
        D_801EAC4D = 0xFF;
    }

    if (D_8011512C == 4 || D_8011512C == 0xA) {
        return;
    }
    if (D_801EAC45 == D_801EAC4D) {
        return;
    }

    for (i = 0; i < 8; i++) {
        D_801EAC4C[i] = D_801EAC44[i];
    }

    switch (D_801EAC45) {
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
        if ((D_801EAC48[0] | D_801EAC48[1] | D_801EAC48[2] | D_801EAC48[3]) == 0) {
            goto reset_state;
        }
        for (i = 0; i < 4; i++) {
            if (D_801EAC48[i] == 1) {
                ((s32 *)D_801EAC58)[i] = func_8002AF48(i);
            } else {
                ((s32 *)D_801EAC58)[i] = 0;
            }
        }
        if (((s32 *)D_801EAC58)[0] == 0 && ((s32 *)D_801EAC58)[1] == 0 && ((s32 *)D_801EAC58)[2] == 0 &&
            ((s32 *)D_801EAC58)[3] == 0) {
            goto reset_state;
        }
        D_8011512C = 1;
        D_8011511A = (func_8002AF60() & 3) + 1;
        func_801E40A8();
        break;
    }

    if (ret != 0) {
        D_801E6448 = ret;
    }
}
