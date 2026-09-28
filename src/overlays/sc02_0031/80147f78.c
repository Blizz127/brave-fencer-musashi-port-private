/* Complete SC02 retail span [80147F78,80148038).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80147F78 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147928(int a0, int a1);
extern void func_8014799C(int a0, int a1);
extern void func_80147A10(int a0, int a1);
extern volatile s32 D_80127090;
extern volatile s32 D_80127094;
extern volatile s32 D_80127098;

void func_80147F78(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 reserved[16];
    s32 t;
    func_80147928(a0, a1);
    func_8014799C(a0, a2);
    func_80147A10(a0, a3);
    D_80127090 = *(s32 *)(a0 + 0x24);
    t = D_80127090;
    D_80127094 = *(s32 *)(a0 + 0x28);
    D_80127098 = *(s32 *)(a0 + 0x2C);
    *(s32 *)(a0 + 0x10) = t;
    *(s32 *)(a0 + 0x14) = D_80127094;
    *(s32 *)(a0 + 0x18) = D_80127098;
    D_80127090 = 0;
    D_80127094 = 0;
    D_80127098 = 0;
    (void)reserved;
}
