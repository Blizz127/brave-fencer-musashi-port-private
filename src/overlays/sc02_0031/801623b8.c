/* SC02.CD FILE_031 / ov_SC02_031 retail span [801623B8,80162414).
 * Offset 0x3A260 at overlay base 80128158. SHA256(span)=f8363491cf915bd3ba4c28297e16736d4bc29e185f5ab28fccb03daa30eb4731.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801623b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801623B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D0C48(s32 a0);
extern void func_800167B8(s32 a0);

s32 func_801623B8(s32 *a0) {
    if (--a0[0xA] == -1) {
        func_800D0C48(1);
        func_800167B8(4);
        *((u8 *)a0 + 0x15) += 1;
    }
    return 0;
}
