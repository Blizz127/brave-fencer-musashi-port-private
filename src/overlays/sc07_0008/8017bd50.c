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
extern s16 D_80196534;
extern void (*D_80196578)(void);
extern short D_801965BC;
extern short D_801965BE;
extern short D_801965C0;
extern s16 D_801966D0;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;

void func_8017BD50(int param_1)
{
    func_8017B0E4(param_1, 6);
    D_80196534 = D_80196534 + 1;
    if (D_80196534 >= 0x19) {
        if (D_80196578 != 0) {
            (*D_80196578)();
        } else {
            D_80114F30 = D_80114F30 + D_801965BC;
            D_80114F34 = D_80114F34 + D_801965BE;
            D_80114F38 = D_80114F38 + D_801965C0;
            D_80114F24 = D_80114F24 + D_801965BC;
            D_80114F28 = D_80114F28 + D_801965BE;
            D_80114F2C = D_80114F2C + D_801965C0;
            func_8012A4BC();
        }
        D_801966D0 = 0;
    }
}
