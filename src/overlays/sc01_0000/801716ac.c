/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801716AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80012FC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_800A5E94;
extern u8 D_800A5E95;
extern u8 D_800A5E96;

s32 func_801716AC(s32 a0, void * a1, s32 * a2)
{
    s32 d;
    s32 p;
    a0 = a0 * 0x10;
    p = a0 + (s32)a1;
    d = (s16)func_80012FC8(*(u8 *)(p + 0xC), (&D_800A5E94)[a0], 10, 1);
    *a2 += d;
    *(char *)(p + 0xC) = *(u8 *)(p + 0xC) + d;
    d = (s16)func_80012FC8(*(u8 *)(p + 0xD), (&D_800A5E95)[a0], 10, 1);
    *a2 += d;
    *(char *)(p + 0xD) = *(u8 *)(p + 0xD) + d;
    d = (s16)func_80012FC8(*(u8 *)(p + 0xE), (&D_800A5E96)[a0], 10, 1);
    *a2 += d;
    *(char *)(p + 0xE) = *(u8 *)(p + 0xE) + d;
}
