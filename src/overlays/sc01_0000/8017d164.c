/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017D164 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8017D164(u16 *arg0, u16 *arg1) {
    extern u16 D_80182698;
    extern u16 D_8018269A;
    extern u16 D_8018269C;
    extern u16 D_801826A0;
    extern u16 D_801826A2;
    extern u16 D_801826A4;

    D_80182698 = *(u16 *)((s32)arg0 + 0x0);
    D_8018269A = *(u16 *)((s32)arg0 + 0x2);
    D_8018269C = *(u16 *)((s32)arg0 + 0x4);
    D_801826A0 = *(u16 *)((s32)arg1 + 0x0);
    D_801826A2 = *(u16 *)((s32)arg1 + 0x2);
    D_801826A4 = *(u16 *)((s32)arg1 + 0x4);
}
