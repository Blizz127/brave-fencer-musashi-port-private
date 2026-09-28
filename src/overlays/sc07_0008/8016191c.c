/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016191C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014C010(int a0, int a1);
int aF8016191C(int param_1, unsigned int param_2) __asm__("func_8016191C");

int aF8016191C(int param_1, unsigned int param_2) {
    if (param_2 & 1) {
        func_8014C010(param_1, 1);
        return 1;
    }
    if (param_2 & 0x4000) {
        func_8014C010(param_1, 1);
        return 2;
    }
    if (param_2 & 0x2000) {
        func_8014C010(param_1, 1);
        return 4;
    }
    return 0;
}
