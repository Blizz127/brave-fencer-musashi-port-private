/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013E83C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern u16 D_80115110;
extern u16 D_8011511A;

void func_8013E83C() {
    extern void func_80141C0C(int);
    extern unsigned short D_80115118;
    extern unsigned short D_80115128;
    extern unsigned short D_8011512E;
    extern unsigned int D_80115130;
    extern unsigned short D_80115158;
    extern unsigned short D_8011515A;
    extern unsigned short D_8011515C;
    extern unsigned short D_8011515E;
    extern unsigned short D_80115162;
    extern unsigned short D_80115166;
    extern void * D_8019FA90;
    extern void * D_8019FA94;
    extern unsigned char D_80180114;
    extern unsigned char D_8018012C;
    extern unsigned char D_801801A0;
    extern unsigned char D_801801A8;


    D_80115118 = 0;
    D_80115130 = 0;
    if (D_8011511A >= 4) {
        D_8011511A = D_8011511A - 3;
    }
    D_80115158 = 0x106;

    if ((((int(*)(int))func_80029178)(0x1c) & 0xFF) == 0) {
        D_8019FA90 = &D_80180114;
        D_8019FA94 = &D_801801A0;
    } else {
        D_8019FA90 = &D_8018012C;
        D_8019FA94 = &D_801801A8;
    }

    D_8011515A = 0x104;
    D_8011515C = 0x104;
    D_8011515E = 0x129;
    D_80115162 = 0x103;
    D_80115166 = 0x105;
    D_80115128 = 0;
    D_8011512E = 0;

    if (D_80115110 == 3) {
        ((void(*)(int, int))func_8002D4C8)(0x46e, 0);
    } else {
        func_80141C0C(0);
    }
}
