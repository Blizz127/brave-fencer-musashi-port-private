/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017F1F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern int func_80178970(void);
extern void func_80178D18(void);
extern void func_80029124(s32 a0, s32 a1);
extern void func_8012C218(void*);

void func_8017F1F4(s32 a0)
{

    extern u8 D_80188C14[];
    if (func_80178970() == 0) return;

    ((void (*)(s32))func_80178D18)(a0);

    func_80029124((s32)D_80188C14[*(s16 *)((s32)a0 + 0x70)], 1);
    ((void (*)(s32))func_8012C218)(a0);
}
