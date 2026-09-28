/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017B7A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u8 D_8012694C;
extern s16 D_80196534;
extern s16 D_801965AC;
extern s16 D_801965AE;
extern s16 D_801965B0;
extern s16 D_801965A4;
extern s16 D_801965A6;
extern s16 D_801965A8;

void func_8017B7A8(void)
{
    D_8012694C = 1;
    D_80196534 = 0;
    D_801965AC = (s16) D_80114F30;
    D_801965AE = (s16) D_80114F34;
    D_801965B0 = (s16) D_80114F38;
    D_801965A4 = (s16) D_80114F24;
    D_801965A6 = (s16) D_80114F28;
    D_801965A8 = (s16) D_80114F2C;
}
