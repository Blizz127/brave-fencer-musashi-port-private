/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A8DCC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_8005C49C(void);
extern void func_801A8E34(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

void func_801A8DCC(s32 a0, s32 a1)
{
    s32 s0;
    s32 v0;

    s0 = func_8005C49C() & 0xFF8;
    v0 = func_8005C49C();
    func_801A8E34(a0, a1, s0, ((v0 & 0xF) + 0x38) << 15, 0x14);
}
