/* SC02 resident retail span [8016DF20,8016DF5C). Offset 0x45DC8 at base 80128158.
 * SHA256(span)=8e4b71b1bb373d3f5d1662aac93ab8c91e50653725946fd67bfe7023a490b2f1.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801816B8->D_80187FA8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016DF20 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187FA8[])(void *);
extern void func_8012A568(void (*a0)(void));

void func_8016DF20(void *a0) {
    D_80187FA8[*(u16 *)((s32)a0 + 0x2)](a0);
}
