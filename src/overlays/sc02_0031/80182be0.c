/* Complete SC02 retail span [80182BE0,80182C24).
 * SC02 820xx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80182BE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_8012A568(void (*a0)(void));
extern void func_801292C8(u8 *a0);

void func_80182BE0(void *a0)
{
    if (func_80128ED8(*(s32 *)((s32)a0 + 0x20), (s32 *)((s32)a0 + 0x24)) == 1) {
        func_801292C8((u8 *)a0);
    }
}
