/* Complete SC02 retail span [8014942C,80149450).
 * PAC0 member31 words.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014942C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012F038(int param_1, short *param_2, short *param_3);

void func_8014942C(s32 arg0) {
    ((void (*)())func_8012F038)(*(s32 *)(arg0 + 0x20) + 0x34);
}
