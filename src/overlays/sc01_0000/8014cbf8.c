/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014CBF8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8014CBF8(void *a0) {
    s32 v1 = *(s32 *)((s32)a0 + 0x174);
    if (v1 != 0) {
        if (*(u16 *)(v1 + 0) != 0) {
            *(s32 *)((s32)a0 + 0x174) = 0;
            *(s8 *)(v1 + 0x74) = 0;
        }
    }
}
