/* Complete SC02 retail span [80146578,8014659C).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80146578 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void * func_8001D074(s32 a0, s32 a1);

/* B28: returns func_8001D074's result; the retail tail call leaves it in v0,
 * which callers read. Byte-identical (gcc-2.7.2-psx -O2). */
void * func_80146578(void) {
    return func_8001D074(6, 0x16);
}
