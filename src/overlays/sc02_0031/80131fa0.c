/* SC02 resident retail span [80131FA0,80131FDC). Offset 0x9E48 at base 80128158.
 * SHA256(span)=5fe57d8ab749ed4198591e846748fce7ce2531f53d479435fd6b44ff8496a133.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E900->D_801851F0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80131FA0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void (*D_801851F0[])(void *);

void func_80131FA0(void *a0) {
    D_801851F0[*(u16 *)((s32)a0 + 0x2)](a0);
}
