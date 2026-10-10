/* SC02 resident retail span [80143C38,80143C74). Offset 0x1BAE0 at base 80128158.
 * SHA256(span)=bdd31f7e907e2bd4dbb030c2477e88cbcb76faadbee3f7aabbbea1ac2b682cd9.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017FCB0->D_801865A0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80143C38 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void (*D_801865A0[])(void *);

void func_80143C38(void *a0) {
    D_801865A0[*(u16 *)((s32)a0 + 0x2)](a0);
}
