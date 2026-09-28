/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017D428 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_80182698;
extern s16 D_8018269A;
extern s16 D_8018269C;
extern s16 D_801826A0;
extern s16 D_801826A2;
extern s16 D_801826A4;

void func_8017D428(s32 param_1)
{
    *(s32 *)(param_1 + 0x3C) = D_80182698;
    *(s32 *)(param_1 + 0x40) = D_8018269A;
    *(s32 *)(param_1 + 0x44) = D_8018269C;
    *(s32 *)(param_1 + 0x48) = D_801826A0;
    *(s32 *)(param_1 + 0x4C) = D_801826A2;
    *(s32 *)(param_1 + 0x50) = D_801826A4;
}
