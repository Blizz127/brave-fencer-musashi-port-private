/* SC02 resident retail span [8016DEA4,8016DEE0). Offset 0x45D4C at base 80128158.
 * SHA256(span)=fd9333ca0fd59c131b82657ee0ccc8eba611ff51a637eb1342041ac6e1126d59.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801816B0->D_80187FA0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016DEA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187FA0[])(void *);
extern void func_8012A568(void (*a0)(void));

void func_8016DEA4(void *a0) {
    D_80187FA0[*(u16 *)((s32)a0 + 0x2)](a0);
}
