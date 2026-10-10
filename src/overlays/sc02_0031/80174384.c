/* SC02 resident retail span [80174384,801743C0). Offset 0x4C22C at base 80128158.
 * SHA256(span)=9ce15fd62fd6ea093dd6034d10df01dd9fe0420abd7a4a0b128ea66d45892315.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801819CC->D_801882BC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174384 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_80174384(void *a0) {

    extern void (*D_801882BC[])(void *);
    D_801882BC[*(u8 *)((s32)a0 + 0x214)](a0);
}
