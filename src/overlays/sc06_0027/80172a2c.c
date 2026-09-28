/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172A2C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80147060(u8 *a0);
extern void func_80149350(s32 arg0);
extern void func_80171A1C(u8 *a0);
extern void func_80172A8C(void *a0);
extern s16 D_80126B30;

void func_80172A2C(int param_1)
{
    ((void (*)(int))func_80147060)(param_1);
    *(short *)(param_1 + 0x136) = 2;
    *(short *)(param_1 + 0x132) = *(unsigned short *)(*(int *)(param_1 + 0x20) + 0x12);
    ((void (*)(int, void *, void *))func_80149350)(param_1, &D_80126B30, &D_80126B30);
    ((void (*)(int))func_80171A1C)(param_1);
    ((void (*)(int))func_80172A8C)(param_1);
}
