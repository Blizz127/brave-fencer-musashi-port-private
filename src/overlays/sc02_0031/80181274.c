/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80181274 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8016EE40(s32 a0, s32 a1, s32 a2);

void func_80181274(void) {

    extern s32 D_80188DC4(void *a0);
    ((void (*)(void *, s32))func_8016EE40)((void *)D_80188DC4, 0x1000000);
}
