/* Complete SC02 retail span [80182BA0,80182BE0).
 * SC02 820xx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80182BA0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80182BA0(void *arg)
{
    s32 *a = arg;
    if (--*(s32 *)((char *)a + 0x1C) <= 0) {
        s32 *p = *(s32 **)((char *)a + 0x20);
        p[1] = p[1] & 0x7FFFFFFF;
        *(s16 *)((char *)a + 0x2) = 1;
    }
}
