/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE8EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801EE8EC(void) {
    extern void func_80029514(s32 _arg0);
    extern u8 *D_80126B10;
    extern void func_80174438(s32 a0);
    extern void func_80029124(s32 arg0, s32 arg1);

    func_80029514(0x12C);
    func_80174438((s32)D_80126B10);
    func_80029124(0x10F, 1);
}
