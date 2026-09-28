/* Complete SC02 retail span [80149078,801490E0).
 * PAC0 member31 words.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80149078 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801490E0(s32 *a0, s16 a1);
extern void func_801490E8(s32 *a0, s16 a1);
extern void func_801490F0(s32 *a0, s16 a1);

void func_80149078(s32 *a0, s32 a1, s32 a2, s32 a3) {
    func_801490E0(a0, (s16)a1);
    func_801490E8(a0, (s16)a2);
    func_801490F0(a0, (s16)a3);
}
