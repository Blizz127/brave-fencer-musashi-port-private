/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161BE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_801497A8(void);
extern void func_801599A4(void *a0);
extern void func_80149864(void);

int func_80161BE0(void *param_1)
{
    if (func_801497A8() == 0) {
        return 0;
    }
    func_801599A4(param_1);
    ((void (*)(void *))func_80149864)(param_1);
    return 1;
}
