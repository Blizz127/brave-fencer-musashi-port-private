/* Complete SC02 retail span [80184A2C,80184A9C).
 * Guarded state-kick.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80184A2C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32 a0, void *a1);

void func_80184A2C(void *a0) {

    extern u8 D_801AB818[];
    extern u8 D_801AB5F8[];
    if (*(s16 *)((s32)a0 + 0x98) == 0) {
        *(s16 *)((s32)a0 + 0x2) = 1;
        if (*(s16 *)((s32)a0 + 0xFE) == 1) {
            func_8012A828((s32)a0, D_801AB818);
        } else {
            func_8012A828((s32)a0, D_801AB5F8);
        }
        *(s16 *)((s32)a0 + 0xFE) = 0;
    }
}
