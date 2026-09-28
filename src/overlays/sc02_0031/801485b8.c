/* Complete SC02 retail span [801485B8,80148634).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801485B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

/* m2c compat (vendor/bfm-decomp/include/common.h). */
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))


void func_801485B8(s32 arg0, s32 arg1, s32 arg2)
{
    M2C_FIELD(arg1, s16 *, 0) = (s16) (s8) M2C_FIELD(arg0, u8 *, 0);
    M2C_FIELD(arg1, s16 *, 2) = (s16) (s8) M2C_FIELD(arg0, u8 *, 1);
    M2C_FIELD(arg1, s16 *, 4) = (s16) (s8) M2C_FIELD(arg0, u8 *, 2);
    M2C_FIELD(arg2, s16 *, 0) = (s16) (s8) M2C_FIELD(arg0, u8 *, 3);
    M2C_FIELD(arg2, s16 *, 2) = (s16) (s8) M2C_FIELD(arg0, u8 *, 4);
    M2C_FIELD(arg2, s16 *, 4) = (s16) (s8) M2C_FIELD(arg0, u8 *, 5);
}
