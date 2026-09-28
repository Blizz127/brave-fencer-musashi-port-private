/* Complete SC02 retail span [8014A638,8014A738).
 * Ahead hole after 4A59C; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014A638 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8014A638(s32 arg0) {
    s16 v;
    if (*(s32 *)((s32)arg0 + 0x44) & 0x10) {
        v = *(u16 *)((s32)arg0 + 0x188) - 4;
        *(s16 *)((s32)arg0 + 0x188) = v;
        if (v < 0) {
            *(s16 *)((s32)arg0 + 0x188) = 0;
        }
    }
}
