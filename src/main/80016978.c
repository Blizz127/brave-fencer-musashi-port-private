/* Main-exec range [80016978,80016A3C) from the SLUS executable.
 * SHA256(span)=f42d53c8dd5f4c86f7c8e039340b5d199dbe9c4e6994fdc7598917856f47f191.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80016978 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800AF630[];
extern u8 D_80062BA0[];
extern s32 D_800B9A18;
extern u16 D_800AF7CE;
extern void func_80016450(s32 a0, s32 a1);

s32 func_80016978(s32 arg0) {
    register u32 zr __asm__("$0");
    register s32 v1 __asm__("$3");
    s32 x = arg0 + zr;
    u8 *s0 = D_800AF630;
    s32 mask = arg0 & 3;
    u32 raw;
    u32 a0;
    u32 v0;

    if (mask == 0) {
        v1 = D_80062BA0[D_800B9A18];
    } else {
        v1 = D_80062BA0[mask];
    }
    D_800AF7CE = D_800AF7CE + v1;
    __asm__ __volatile__("" ::: "memory");
    raw = *(u16 *)&s0[0x19E];
    a0 = raw + zr;
    if (a0 >= 0xFFU) {
        a0 = 0xFF;
    }
    v0 = ((x & 0xFFFFU) < 4U) ? 0xFF - a0 : a0;
    func_80016450(v0 & 0xFF, 0);
    return *(u16 *)&s0[0x19E] >= 0xFF;
}
