/* SC02 resident retail span [80170BD8,80170C14). Offset 0x48A80 at base 80128158.
 * SHA256(span)=f665e129a5d58fb1a8cda70f470db0391378f5e2b701f6c0f6e26f3251db9139.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818A0->D_80188190.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170BD8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80188190[])(void *);

void func_80170BD8(void *a0) {
    D_80188190[*(u8 *)((s32)a0 + 0x216)](a0);
}
