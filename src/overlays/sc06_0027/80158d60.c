/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158D60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 func_801487F4(s32 *a0);
extern s32 func_80159434(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);

void func_80158D60(s32 a0) {
    s32 count;
    s32 i;
    s32 arg;
    arg = 0x4C000;
    count = 1;
    if (func_801487F4((s32 *)a0) & 0xF0) {
        count = 4;
    }
    for (i = count; i > 0; i--) {
        func_80159434(a0, arg);
        if (*(s16 *)(*(s32 *)(a0 + 0x20) + 0x10) < 0xC00) {
            func_80147324(0x454);
            *(s16 *)(*(s32 *)(a0 + 0x20) + 0x10) = 0xC00;
            *(s32 *)(a0 + 0x238) = 0xFFEA0000;
            func_80146CA0((void *)a0);
            i = 0;
        }
    }
}
