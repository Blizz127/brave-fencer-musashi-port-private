/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A86F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801F8978[3];
extern void func_801A8738();

void func_801A86F8(void) {
    u8 *p = D_801F8978;
    func_801A8738(p);
    func_801A8738(&p[1]);
    func_801A8738(&p[2]);
}
