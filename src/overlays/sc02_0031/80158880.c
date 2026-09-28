/* SC02 resident retail span [80158880,801588CC). Offset 0x30728 at base 80128158.
 * SHA256(span)=46901c75bac2ec070af8017941af17c895672db256c4ffcbaf6ba5eec6e84fd5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018071C->D_8018700C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158880 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149020(s32 *a0);
extern void (*D_8018700C[])(s32 *);

void func_80158880(s32 *param) {
    func_80149020(param);
    D_8018700C[*(u8 *)((s32)param + 0x4F)](param);
}
