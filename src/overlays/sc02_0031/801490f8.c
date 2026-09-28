/* Complete SC02 retail span [801490F8,80149184).
 * PAC0 member31 words.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801490F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);

void func_801490F8(s32 a0, s32 a1) {
    s32 s0 = a0;
    s32 s1 = (s16)a1;
    *(s16 *)(s0 + 0x100) =
        *(u16 *)(s0 + 0x100) +
        func_80012B04(*(s16 *)(s0 + 0x100), *(s16 *)(s0 + 0x108), s1);
    *(s16 *)(s0 + 0x102) =
        *(u16 *)(s0 + 0x102) +
        func_80012B04(*(s16 *)(s0 + 0x102), *(s16 *)(s0 + 0x10A), s1);
    *(s16 *)(s0 + 0x104) =
        *(u16 *)(s0 + 0x104) +
        func_80012B04(*(s16 *)(s0 + 0x104), *(s16 *)(s0 + 0x10C), s1);
}
