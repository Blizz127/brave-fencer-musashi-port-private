/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1C38 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A36F0(void *a0);
extern void func_801A3744(s32 a0);
extern void func_8012AD44(s32 *a0, s16 a1);

void func_801A1C38(s32 a0) {
    *(s16 *)(a0 + 0xAE) = -1;
    func_801A36F0(a0);
    func_801A3744(a0);
    func_8012AD44((s32 *)a0, 0xB);
}
