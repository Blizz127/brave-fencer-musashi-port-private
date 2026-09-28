/* Complete SC02 retail span [80182078,801820E0).
 * STOP dispatch D_80198FB8.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80182078 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80188FB8[])(void);
extern void func_801832D0(s32 arg0, s32 arg1);

void func_80182078(void *a0) {
    D_80188FB8[*(u16 *)((s32)a0 + 0x2)]();
    if (*(u16 *)a0 != 0) {
        func_801832D0(*(s16 *)((s32)a0 + 0xA) - 0x380, *(s16 *)((s32)a0 + 0xFE));
    }
}
