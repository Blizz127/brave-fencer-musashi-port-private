/* SC02 resident retail span [801714E4,80171520). Offset 0x4938C at base 80128158.
 * SHA256(span)=282a8af411aa4dda842a3a8e00547338f11cf628ea5e1a8271604135d1bde014.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818F0->D_801881E0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801714E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_801881E0[])(void);

void func_801714E4(void *a0) {
    D_801881E0[*(u8 *)((s32)a0 + 0x216)]();
}
