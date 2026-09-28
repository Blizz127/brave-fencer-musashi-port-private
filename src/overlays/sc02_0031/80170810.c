/* SC02 resident retail span [80170810,8017084C). Offset 0x486B8 at base 80128158.
 * SHA256(span)=88687f5f17fd6fedb41cb8e61eec796f1912880cbb11343ce8ecf57e4b29b0a8.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181890->D_80188180.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170810 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void (*D_80188180[])(void);

void func_80170810(void *a0) {
    D_80188180[*(u8 *)((s32)a0 + 0x216)]();
}
