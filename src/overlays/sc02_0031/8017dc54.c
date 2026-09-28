/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017DC54 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_8014C088(s32 a0, s32 a1);
extern s32 func_8014CB58(void);
extern s32 func_80171990(u8 *a0);
extern void func_8014B5C4(s32 *a0, s32 a1, s32 a2);

void func_8017DC54(s32 a0)
{
    if (func_8014C088(a0, 0x16) == 0)
    {
        *(s32 *)(a0 + 0x44) &= ~0x20000;
        func_8014B5C4((s32 *)a0, func_8014CB58() & 0xFF, 0x80);
        func_80171990((u8 *)a0);
    }
}
