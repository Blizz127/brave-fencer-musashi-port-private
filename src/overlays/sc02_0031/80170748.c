/* SC02 resident retail span [80170748,80170784). Offset 0x485F0 at base 80128158.
 * SHA256(span)=51b70fb0fc0903dfec7dc269a35a2647790880e1f47088725a0502777dd93abb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181888->D_80188178.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170748 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80188178[])(void);

void func_80170748(void *a0) {
    D_80188178[*(u8 *)((s32)a0 + 0x216)]();
}
