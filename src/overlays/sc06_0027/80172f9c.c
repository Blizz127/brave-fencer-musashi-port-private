/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172F9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8017303C(void *);
extern void func_80154A74(s32 a0, s32 a1);
extern s32 func_80174650(s32);
extern u8 D_800D46E4[];
extern s32 D_80126B58;
extern s16 D_80126B30;

void func_80172F9C(void) {
    func_8017303C(D_800D46E4);
    func_80154A74((s32)&D_80126B58, 0x11);
    D_80126B30 = 0;
    func_80174650((s32)&D_80126B58);
}
