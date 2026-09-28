/* Complete SC02 retail span [801825E0,80182618).
 * SC02 820xx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801825E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_800D0CE0(void);
extern void func_8012C218(void *a0);

void func_801825E0(s32 param_1) {
        if (((int (*)(void))func_800D0CE0)() != 0) {
            ((void (*)(s32))func_8012C218)(param_1);
        }
    }
