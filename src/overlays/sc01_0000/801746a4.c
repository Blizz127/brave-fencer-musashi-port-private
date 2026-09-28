/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801746A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80172760(s32 a0);
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_80174684(void *);

void func_801746A4(void)
{
    ((void (*)(void *, int))func_8016EDEC)(func_80172710, 0x1000000);
    func_80174684(func_80172760);
}
