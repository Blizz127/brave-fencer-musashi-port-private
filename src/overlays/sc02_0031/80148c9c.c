/* Complete SC02 retail span [80148C9C,80148CB4).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80148C9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char pad[0x12]; s16 field_0x12; } Obj;

s32 func_80148C9C(s32 a0, s32 a1) {
    Obj *p = *(Obj **)((s32)a0 + 0x20);
    p->field_0x12 = (a1 + 0x400) & 0xFFF;
    return 1;
}
