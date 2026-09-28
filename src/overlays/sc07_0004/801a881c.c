/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A881C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8005C49C(void);
extern void func_8012AD44(s32 *a0, s16 a1);

void func_801A881C(s32 a0)
{
    s32 r1;
    s32 r2;

    *(u16 *)((s32)a0 + 0xFE) = 0x10;
    r1 = func_8005C49C();
    *(u16 *)((s32)a0 + 0x100) = r1;
    r2 = (func_8005C49C() & 0x1F) + 0x40;
    *(u16 *)((s32)a0 + 0x102) = r2;
    if ((r2 & 1) != 0) {
        *(u16 *)((s32)a0 + 0x102) = -r2;
    }
    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x10) = 0;
    func_8012AD44(a0, 1);
}
