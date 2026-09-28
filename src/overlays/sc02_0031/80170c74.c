/* SC02 resident retail span [80170C74,80170CB0). Offset 0x48B1C at base 80128158.
 * SHA256(span)=4b1074ed73ae3b245cd70953ccb4e972b9dcccd315fa78dce86726bb8ded8680.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818A8->D_80188198.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170C74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80188198[])(void);

void func_80170C74(void *a0) {
    D_80188198[*(u8 *)((s32)a0 + 0x215)]();
}
