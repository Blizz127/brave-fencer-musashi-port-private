/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80184760 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8012C218(void *a0);

void func_80184760(void * arg0) {
        *(short *)((char *)arg0 + 0x2) = 2;
        ((void (*)(s32))func_8012C218)(*(s32 *)((char *)arg0 + 0xcc));
    }
