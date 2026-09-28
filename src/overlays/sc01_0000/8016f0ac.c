/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F0AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016F0E4(void);
extern void func_80165770(void);

void func_8016F0AC(void) {
    extern u8 aD80126B58 __asm__("D_80126B58");
    ((void (*)(void *))func_8016F0E4)(&aD80126B58);
    ((void (*)(void *))func_80165770)(&aD80126B58);
}
