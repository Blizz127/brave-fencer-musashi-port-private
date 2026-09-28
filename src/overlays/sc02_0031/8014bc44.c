/* Complete SC02 retail span [8014BC44,8014BC80).
 * Ahead hole after 4AA28; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014BC44 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_80078EB2;
extern void func_8014BC80(s32 a0, s32 a1);

void func_8014BC44(s32 a0, s32 a1) {
    if (*(s32 *)((s32)a0 + 0x44) & 0x2000000) {
        a1 = D_80078EB2;
    }
    func_8014BC80(a0, a1);
}
