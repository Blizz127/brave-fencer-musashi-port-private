/* Complete SC02 retail span [8014C918,8014C968).
 * Gap after 4C6D0→existing 4C968; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C918 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801151F0[];

s32 func_8014C918(s32 a0, s32 a1) {
    s32 v1;
    s32 ret;
    if (a1 == 0x18) {
        return 0x8;
    }
    v1 = 0;
    goto search;
found:
    return ret;
search:
    do {
        ret = v1 & 0xFF;
        if (D_801151F0[ret] == a1) {
            goto found;
        }
        v1 += 1;
    } while ((u32)(v1 & 0xFF) < 0x8);
    return 0;
}
