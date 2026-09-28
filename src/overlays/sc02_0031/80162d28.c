/* SC02.CD FILE_031 / ov_SC02_031 retail span [80162D28,80162D88).
 * Offset 0x3ABD0 at overlay base 80128158. SHA256(span)=f657a4c0e22da5a845e919b8886d4f9524bb6c822e8b39a3022b3d6f52aecf6d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80162d28.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80162D28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80013F3C(s32 a0);
extern void func_800126C4(s32 a0, s32 a1);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800123F0(s32 a0, s32 a1);

void func_80162D28(s32 *a0) {
    s16 *s0 = (s16 *)a0[8];
    s32 s1 = (s32)s0 + 0x34;
    func_80013F3C(s1);
    func_800126C4(s1, s0[8]);
    func_80012558(s1, s0[9]);
    func_800123F0(s1, s0[10]);
}
