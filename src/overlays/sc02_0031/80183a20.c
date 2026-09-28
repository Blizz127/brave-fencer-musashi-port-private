/* Complete SC02 retail span [80183A20,80183BB0).
 * Live STOP 83AC8 cluster; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80183A20 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_800183E0(s32 a0);

void func_80183A20(s32 param_1) {

    extern u16 D_800B99DA;
    extern u8 D_80189354[];
    extern u8 D_801B4A44[];
    *(u8 *)(*(s32 *)(param_1 + 0xCC) + 0x27) = 0xA3;
    func_800183E0((s32)&D_801B4A44[D_80189354[D_800B99DA & 0x1F] * 16]);
}
