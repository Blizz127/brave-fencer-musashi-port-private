/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158FA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_8019C160;
extern u8 D_80110C3C[];
extern u16 func_80148800(s32 *a0);
extern s32 func_801399F0(s32);
extern void func_80139914(s32);
extern s32 func_80159464(void);
extern void func_801594E8(s32, s32);
extern void func_80146C98(s32 *a0, s16 a1);
extern s32 func_8013767C(s32 a0);
extern void func_80146CA0(void *a0);

void func_80158FA4(s32 param_1)
{
    s32 v0;
    s16 sVar1;

    v0 = *(s32 *)(param_1 + 0x20);
    *(u16 *)(v0 + 0x12) = (*(u16 *)(v0 + 0x12) + 0x16) & 0xfff;
    if (((s32 (*)(void))func_80148800)() & 0xf0) {
        D_8019C160 = 1;
    }
    if (func_801399F0(*(s32 *)(param_1 + 0x198)) != 0) {
        func_80139914(*(s32 *)(param_1 + 0x198));
        *(s32 *)(param_1 + 0x198) = 0;
        sVar1 = ((s32 (*)(s32))func_80159464)(param_1);
        if (sVar1 != 0) {
            func_801594E8(param_1, sVar1);
            ((void (*)(s32, s32))func_80146C98)(param_1, 0xc);
        } else {
            *(s32 *)(param_1 + 0x198) = ((s32 (*)(u8 *))func_8013767C)(&(*(u8 *)&D_80110C3C));
            ((void (*)(s32))func_80146CA0)(param_1);
        }
    }
}
