/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E3C1C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80029774(s32);
extern s32 func_8002D4C8(s32, s32);
extern s32  func_8002AF48(s32);
extern s32  func_8002AF60(void);
extern void func_801E40A8(void);

int func_801E3C1C() {
    extern s32 D_801EAC54;
    extern u32 D_801EAC3C;
    extern u8 D_801EAC45;
    extern u8 D_801EAC4D;
    extern u16 D_801EAC44[];
    extern u8 D_801EAC4C[];
    extern u8 D_801EAC48[];
    extern void *D_801EAC58[];
    extern s32 D_801EAC5C;
    extern s32 D_801EAC60;
    extern s32 D_801EAC64;
    extern s32 D_801E6448;
    extern s32 D_801E64E8;
    extern s16 D_8011512C;
    extern s16 D_80115118;
    extern u16 D_8011511A;
    extern u16 D_801150D4;
    extern void func_80029774(s32 a0);
    extern s32 func_8002D4C8(s32 a0, s32 a1);
    extern s32 func_8002AF48(s32 a0);
    extern s32 func_8002AF60(void);
    extern void func_801E40A8(void);

    s32 ret;
    s16 i;
    s16 *p;

    ret = 0;
    if (D_801EAC54 != 0) {
        if (D_801EAC54 == 1) {
            p = &D_8011512C;
            if (*p == 3) {
                if (D_801EAC45 == 8) {
                    func_80029774(0);
                    *p = 4;
                    D_80115118 = 0x4B;
                    D_801150D4 = 0;
                    D_801E64E8 = 0xF;
                    func_8002D4C8(0xB3B, 0);
                } else {
                    *p = 0;
                }
            } else {
                if (D_801EAC45 == 6) {
                    *p = 7;
                    D_80115118 = 0x4B;
                    D_801E64E8 = 0x18;
                } else {
                    *p = 0;
                }
            }
        } else {
            if ((D_801EAC3C & 3) == 1) {
                D_8011512C = 0xB;
                D_801E64E8 = 0x12;
            } else {
                D_8011512C = 0xC;
                D_801E64E8 = 0x1C;
            }
            D_80115118 = 0x4B;
        }
        D_801EAC3C = 0;
        D_801EAC4D = 0xFF;
    }

    if (D_8011512C == 0xB || D_8011512C == 0xC) {
        return;
    }
    if (D_801EAC45 == D_801EAC4D) {
        return;
    }

    for (i = 0; i < 8; i++) {
        D_801EAC4C[i] = ((u8 *)D_801EAC44)[i];
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
            ((s32 *)D_801EAC58)[i] = 0;
        }
        D_8011511A = 1;
        func_801E40A8();
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
            if (D_801EAC48[i] == 1) {
                ((s32 *)D_801EAC58)[i] = func_8002AF48(i);
            } else {
                ((s32 *)D_801EAC58)[i] = 0;
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
            if ((((s32 *)D_801EAC58)[0] == 0) && (((s32 *)D_801EAC58)[1] == 0) && (((s32 *)D_801EAC58)[2] == 0) &&
                (((s32 *)D_801EAC58)[3] == 0)) {
                D_801150D4 = 0;
                D_8011511A = 1;
            }
        }
        func_801E40A8();
        break;
    }
    }

    if (ret != 0) {
        D_801E6448 = ret;
    }
}
