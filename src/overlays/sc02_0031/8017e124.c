/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017E124 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8014659C(void);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80162CCC(void);

void func_8017E124(int param_1) {

    extern u16 D_800DF2E0;
    extern s32 D_801888C8;
    extern s32 D_80188924[];
    s32 iVar1;
    iVar1 = ((s32 (*)(void))func_8014659C)();
    *(s32 *)(param_1 + 0x20) = iVar1;
    if (iVar1 != 0) {
        ((void (*)(s32, void *))func_8001C810)(iVar1, &D_800DF2E0);
        *(s32 **)(iVar1 + 0x80) = &D_801888C8;
        *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x50000000;
        *(u16 *)(iVar1 + 0x2c) = *(u16 *)(iVar1 + 0x2c) | 0xb0;
        *(s32 *)(param_1 + 0x58) = (s32)&D_80188924[*(s32 *)(param_1 + 0x50) * 2];
        *(u16 *)(iVar1 + 0x1c) = 0;
        *(u16 *)(iVar1 + 0x1a) = 0;
        *(u16 *)(iVar1 + 0x18) = 0;
        ((void (*)(s32))func_80146CA0)(param_1);
    } else {
        ((void (*)(s32))func_80162CCC)(param_1);
    }
}
