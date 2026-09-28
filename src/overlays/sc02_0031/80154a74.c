/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154A74,80154AB4).
 * Offset 0x2C91C at overlay base 80128158. SHA256(span)=c8dcb976f87e6f1b3b56d20dd17ac8bda546580fee961a159ef0a228e2d2ff5a.
 * STOP pc=80154a74 (func_80154A74), CPU_BOUNDARY/REFUSED, ra=8015a1e8.
 * Callee from burned func_8015A1C8 (jal 0C05529D); calls sibling func_80154AB4 (jal 0C0552AD).
 * Donor shape: Druthulu shared/ov/func_80154A74.h (compare *(a0+0xD0) vs (*(s32**)(a0+0xCC))[a1]; else func_80154AB4).
 * NOT MAIN10; NOT in parked PAC0 hole 8014E934…80153C8C; later SC02 text near jr_80154C24 / shared OV body.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154A74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154AB4(s32 a0, s32 a1);

void func_80154A74(s32 a0, s32 a1) {
    if (*(s32 *)(a0 + 0xD0) != ((s32 *)*(s32 **)(a0 + 0xCC))[a1]) {
        func_80154AB4(a0, a1);
    }
}
