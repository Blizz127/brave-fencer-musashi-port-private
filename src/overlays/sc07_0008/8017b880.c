/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017B880 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_801965C4;
extern s16 D_801965C6;
extern s16 D_801965C8;
extern s16 D_801965CC;
extern s16 D_801965CE;
extern s16 D_801965D0;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;

void func_8017B880(void)
{
    D_80114F30 = D_801965C4;
    D_80114F34 = D_801965C6;
    D_80114F38 = D_801965C8;
    D_80114F24 = D_801965CC;
    D_80114F28 = D_801965CE;
    D_80114F2C = D_801965D0;
}
