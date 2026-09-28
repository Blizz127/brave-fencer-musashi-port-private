/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171AB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_8014C568(s16 *a0, s16 *a1);
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);

s16 func_80171AB0(s32 param_1, void * _arg1)
{
    short sVar1;
    sVar1 = ((short (*)(void))func_8014C568)();
    sVar1 = ((short (*)(int, int, int))func_80012B04)((int)*(short *)(*(int *)(param_1 + 0x20) + 0x12), (int)sVar1, 4);
    *(unsigned short *)(*(int *)(param_1 + 0x20) + 0x12) =
        *(short *)(*(int *)(param_1 + 0x20) + 0x12) + sVar1 & 0xfff;
    return (int)sVar1;
}
