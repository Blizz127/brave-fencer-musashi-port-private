/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161C24 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147324();

void func_80161C24(int param_1, int param_2)
{

    extern unsigned short D_80180A8C[];
    extern unsigned short D_80180A8E[];

    if ((unsigned int)param_2 < 8) {
        if (*(u8 *)(param_1 + 0xDA) != 0) {
            func_80147324(D_80180A8C[(unsigned int)param_2 * 2]);
            *(u8 *)(param_1 + 0xDA) = 0;
        } else {
            func_80147324(D_80180A8E[(unsigned int)param_2 * 2]);
            *(u8 *)(param_1 + 0xDA) = 1;
        }
    }
}
