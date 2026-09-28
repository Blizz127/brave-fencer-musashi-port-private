/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80143B6C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);

s32 func_80143B6C(s32 arg0, s32 arg1) {
    s32 iVar1;
    iVar1 = func_8012C658(0x1C, arg1, arg0);
    if (((iVar1 != 0) && (*(s32*)(arg0 + 0x20) != 0)) && (arg1 == 0)) {
        *(s16*)(iVar1 + 0xFC) = *(u16*)(*(s32*)(arg0 + 0x20) + 0x12);
    }
    return iVar1;
}
