/* Exact retail word export for [80015A74,80015AD0); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80015A74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


unsigned int func_80015A74(unsigned int param_1) {
    unsigned int result;
    unsigned int divisor;
    int i;

    divisor = 1000000000;
    result = 0;
    for (i = 0; i < 10; i++) {
        result = (result << 4) | (param_1 / divisor);
        param_1 = param_1 % divisor;
        divisor = divisor / 10;
    }
    return result;
}
