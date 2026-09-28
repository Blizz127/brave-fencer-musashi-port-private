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

extern s16 D_801A5704;
extern s16 D_801A5706;
extern s16 D_801A5708;
extern s16 D_801A570C;
extern s16 D_801A570E;
extern s16 D_801A5710;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;

void func_8017B880(void)
{
    D_80114F30 = D_801A5704;
    D_80114F34 = D_801A5706;
    D_80114F38 = D_801A5708;
    D_80114F24 = D_801A570C;
    D_80114F28 = D_801A570E;
    D_80114F2C = D_801A5710;
}
