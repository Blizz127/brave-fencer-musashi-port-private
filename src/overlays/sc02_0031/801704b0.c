/* SC02 resident retail span [801704B0,801704EC). Offset 0x48358 at base 80128158.
 * SHA256(span)=c8ef39cf7ce31d0ea37f00b4f47a98c912468b9aebea7826e2308f5c10ffa36f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181868->D_80188158.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801704B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80188158[])(void);
extern void func_8012A568(void (*a0)(void));

void func_801704B0(void *a0) {
    D_80188158[*(u8 *)((s32)a0 + 0x216)]();
}
