/* Complete SC02 retail span [801490E0,801490E8).
 * PAC0 member31 words.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801490E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801490E0(s32 *a0, s16 a1) {
    *(s16*)((s32)a0 + 0x108) = a1;
}
