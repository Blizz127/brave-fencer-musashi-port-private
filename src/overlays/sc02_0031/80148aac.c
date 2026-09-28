/* Complete SC02 retail span [80148AAC,80148AFC).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80148AAC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_80148AFC(void *a0);

void func_80148AAC(u8 *a0) {
    u8 *v1;
    if ((func_80148AFC(a0) & 0xff) != 0) {
        v1 = *(u8 **)(a0 + 0x20);
        *(u16 *)(v1 + 0x12) = (*(u16 *)(v1 + 0x12) + 0xFA) & 0xFF8;
    }
}
