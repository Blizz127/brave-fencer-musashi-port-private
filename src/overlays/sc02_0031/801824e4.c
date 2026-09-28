/* Complete SC02 retail span [801824E4,801825E0).
 * SC02 820xx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801824E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_8005C49C(void);
extern s32 D_80188E80[];
extern s32 func_80182618(s32 a0);
extern void func_801829A0(void *a0);
extern void func_801829A8(void *a0);
extern s32 func_80182AB4(s32 a0, s16 a1, s32 a2);
extern s32 func_8012BEE8(s32 a0);

void func_801824E4(void *a0) {
    s32 i;
    s32 *p;

    switch (*(u16 *)((s32)a0 + 0x34)) {
    case 0:
        if (*(s32 *)((s32)a0 + 0xE0) != 0) {
            i = 0;
            p = D_80188E80;
            for (; i < 11; i++) {
                func_80182AB4(p, 0x7FFF, func_8005C49C() & 1);
                p = (s32 *)((s8 *)p + 8);
            }
            (*(s32 *)((s32)a0 + 0xE0))--;
        }
        if (func_8012BEE8(a0) != 0) {
            *(s32 *)((s32)a0 + 0x1C) = 0x1E;
            *(u16 *)((s32)a0 + 0x34) += 1;
        }
        break;
    case 1:
        func_801829A8(a0);
        if (func_8012BEE8(a0) != 0) {
            *(u16 *)((s32)a0 + 0x34) += 1;
            func_801829A0(a0);
        }
        break;
    case 2:
        break;
    }
    func_80182618(a0);
}
