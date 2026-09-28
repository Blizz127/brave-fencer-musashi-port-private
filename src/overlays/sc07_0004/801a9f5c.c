/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A9F5C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801AA0B4(void *a0);
extern void func_8012AD80(s32 a0);
extern void func_8012AD44(s32 *a0, s16 a1);

void func_801A9F5C(void *arg0) {
    *(s32 *)((s32)arg0 + 0x1C) = 0x40;
    func_801AA0B4(arg0);
    func_8012AD80((s32)arg0);
    func_8012AD80((s32)arg0);
    func_8012AD44((s32 *)arg0, 2);
}
