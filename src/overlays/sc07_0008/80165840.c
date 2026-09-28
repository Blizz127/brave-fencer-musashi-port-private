/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165840 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC3;
extern void func_80165874(void);

void func_80165840(void) {
    if (D_80078EC3 != 0) {
        D_80078EC3 = 0;
        func_80165874();
    }
}
