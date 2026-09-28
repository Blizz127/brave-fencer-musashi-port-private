/* Complete SC02 retail span [8014C3A4,8014C3D0).
 * Ahead hole after 4BE9C→4C6D0; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C3A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8014C43C(void *a0, s32 a1, s32 a2, s32 a3, s16 a5);

s32 func_8014C3A4(void *a0, s32 a1, s32 a2, s32 a3) {
    return func_8014C43C(a0, a1, a2, a3, *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12));
}
