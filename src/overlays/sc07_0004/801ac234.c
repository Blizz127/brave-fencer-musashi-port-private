/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AC234 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80128ED8(s32 a0, s32 *a1);

void func_801AC234(void *a0)
{
    extern void func_801292C8(u8 *a0);
    extern void func_8012931C(struct vec *a0);

    func_8012931C((struct vec *)a0);
    if (func_80128ED8(*(s32 *)((char *)a0 + 0x20), (s32 *)((char *)a0 + 0x24)) != 0 ||
        (*(s16 *)((char *)a0 + 0x2C) != 2 && *(s16 *)((char *)a0 + 0xA) >= -0x200)) {
        func_801292C8((u8 *)a0);
    }
}
