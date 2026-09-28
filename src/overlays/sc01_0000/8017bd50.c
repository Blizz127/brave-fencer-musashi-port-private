/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017BD50 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8017B0E4(int, int);
extern void func_8012A4BC(void);
extern s16 D_801A5674;
extern void (*D_801A56B8)(void);
extern short D_801A56FC;
extern short D_801A56FE;
extern short D_801A5700;
extern s16 D_801A5870;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;

void func_8017BD50(int param_1)
{
    func_8017B0E4(param_1, 6);
    D_801A5674 = D_801A5674 + 1;
    if (D_801A5674 >= 0x19) {
        if (D_801A56B8 != 0) {
            (*D_801A56B8)();
        } else {
            D_80114F30 = D_80114F30 + D_801A56FC;
            D_80114F34 = D_80114F34 + D_801A56FE;
            D_80114F38 = D_80114F38 + D_801A5700;
            D_80114F24 = D_80114F24 + D_801A56FC;
            D_80114F28 = D_80114F28 + D_801A56FE;
            D_80114F2C = D_80114F2C + D_801A5700;
            func_8012A4BC();
        }
        D_801A5870 = 0;
    }
}
