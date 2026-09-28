/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801588CC - byte-exact against retail at -O2 (tools/register_match.py). */
#define SsGetMute func_8001BD80
extern s32 D_801950F0;
extern s32 D_801950FC;
extern s32 D_80195100;
extern int D_801950F0;
extern int D_801950FC;
extern int D_80195100;
extern int func_800D0CA0(int);
extern int func_8001AAA0(int);
extern int SsGetMute(void);
extern s32 func_80159464(void);

void func_801588CC(int param_1) {

    extern void (*D_8018007C[])(void);
    extern int D_801950F4;
    extern int D_801950F8;
    short sVar1;

    D_8018007C[*(unsigned short *)(param_1 + 2)]();
    switch (D_801950F0) {
    case 0:
        break;
    case 1:
        func_800D0CA0(2);
        D_801950F8 = 0;
        D_801950F4 = 0x46;
        D_801950F0 += 1;
        break;
    case 2:
        if (D_801950F4 == 0) {
            if (SsGetMute() == 0) {
                D_801950F0 += 1;
            }
        } else {
            D_801950F4 -= 1;
        }
        break;
    case 3:
        if (func_8001AAA0(0x83) != 0) {
            D_801950F0 += 1;
        }
        break;
    case 4:
        D_801950FC = 0;
        sVar1 = ((int (*)(int))func_80159464)(param_1);
        if (sVar1 != 0) {
            D_801950F4 = 0xd2;
        } else {
            D_801950F4 = 1;
        }
        break;
    case 5:
        D_801950F4 -= 1;
        if (D_801950F4 == -1 || D_80195100 != 0) {
            D_801950F4 = 0;
            D_801950F0 += 1;
        }
        break;
    case 6:
        func_800D0CA0(1);
        D_801950F4 = 0x28;
        D_801950F0 += 1;
        break;
    case 7:
        if (D_801950F4 == 0) {
            if (SsGetMute() == 0) {
                D_801950F0 += 1;
            }
        } else {
            D_801950F4 -= 1;
        }
        break;
    case 8:
        D_801950F8 = 1;
        break;
    }
}
