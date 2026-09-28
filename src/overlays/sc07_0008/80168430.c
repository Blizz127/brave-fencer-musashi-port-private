/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80168430 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80166F58(s32, s32, s32, s32);

void func_80168430(s32 param_1) {

    extern u8 D_801802A0[];
    extern u8 D_80180278[];
    extern u8 D_80180279[];
    s32 iVar1;

    *(s32 *)(param_1 + 0x30) = D_801802A0[*(s32 *)(param_1 + 0x2C)];
    iVar1 = (*(s32 *)(param_1 + 0x2C) << 0x11) >> 0x10;
    *(s16 *)(param_1 + 0x2A) = D_80180278[iVar1];
    *(s32 *)(param_1 + 0x1C) = D_80180279[iVar1];
    ((void (*)(s32, s32, s32, s32))func_80166F58)(param_1, 5, 0x3B, 2);
    *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
}
