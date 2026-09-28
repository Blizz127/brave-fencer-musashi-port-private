/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017A094 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80179B74(u16 *p);
extern s32 D_8019654C;

void func_8017A094(s32 arg0) {
    s16 sp10;

    D_8019654C = arg0;
    sp10 = 0x15;
    func_80179B74(&sp10);
}
