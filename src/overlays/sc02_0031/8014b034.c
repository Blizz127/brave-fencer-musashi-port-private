/* Complete SC02 retail span [8014B034,8014B084).
 * Ahead hole after 4AA28; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014B034 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014B084(void);
extern s16 D_80078E90;

void func_8014B034(s32 a0)
{
    register s16 *ptr = &D_80078E90;
    s16 v;
    v = ptr[1] + a0;
    ptr[1] = v;
    if (v >= 0x5A0) {
        ptr[1] = v - 0x5A0;
        func_8014B084();
    }
}
