/* SC02 resident retail span [8016F8E4,8016F920). Offset 0x4778C at base 80128158.
 * SHA256(span)=a1ea397bea2a26a568a58257b0d60fdd9bff3c63759d57ab85e75873dee22eee.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801817EC->D_801880DC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F8E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801880DC[])(void *);
extern void func_8012A568(void (*a0)(void));

void func_8016F8E4(void *a0) {
    D_801880DC[*(u8 *)((s32)a0 + 0x216)](a0);
}
