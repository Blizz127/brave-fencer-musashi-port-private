/* SC02.CD member31 PAC0 decoded [80129220,80129248). No C match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80129220 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80129258(void);
extern void func_80129248(s16 a0);

void func_80129220(void) {
    func_80129258();
    func_80129248(1);
}
