/* Complete SC02 retail span [801848E4,8018496C).
 * State-0 setup via func_8012C354/func_8012A828.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801848E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);

void func_801848E4(void *a0) {

    extern u8 D_801AAE54[];
    extern u8 D_801AB818[];
    extern u8 D_801AB5F8[];
    s32 ptr;
    unsigned short v1;
    unsigned short v0;

    if (func_8012C354((s32)a0, (s32)D_801AAE54) == 0) {
        return;
    }

    ptr = *(s32 *)((s32)a0 + 0x64);
    v1 = *(unsigned short *)(ptr + 0x36);
    v0 = *(unsigned short *)((s32)a0 + 0x70);
    *(unsigned short *)((s32)a0 + 0xFC) = v1;

    if (v0 & 0x4000) {
        func_8012A828((s32)a0, D_801AB818);
        *(unsigned short *)((s32)a0 + 0x5C) = 0;
    } else {
        func_8012A828((s32)a0, D_801AB5F8);
    }

    *(unsigned short *)((s32)a0 + 0x2) = 1;
}
