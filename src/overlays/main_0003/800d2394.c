/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2394 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_800D9470;
extern s32 D_800D9474;
extern s32 D_800D9478;
extern s32 D_800D947C;
extern s32 D_800D9480;
typedef struct S_D2394 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s16 f18;
    s16 f1A;
    s16 f1C;
    s16 f1E;
    s16 f20;
    s16 f22;
    s16 f24;
    s16 f26;
    s32 f28;
    s16 f2C;
    s16 f2E;
    s16 f30;
    s16 f32;
    s32 f34;
    s32 f38;
} S_D2394;
typedef struct S_D2394B {
    s32 f0;
    s32 f4;
} S_D2394B;

void func_800D2394(S_D2394 *t, s16 a1, s16 a2, s16 a3, s32 a4, S_D2394B *a5) {
    if (D_800D9480 == 1) {
        t->f8 = 0;
        t->f14 = 0;
        t->f28 = 0;
        t->f34 = 0;
        D_800D9480 = 0;
        t->f0 = D_800D9470;
        t->f4 = D_800D9474;
        t->fC = D_800D9478;
        t->f10 = D_800D947C;
    }
    t->f18 = a1;
    t->f1A = a2;
    t->f20 = a3;
    t->f22 = a4;
    t->f30 = (a5->f4 != 0) ? 0x18 : 0x10;
    t->f38 = a5->f4;
    if (t->f28 == 0) {
        t->f2C = a1;
        t->f2E = a2;
    } else {
        t->f2C = a3;
        t->f2E = a4;
    }
}
