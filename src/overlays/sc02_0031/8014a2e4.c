/* Complete SC02 retail span [8014A2E4,8014A380).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014A2E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801202A0[];
extern s32 func_8014C278(s32 a0, s32 a1, s32 a2);

s32 func_8014A2E4(s32 a0) {
    register s32 a0v __asm__("$18");
    register u32 i __asm__("$17");
    register u8 *p __asm__("$16");
    a0v = a0;
    i = 0;
    p = D_801202A0;
    do {
        if (*(u16 *)(p + 0x0) != 0
            && (*(u16 *)(p + 0x5C) & 0x8000)
            && *(s16 *)(p + 0xAA) != 0
            && func_8014C278(a0v, (s32)p, 0x30) != 0) {
            return (s32)p;
        }
        i++;
        p += 0x10C;
    } while (i < 0x60);
    return 0;
}
