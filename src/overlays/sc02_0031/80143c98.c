/* SC02 resident retail span [80143C98,80143CD4). Offset 0x1BB40 at base 80128158.
 * SHA256(span)=9d547e592b5bff864f8c1412625d2636355b480071a907c5dd8bf1a1d7df188a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017FCB8->D_801865A8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80143C98 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void (*D_801865A8[])(void *);

void func_80143C98(void *a0) {
    D_801865A8[*(u16 *)((s32)a0 + 0x2)](a0);
}
