/* Complete SC02 retail span [8014B504,8014B598).
 * Ahead hole after 4AA28; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014B504 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8016F1AC(void);
extern s16 D_80078E9A;
extern s32 D_80078E98;

void func_8014B504(u16 *a0) {
    s32 v1;
    if (func_8016F1AC() != 0) {
        return;
    }
    if (*a0 == 0x1E || *a0 == 0x1A) {
        return;
    }
    if ((D_80078E9A & 0x8000) == 0) {
        return;
    }
    v1 = D_80078E98 + 0x1555;
    D_80078E98 = v1;
    if (0x257F6A < (v1 & 0x7FFF0000)) {
        D_80078E98 = 0;
    }
}
