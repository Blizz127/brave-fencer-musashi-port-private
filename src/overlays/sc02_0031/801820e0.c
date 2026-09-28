/* Complete SC02 retail span [801820E0,80182174).
 * SC02 820xx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801820E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80029178(s32 a0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_80182994(void *a0);
extern s32 func_8012C51C(void *a0, s32 a1);
extern void func_801832D0(s32 arg0, s32 arg1);
extern u8 D_80188ED8;

void func_801820E0(void *a0) {
    s32 v0;

    if ((func_80029178(0x9C) & 0xFF) != 0) {
        func_801832D0(-0x380, 0);
        func_8012CAE4(a0);
    } else {
        v0 = ((s32 (*)(void))func_8012C1B8)();
        *(s32 *)((s32)a0 + 0x20) = v0;
        if (v0 == 0) {
            func_8012CAE4(a0);
        } else {
            func_8001C214(v0, 0);
            func_80182994(a0);
            func_8012C51C(&D_80188ED8, (s32)a0);
            *(s16 *)((s32)a0 + 0x2) = 1;
        }
    }
}
