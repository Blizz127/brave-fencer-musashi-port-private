/* SC02 resident retail span [8016F9C4,8016FA00). Offset 0x4786C at base 80128158.
 * SHA256(span)=da875f56dd493691adeb652f1350d7dd96b081a508ab7013c1c7bd89be0579cd.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801817F4->D_801880E4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F9C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801880E4[])(void *);
extern void func_8012A568(void (*a0)(void));

void func_8016F9C4(void *a0) {
    D_801880E4[*(u8 *)((s32)a0 + 0x216)](a0);
}
