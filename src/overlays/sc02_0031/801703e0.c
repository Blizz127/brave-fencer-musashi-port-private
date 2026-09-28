/* SC02 resident retail span [801703E0,8017041C). Offset 0x48288 at base 80128158.
 * SHA256(span)=d30cf315dd455aa9a10fbb2ad0f30d46e0d4f632baa8f225a9c073ce8b3e8099.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181860->D_80188150.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801703E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80188150[])(void);
extern void func_8012A568(void (*a0)(void));

void func_801703E0(void *a0) {
    D_80188150[*(u8 *)((s32)a0 + 0x216)]();
}
