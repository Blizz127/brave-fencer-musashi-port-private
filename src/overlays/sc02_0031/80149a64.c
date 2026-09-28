/* Complete SC02 retail span [80149A64,80149AA8).
 * PAC0 member31 words.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80149A64 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80149AA8(s32 *a0);
extern s32 func_80149B54(s32 *a0);

s32 func_80149A64(s32 *a0) {
    if (func_80149AA8(a0) || func_80149B54(a0)) {
        return 1;
    }
    return 0;
}
