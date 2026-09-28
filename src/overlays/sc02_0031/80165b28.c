/* SC02 resident retail span [80165B28,80165B6C). Offset 0x3D9D0 at base 80128158.
 * SHA256(span)=2338b115028b24b69fa3a75f1970a7943a2e056c3fe7c1386dbe87dd0f28ef7c.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181254->D_80187B44.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165B28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187B44[])(void);

void func_80165B28(void *a0) {
    *(u32 *)((s32)a0 + 0x44) |= 8;
    D_80187B44[*(u8 *)((s32)a0 + 0x197)]();
}
