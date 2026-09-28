/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A8C58 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_8005C49C(void);
extern void func_801A8CE0(s32 a0, s16 a1, s32 a2, s32 a3);
extern void func_801A900C(s32 a0);

void func_801A8C58(s32 s2)
{
    s32 i;
    s32 base;
    s32 y;
    s32 sel;

    i = 0;
    base = -0x40;
    while (i < 0x10) {
        y = base + (func_8005C49C() & 0x7F);
        sel = (i & 1) ? 0xC0000 : 0x140000;
        func_801A8CE0(s2, (s16)y, sel, 0x14);
        i++;
        base += 0x100;
    }
    func_801A900C(s2);
}
