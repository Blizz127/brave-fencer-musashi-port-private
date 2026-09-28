/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801F0A14 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029178(s32);
extern s32 func_80029504(void);
extern void func_80029124(s32 a0, s32 a1);

s32 func_801F0A14() {
    s32 v1 = func_80029504();
    s32 flag;

    if ((u32)(v1 - 0xC8) >= 0x64U) {
        if (v1 < 0x12C || (func_80029178(0xFA) & 0xFF) == 0) {
            flag = 1;
        } else {
            flag = 0;
        }
    } else {
        flag = 0;
    }

    if (flag != 0) {
        if ((func_80029178(0x114) & 0xFF) == 0) {
            func_80029124(0x114, 1);
            return 1;
        }
    }
    return 0;
}
