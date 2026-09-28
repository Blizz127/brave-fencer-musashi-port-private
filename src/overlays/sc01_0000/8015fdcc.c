/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015FDCC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801399F0(s32 a0);
extern void func_80147324(s32 a0);
extern void func_80139914(s32 a0);
extern s32 func_80028DE0(void);
extern u8 func_80165700(s32 a0, s32 a1);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80146CA0(void *a0);

void func_8015FDCC(s32 a0) {
    s32 s0 = a0;
    if (func_801399F0(*(s32 *)(s0 + 0x198)) != 0) {
        func_80147324(0x19);
        func_80139914(*(s32 *)(s0 + 0x198));
        *(s32 *)(s0 + 0x198) = 0;
        if (func_80028DE0() == 0) {
            if ((func_80165700(s0, *(u8 *)(s0 + 0x1A0)) & 0xFF) != 0) {
                func_801466F0(0x24, s0, 0, 0, 0, 0, 0, 0);
                func_80147324(0x989);
            }
        }
        func_80146CA0((void *)s0);
    }
}
