/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017A3D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern short D_8019656C;
extern short D_80196568;
extern int func_800D0CA0(int);
extern int func_8001AAA0(void);
extern int func_800D0CE0(void);

int func_8017A3D8(void)
{
    switch (D_8019656C) {
    case 0:
        func_800D0CA0(1);
        D_8019656C = D_8019656C + 1;
        return 0;
    case 100:
    {
        register int a __asm__("$4");
        a = D_80196568;
        if (a != -1) {
            return func_8001AAA0() != 0;
        }
        return func_800D0CE0() == 1;
    }
    default:
        D_8019656C = D_8019656C + 1;
        if (D_8019656C < 0x1E) {
            return 0;
        }
        D_8019656C = 100;
        return 0;
    }
}
