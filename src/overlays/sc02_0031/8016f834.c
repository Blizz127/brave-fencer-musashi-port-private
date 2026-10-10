/* SC02 resident retail span [8016F834,8016F870). Offset 0x476DC at base 80128158.
 * SHA256(span)=24f603c4c2b6ec4d3f8f28084ad28a6695b49fccdcee7541923745e3dcbee6eb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801817E4->D_801880D4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F834 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801880D4[])(void *);
extern void func_8012A568(void (*a0)(void));

void func_8016F834(void *a0) {
    D_801880D4[*(u8 *)((s32)a0 + 0x216)](a0);
}
