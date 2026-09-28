/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A38A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012C218(void *a0);

void func_801A38A8(s32 arg0) {
    if (*(u32 *)(*(u32 *)(arg0 + 0x64) + 0xE0) & 0x10) {
        func_8012C218((void *)arg0);
    }
}
