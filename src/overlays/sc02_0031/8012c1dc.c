/* Complete SC02 retail span [8012C1DC,8012C218).
 * Gap between 2C1B8 and 2C218.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012C1DC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_800B3DF0[];

s32 func_8012C1DC(s32 a0) {
    u8 *p;
    u8 *end;
    p = (u8 *)(*(s32 *)(a0 + 0x20) + 0x84);
    end = D_800B3DF0;
    if (p != end) {
        do {
            if (*(u16 *)p == 0) {
                return (s32)p;
            }
            p += 0x84;
        } while (p != end);
    }
    return 0;
}
