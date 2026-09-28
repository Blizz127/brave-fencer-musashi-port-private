/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161CD0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_800CF8B4();
extern void func_80147324(int arg0);
void aF80161CD0(int param_1, unsigned int param_2) __asm__("func_80161CD0");

void aF80161CD0(int param_1, unsigned int param_2)
{

    extern unsigned short D_8017FDE8;
    if (param_2 < 8) {
        if (func_800CF8B4() != 0) {
            func_80147324((&D_8017FDE8)[param_2]);
        }
    }
}
