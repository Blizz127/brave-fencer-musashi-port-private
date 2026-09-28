/* Complete SC02 retail span [801496D4,80149704).
 * PAC0 member31 words.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801496D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_801496D4(void *a0) {
    s32 v0 = 0;
    if (*(s32 *)((s32)a0 + 0x178)) {
        return v0;
    }
    v0 = *(u16 *)((s32)a0 + 0xAC) & 0x40;
    if (v0) {
        v0 = 1;
    }
    return v0;
}
