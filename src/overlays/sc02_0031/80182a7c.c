/* Complete SC02 retail span [80182A7C,80182AB4).
 * SC02 820xx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80182A7C - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_80182A7C(s32 arg0) {
        s32 v0;
        if (*(s16 *)(arg0 + 0xfc) != *(s16 *)(*(s32 *)(arg0 + 0x64) + 0x36)) {
            ((void (*)(void))func_8012C218)();
        }
    }
