/* Complete SC02 retail span [80149290,80149350).
 * PAC0 member31 words.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80149290 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149350(s32 arg0);

void func_80149290(s32 a0) {
    volatile s32 a;
    volatile s32 b;
    volatile s32 c;
    a = *(s32 *)(*(s32 *)(a0 + 0x20) + 0x48);
    b = *(s32 *)(*(s32 *)(a0 + 0x20) + 0x4C);
    c = *(s32 *)(*(s32 *)(a0 + 0x20) + 0x4C);
    *(s32 *)(*(s32 *)(a0 + 0x20) + 0x48) = *(s16 *)(a0 + 6);
    *(s32 *)(*(s32 *)(a0 + 0x20) + 0x4C) = *(s16 *)(a0 + 0xA);
    *(s32 *)(*(s32 *)(a0 + 0x20) + 0x50) = *(s16 *)(a0 + 0xE);
    func_80149350(a0);
    *(s32 *)(*(s32 *)(a0 + 0x20) + 0x48) = a;
    *(s32 *)(*(s32 *)(a0 + 0x20) + 0x4C) = b;
    *(s32 *)(*(s32 *)(a0 + 0x20) + 0x50) = c;
}
