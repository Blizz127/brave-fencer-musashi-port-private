/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172D68 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 D_80126B58;
extern s32 D_80127508;
extern s32 func_80172DAC();
extern s32 func_8014C168(s32 *a0, s32 a1);
extern void func_80174684(void *);

void func_80172D68(s32 a0)
{
    D_80127508 = func_8014C168(&D_80126B58, a0);
    func_80174684(func_80172DAC);
}
