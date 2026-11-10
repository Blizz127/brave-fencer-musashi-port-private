/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801418F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u16 D_80115110;
extern u16 D_80115112;
extern unsigned short D_80115118;
extern volatile u16 D_8011511A;
extern s16 D_80115128;
extern u16 D_8011512E;
extern s32 D_80115130;
extern u8 D_80115158[];
extern s16 D_8011515A;
extern u8 D_8011515C;
extern s16 D_8011515E;
extern s16 D_80115162;
extern s16 D_80115166;
extern u8  D_80186338;
extern u8  D_80186350;
extern u8  D_801863C4;
extern u8  D_801863CC;
extern s16 D_80186698;
extern s16 D_8018669A;
extern void *D_801C42D0;
extern void *D_801C42D4;
extern void func_800D24A0(s32 a0);
extern s32  func_80029178(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80141C0C(s32 a0);

void func_801418F8(void)
{
    u16 t;

    func_800D24A0(1);
    D_8011511A = 2;
    t = D_8011511A;
    (*(s16 *)&D_80115118) = 0;
    D_80115130 = 0;
    if (t >= 4) {
        D_8011511A = t - 3;
    }
    (*(s16 *)D_80115158) = 0x106;
    if ((func_80029178(0x1C) & 0xFF) == 0) {
        D_801C42D0 = &D_80186338;
        D_801C42D4 = &D_801863C4;
    } else {
        D_801C42D0 = &D_80186350;
        D_801C42D4 = &D_801863CC;
    }
    D_8011515A = 0x104;
    (*(s16 *)&D_8011515C) = 0x104;
    D_8011515E = 0x129;
    D_80115162 = 0x103;
    D_80115166 = 0x105;
    D_80115128 = 0;
    D_8011512E = 0;
    if (D_80115110 == 3) {
        func_8002D4C8(0x46E, 0);
    } else {
        func_80141C0C(0);
    }
    D_80115128 = 1;
    D_80186698 = 0xE;
    D_8018669A = 3;
    D_80115112 = D_80115112 + 1;
}
