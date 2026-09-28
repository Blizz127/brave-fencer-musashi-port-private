/* Complete SC02 retail span [8014C1A0,8014C1C8).
 * Ahead hole after 4BE9C→4C6D0; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C1A0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014C1C8(s32 arg0, s32 arg1, void *arg2);
extern u8 D_801868B0[];

void func_8014C1A0(s32 arg0, s32 arg1) {
    func_8014C1C8(arg0, arg1, D_801868B0);
}
