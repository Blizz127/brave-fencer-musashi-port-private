/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171FFC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_8017248C(s32, s32);
extern s32 func_8004CFEC(s32, s32);
extern void func_80172170(s32, s32);
extern void func_80146D90(s32);

s32 func_80171FFC(short *a0, short *a1, s32 a2)
{
    s32 r;
    r = func_8017248C((s32)a0, (s32)a1);
    if (r != 0) {
        func_80146D90((s32)a0);
        return r;
    }
    *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) =
        (func_8004CFEC(a1[0] - a0[3], a1[2] - a0[7]) + 0x800) & 0xFFF;
    func_80172170((s32)a0, a2 & 0xFF);
    return 0;
}
