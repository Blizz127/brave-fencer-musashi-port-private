/* Complete SC02 retail span [8014C43C,8014C4AC).
 * Ahead hole after 4BE9C→4C6D0; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C43C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 func_80156370(u16 a0);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);

s32 func_8014C43C(void * a0, s32 a1, s32 a2, s32 a3, s16 a4)
{
    u16 v0;
    v0 = func_80156370((u16)a2);
    func_8014C4AC(a1, a2, v0 & 0xFFFF, a3, (s16)a4);
}
