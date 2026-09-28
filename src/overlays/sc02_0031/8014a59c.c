/* Complete SC02 retail span [8014A59C,8014A638).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014A59C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EBF;
extern s32 func_80029178(s32 arg);

void func_8014A59C(s32 a0) {
    s32 r;
    s32 add;
    if (*(u32 *)(a0 + 0x44) & 1) {
        if ((*(u16 *)(a0 + 0xAA) & 8) != 0) {
            r = func_80029178(0x20);
            add = 3;
            if ((r & 0xFF) != 0) {
                add = 6;
            }
            D_80078EBF = D_80078EBF + add;
            if (0x80 < D_80078EBF) {
                __asm__ __volatile__("");
                D_80078EBF = 0x80;
            }
        }
    } else {
        D_80078EBF = 0;
    }
}
