/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801842E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80178CBC(s32 arg0, s32 arg1);
extern s32 D_80189484;

void func_801842E0(void *arg0) {
    ((void (*)(void *, void *))func_80178CBC)(arg0, &D_80189484);
    *(s16 *)((u8 *)arg0 + 0x2) = 0x3;
}
