/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801588CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int D_801A45B0;
extern int D_801A45BC;
extern int D_801A45C0;
extern int func_800D0CA0(int);
extern int func_8001AAA0(int);
extern int func_8001BD80(void);
extern s32 func_80159464(void);

void func_801588CC(int param_1) {

    extern void (*D_80180FA8[])(void);
    extern int D_801A45B4;
    extern int D_801A45B8;
    short sVar1;

    D_80180FA8[*(unsigned short *)(param_1 + 2)]();
    switch (D_801A45B0) {
    case 0:
        break;
    case 1:
        func_800D0CA0(2);
        D_801A45B8 = 0;
        D_801A45B4 = 0x46;
        D_801A45B0 += 1;
        break;
    case 2:
        if (D_801A45B4 == 0) {
            if (func_8001BD80() == 0) {
                D_801A45B0 += 1;
            }
        } else {
            D_801A45B4 -= 1;
        }
        break;
    case 3:
        if (func_8001AAA0(0x83) != 0) {
            D_801A45B0 += 1;
        }
        break;
    case 4:
        D_801A45BC = 0;
        sVar1 = ((int (*)(int))func_80159464)(param_1);
        if (sVar1 != 0) {
            D_801A45B4 = 0xd2;
        } else {
            D_801A45B4 = 1;
        }
        break;
    case 5:
        D_801A45B4 -= 1;
        if (D_801A45B4 == -1 || D_801A45C0 != 0) {
            D_801A45B4 = 0;
            D_801A45B0 += 1;
        }
        break;
    case 6:
        func_800D0CA0(1);
        D_801A45B4 = 0x28;
        D_801A45B0 += 1;
        break;
    case 7:
        if (D_801A45B4 == 0) {
            if (func_8001BD80() == 0) {
                D_801A45B0 += 1;
            }
        } else {
            D_801A45B4 -= 1;
        }
        break;
    case 8:
        D_801A45B8 = 1;
        break;
    }
}
