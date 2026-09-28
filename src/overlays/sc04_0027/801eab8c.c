/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EAB8C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029504(void);
extern s32 func_80029178(s32 arg);
extern void func_80029124(s32, s32);

s32 func_801EAB8C(void) {
    s32 val = func_80029504();
    s32 flag;

    if ((u32)(val - 200) >= 100) {
        if (val < 300 || !(func_80029178(250) & 0xFF)) {
            flag = 1;
        } else {
            flag = 0;
        }
    } else {
        flag = 0;
    }

    if (flag == 0) {
        return 0;
    }
    if (func_80029178(276) & 0xFF) {
        return 0;
    }
    func_80029124(276, 1);
    return 1;
}
