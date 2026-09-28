/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EDE38 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801F82F8;
extern u8 D_801F8308[];
extern void (*D_801F8010)();
extern s16 D_801F800C;
extern s16 D_801F8018;
extern s16 D_80115118;
extern s16 D_8011512C;
extern s32 D_801F1838;
extern s32 D_80115130;
extern s32 D_80115134;
extern s32 D_801F18E4[];
extern s16 D_80115126;
extern u8 D_80115138[];
extern s32 D_801F17A0;

void func_801EDE38(void) {
    s16 i;
    s32 cond;
    s32 *p;
    s16 *q;

    D_801F82F8 = 0;
    for (i = 0; i < 8; i++) {
        D_801F8308[i] = -1;
    }
    cond = *(s16 *)&D_801F8010;
    D_801F800C = 0;
    D_801F8018 = 0;
    D_80115118 = 0;
    if (cond == 0) {
        D_8011512C = 0;
        D_801F1838 = D_801F17A0;
    } else {
        D_8011512C = 9;
        D_801F1838 = 26;
    }
    i = 0;
    p = &D_80115130;
    *p = 0;
    D_80115134 = D_801F18E4[D_80115126];
    q = (s16 *)p + 20;
    for (; i < 6; i++) {
        D_80115138[i] = *(u16 *)(D_80115134 + i * 32);
        q[i] = *(u16 *)(D_80115134 + i * 32 + 2);
    }
}
