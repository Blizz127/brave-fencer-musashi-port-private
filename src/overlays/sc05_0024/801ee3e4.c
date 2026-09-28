/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE3E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_80178B18(s32 param_1, s32 param_2);
extern s16 D_801EE544;
extern s16 D_801EE546;
extern s16 D_801EE548;
extern s16 D_801B9B0C;
extern s32 D_801F443C[];
extern s32 D_801EE574[];

void func_801EE3E4(s32 param_1)
{
    s32 v0;
    s32 v1;

    v0 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)(param_1 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4((void *)param_1);
    } else {
        func_8001C214(v0, (s32)D_801F443C);
        *(s16 *)(param_1 + 0x6) = D_801EE544;
        v1 = *(s32 *)(param_1 + 0x68);
        *(s16 *)(param_1 + 0xA) = D_801EE546;
        *(s16 *)(param_1 + 0xE) = D_801EE548;
        *(s16 *)(v1 + 0xC) = 0x7FFF;
        *(s16 *)(param_1 + 0x2) = 1;
        func_8012A828(param_1, &D_801B9B0C);
        *(s16 *)(param_1 + 0x34) = 0;
        func_80178B18(param_1, (s32)D_801EE574);
    }
}
