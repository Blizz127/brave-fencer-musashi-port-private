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
extern s16 D_801B7504;
extern void (*D_801B7548)(void);
extern short D_801B758C;
extern short D_801B758E;
extern short D_801B7590;
extern s16 D_801B7A98;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;

void func_8017BD50(int param_1)
{
    func_8017B0E4(param_1, 6);
    D_801B7504 = D_801B7504 + 1;
    if (D_801B7504 >= 0x19) {
        if (D_801B7548 != 0) {
            (*D_801B7548)();
        } else {
            D_80114F30 = D_80114F30 + D_801B758C;
            D_80114F34 = D_80114F34 + D_801B758E;
            D_80114F38 = D_80114F38 + D_801B7590;
            D_80114F24 = D_80114F24 + D_801B758C;
            D_80114F28 = D_80114F28 + D_801B758E;
            D_80114F2C = D_80114F2C + D_801B7590;
            func_8012A4BC();
        }
        D_801B7A98 = 0;
    }
}
