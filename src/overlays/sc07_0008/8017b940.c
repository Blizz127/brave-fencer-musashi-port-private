/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017B940 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern u16 D_801965B4;
extern u16 D_801965B6;
extern u16 D_801965B8;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u8  D_8012694C;
extern s16 D_80196534;
extern short D_801965BC;
extern short D_801965BE;
extern short D_801965C0;
extern s16 D_801965AC;
extern s16 D_801965AE;
extern s16 D_801965B0;
extern s16 D_801965A4;
extern s16 D_801965A6;
extern s16 D_801965A8;

void func_8017B940(void)
{
    s32 buf[3];

    D_8012694C = 2;
    buf[0] = (*(s16 *)&D_80126B5E) - (*(s16 *)&D_801965B4);
    buf[1] = (*(s16 *)&D_80126B62) - (*(s16 *)&D_801965B6);
    buf[2] = (*(s16 *)&D_80126B66) - (*(s16 *)&D_801965B8);
    (*(s16 *)&D_801965BC) = buf[0];
    (*(s16 *)&D_801965BE) = buf[1];
    (*(s16 *)&D_801965C0) = buf[2];
    D_801965AC = D_80114F30 + buf[0];
    D_80196534 = 0;
    D_801965AE = D_80114F34 + buf[1];
    D_801965B0 = D_80114F38 + buf[2];
    D_801965A4 = D_80114F24 + buf[0];
    D_801965A6 = D_80114F28 + buf[1];
    D_801965A8 = D_80114F2C + buf[2];
}
