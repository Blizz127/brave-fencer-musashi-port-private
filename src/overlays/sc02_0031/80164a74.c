/* SC02.CD FILE_031 / ov_SC02_031 retail span [80164A74,80164ACC).
 * Offset 0x3C91C at overlay base 80128158. SHA256(span)=d5da36fdb2a5b311939ab45717c6ce17d84b255a2cc2900674dbbbd619e0516b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80164a74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164A74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80148534(s32 a0, s32 a1);
extern void func_80015954(s32 a0, s32 a1);
extern void func_80149374(s32 a0, s32 a1);

void func_80164A74(s32 *a0) {
    s32 sp10[2];
    s32 sp18[2];
    s32 s1 = a0[0x4C / 4];
    func_80148534((s32)sp10, (s32)sp18);
    func_80015954((s32)sp10, (s32)a0 + 4);
    func_80149374(s1, (s32)a0 + 4);
}
