/* SC02 resident retail span [80170EFC,80170F38). Offset 0x48DA4 at base 80128158.
 * SHA256(span)=8a175117d4eaf495dad0db2c7b2f32b3df5be5af69443654682cab9f7ee41211.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818C0->D_801881B0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170EFC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_801881B0[])(void *);

void func_80170EFC(void *a0) {
    D_801881B0[*(u8 *)((s32)a0 + 0x216)](a0);
}
