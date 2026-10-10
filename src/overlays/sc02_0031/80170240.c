/* SC02 resident retail span [80170240,8017027C). Offset 0x480E8 at base 80128158.
 * SHA256(span)=623d14dd297b604d30a04810b11e08a48d1beaa8872d2cc30b6284008048792d.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181850->D_80188140.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170240 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80188140[])(void *);
extern void func_8012A568(void (*a0)(void));

void func_80170240(void *a0) {
    D_80188140[*(u8 *)((s32)a0 + 0x216)](a0);
}
