/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80181DEC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80181DEC(s16 *param_1) {
    extern s32 func_8005C49C(void);
    s32 v0;
    s32 v1;

    *(s16 *)(param_1 + 2) = ((func_8005C49C() & 0xF) << 5) + (func_8005C49C() & 0x1F) - 0x190;
    *(s16 *)param_1 = *(s16 *)(param_1 + 2);

    *(s16 *)(param_1 + 3) = ((func_8005C49C() & 0xF) << 4) - 0x120;
    *(s16 *)(param_1 + 1) = *(s16 *)(param_1 + 3);

    *(s32 *)(param_1 + 6) = 3;
    *(s32 *)(param_1 + 8) = 8;

    v1 = func_8005C49C();
    v0 = func_8005C49C();
    *(s32 *)(param_1 + 4) = (v1 & 7) + (v0 & 7);

    *(s32 *)(param_1 + 10) = 0;
}
