/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80141C0C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u16 D_80115110;
extern u8 D_8017FF5C;
extern void func_8002D4C8(s32 a0, s32 a1);

void func_80141C0C(s32 param_1)
{
    func_8002D4C8(*(u16 *)(&D_8017FF5C + (((param_1 << 16) >> 15) + (u32)D_80115110) * 2), 0);
}
