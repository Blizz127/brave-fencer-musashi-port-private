/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A50D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012AD44(s32 *a0, s16 a1);

void func_801A50D4(void * arg0) {
        *(s8 *)((char *)arg0 + 0xfc) = 0x8;
        ((void (*)(s32, s32))func_8012AD44)((int)arg0, 0x2);
    }
