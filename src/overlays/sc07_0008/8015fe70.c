/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015FE70 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_8017F99C[])(void*);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern s32 func_80161208();

void func_8015FE70(u16 *param_1)
{
    if ((param_1[0x5c] & 0x8000) != 0) {
        if (param_1[0x5d] == 0) {
            ((void (**)())D_8017F99C)[param_1[0]]();
            ((void (*)(u16 *, s16))func_80147078)(param_1, 0);
            ((void (*)(u16 *))func_80159B70)(param_1);
            return;
        }
        param_1[0x5c] = param_1[0x5d];
    }
    if ((param_1[0x5c] & 0x4000) != 0) {
        ((void (*)(u16 *, s16))func_80154A74)(param_1, 0x11);
    }
    ((void (*)(u16 *))func_80161208)(param_1);
}
