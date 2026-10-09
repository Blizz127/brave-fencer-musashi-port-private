/* SC02 resident retail span [80162330,8016236C). Offset 0x3A1D8 at base 80128158.
 * SHA256(span)=a5361498eee65b64101b39da149520b0e34581d5dc24690782c67bfe457c4911.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180EE0->D_801877D0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80162330 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801877D0[])(void *);

void func_80162330(void *a0) {
    D_801877D0[*(u8 *)((s32)a0 + 0x15)](a0); /* retail jalr keeps a0 */
}
