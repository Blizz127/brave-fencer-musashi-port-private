/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015ACC4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8014ED28();
extern void func_8014FA04(s32 a0);
extern void func_8015ADB0(s32 a0);

void func_8015ACC4(s32 *arg0) {
    func_80147078(arg0, 2);
    func_8014ED28((s32)arg0);
    func_8014FA04((s32)arg0);
    func_8015ADB0((s32)arg0);
}
