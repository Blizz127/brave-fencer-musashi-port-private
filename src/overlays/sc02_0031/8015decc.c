/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DECC,8015DF34).
 * Offset 0x35D74 at overlay base 80128158. SHA256(span)=28c5c43f15d92f3507a1a38e5f97b2585819ebb0ef2231dc27f67f7727f5877c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015decc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015DECC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_8015E018(s32 a0);
extern void func_80147300(u16 arg0);
extern void func_801553A8(s32 *a0);
extern void func_8014BD60(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);

void func_8015DECC(s32 a0) {
    func_80154150(a0, 0x1C);
    func_80154A74(a0, 0x19);
    *(s32 *)(a0 + 0x234) = 0;
    func_8015E018(a0);
    func_80147300(0x5F5);
    func_801553A8((s32 *)a0);
    func_8014BD60(a0, 4);
    func_80146CA0((void *)a0);
}
