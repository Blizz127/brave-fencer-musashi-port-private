/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012C2D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80120194[];
extern u8 D_801202A0[];

s32 func_8012C2D0(void)
{
    s32 p;
    s32 it;
    it = (s32)D_80120194;
    __asm__ __volatile__("" : "=r"(it) : "0"(it));
    p = it + 0x658C;
    goto test;
copy:
    return it;
test:
    it = (s32)D_801202A0;
    __asm__ __volatile__("" : "=r"(it) : "0"(it));
    if (it == p) goto zero;
body:
    if (*(u16 *)it == 0) goto copy;
    it += 0x10C;
    if (it != p) goto body;
zero:
    return 0;
}
