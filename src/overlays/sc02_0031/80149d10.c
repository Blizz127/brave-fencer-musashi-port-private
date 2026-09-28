/* Complete SC02 retail span [80149D10,80149D9C).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80149D10 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 func_8014B5B8(s32 *a0);
extern u8 D_80078EBF;
extern u8 D_80078EC0;

s32 func_80149D10(s32 a0) {
    if (*(s32 *)(a0 + 0x44) & 0x400) {
        return 0;
    }
    if (D_80078EBF != 0x80) {
        return 0;
    }
    if ((D_80078EC0 & 0x7F) == 0) {
        return 0;
    }
    if (*(u16 *)(a0 + 0xAC) & 0x10) {
        if ((func_8014B5B8((s32 *)a0) & 0xFF) != 0) {
            return 2;
        }
        return 1;
    }
    return 0;
}
