/* Complete SC02 retail span [8012C194,8012C1B8).
 * Live STOP leaf before 2C1B8.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012C194 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8001D074(s32 a, s32 b);

void func_8012C194(void) {
    func_8001D074(0x3E, 0x7D);
}
