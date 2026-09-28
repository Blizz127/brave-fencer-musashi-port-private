/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017D0BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

void func_8017D0BC(void)
{
    extern void func_8012A018(s32 a0, s32 a1);
    extern void func_8012A094(s32 a0);
    extern void func_8017D1B4(void *a0);
    extern s16 D_80182698;
    extern s16 D_8018269A;
    extern s16 D_8018269C;
    extern s16 D_801826A0;
    extern s16 D_801826A2;
    extern s16 D_801826A4;
    extern u8 D_80126948[];
    extern s32 D_80126984;
    extern s32 D_80126988;
    extern s32 D_8012698C;
    extern s32 D_80126990;
    extern s32 D_80126994;
    extern s32 D_80126998;

    D_80126984 = D_80182698;
    D_80126988 = D_8018269A;
    D_8012698C = D_8018269C;
    D_80126990 = D_801826A0;
    D_80126994 = D_801826A2;
    D_80126998 = D_801826A4;
    func_8012A018((s32)func_8017D1B4, 1);
    func_8012A094((s32)D_80126948);
    func_8017D1B4(D_80126948);
}
