/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801577C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int D_80195468;
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80157808(void *param_1);

void func_801577C8(s32 arg0) {
    D_80195468 = 0x12C;
    func_80147078(arg0, 7);
    func_80157808(arg0);
}
