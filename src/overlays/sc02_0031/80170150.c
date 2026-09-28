/* SC02 resident retail span [80170150,8017018C). Offset 0x47FF8 at base 80128158.
 * SHA256(span)=31c5e6c73a72c3db86d607c560200dc532d48b3f67df553486197a5b1706e07b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181848->D_80188138.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170150 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80188138[])(void);
extern void func_8012A568(void (*a0)(void));

void func_80170150(void *a0) {
    D_80188138[*(u8 *)((s32)a0 + 0x216)]();
}
