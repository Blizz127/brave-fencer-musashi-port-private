/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80137614 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_801399A8(void);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");

s32 aF80137614(s32 a0, s32 a1, s32 a2)
{
    s32 v1, s0;
    __asm__("" : "=r"(v1) : "0"(a1));
    s0 = func_801399A8();
    if (s0 != 0) {
        func_801377B4(a0, a2 & 0xD8, s0);
        *(s16 *)(s0 + 0x1C) = v1;
    }
    return s0;
}
