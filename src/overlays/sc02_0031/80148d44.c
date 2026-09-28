/* Complete SC02 retail span [80148D44,80148E54).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80148D44 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8004CFEC(s32 a0, s32 a1);

s32 func_80148D44(void) {

    extern s32 D_801151D4;
    extern u8 D_80126C01;
    extern u16 D_80126C02;
    extern u16 D_80126C06;
    extern s32 D_801867A8[];
    register s32 ang __asm__("$16");
    register s32 a __asm__("$4");
    s32 p;
    s32 res;
    s32 d;

    p = D_801151D4;
    a = (func_8004CFEC(*(s32 *)(p + 0x44) - *(s32 *)(p + 0x50),
                  *(s32 *)(p + 0x48) - *(s32 *)(p + 0x3c)) - 0x400) & 0xFFF;
    d = (s32)D_80126C01;
    __asm__ __volatile__("" : : "r"(a));
    ang = a;
    if (d == 0x53) {
        goto final;
    }
    if (d < 0x54) {
        if (d == 0x41) {
            goto call;
        }
        return 0x41;
    }
    if (d != 0x73) {
        return 0x73;
    }
    goto final;
call:
    return (s32)(s16)((s16 (*)())(D_801867A8[D_80126C02 >> 0xc]))();
final:
    {
        u32 e = D_80126C06;
        if (((e & 0xff) == 0x80) && ((e >> 8) == (e & 0xff))) {
            return -1;
        }
        __asm__ __volatile__("" : : : "memory");
        res = (ang + func_8004CFEC((D_80126C06 & 0xff) - 0x80, 0x80 - (D_80126C06 >> 8))) & 0xFFF;
    }
    return res;
}
