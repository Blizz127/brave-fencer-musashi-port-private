/* Complete SC02 retail span [80147628,80147718).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80147628 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80013F3C(s32 a0);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800126C4(s32 a0, s32 a1);
extern void func_800123F0(s32 a0, s32 a1);

void func_80147628(s32 a0) {
    s32 s2 = *(s32 *)(a0 + 0x20);
    s32 s1 = s2 + 0x34;
    func_80013F3C(s1);
    func_80012558(s1, *(s16 *)(a0 + 0x102));
    func_800126C4(s1, *(s16 *)(a0 + 0x100));
    func_800123F0(s1, *(s16 *)(a0 + 0x104));
    if (*(u16 *)(a0 + 0x136) & 2) {
        func_80012558(s1, *(s16 *)(a0 + 0x132));
    } else {
        func_80012558(s1, *(s16 *)(s2 + 0x12));
    }
    if (*(u16 *)(a0 + 0x136) & 1) {
        func_800126C4(s2 + 0x34, *(s16 *)(a0 + 0x130));
    } else {
        func_800126C4(s2 + 0x34, *(s16 *)(s2 + 0x10));
    }
    if (*(u16 *)(a0 + 0x136) & 4) {
        func_800123F0(s2 + 0x34, *(s16 *)(a0 + 0x134));
    } else {
        func_800123F0(s2 + 0x34, *(s16 *)(s2 + 0x14));
    }
}
