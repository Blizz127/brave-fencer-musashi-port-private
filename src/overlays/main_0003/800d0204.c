/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0204 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_800EC8B0;
extern void func_800D1E58(void);
extern void func_800D0D6C(void);
extern void func_800118AC(void);

void func_800D0204(void) {
    if (D_800EC8B0) {
        func_800D1E58();
        func_800D0D6C();
        func_800118AC();
    } else {
        func_800118AC();
    }
}
