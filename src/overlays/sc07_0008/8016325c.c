/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016325C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80162F60(s32 arg0, s32 arg1);
extern void func_80162F80(s32 arg0, s32 arg1);
extern void func_80162FA0(s32 arg0, s32 arg1);
extern void func_80146D30(s32 a0);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");

void func_8016325C(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_80162F60(a0, a1);
    func_80162F80(a0, a2);
    func_80162FA0(a0, a3);
    aD_80127090 = *(s32 *)(a0 + 0x24);
    aD_80127094 = *(s32 *)(a0 + 0x28);
    aD_80127098 = *(s32 *)(a0 + 0x2C);
    func_80146D30(a0);
}
