/* SC02 resident retail span [801737E8,80173824). Offset 0x4B690 at base 80128158.
 * SHA256(span)=129adab47d13748cbafd6c7b7b422e60b86a1da7fa9f9ed1022fdc429a161c2a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181984->D_80188274.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801737E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_801737E8(void *a0) {

    extern void (*D_80188274[])(void);
    D_80188274[*(u8 *)((s32)a0 + 0x214)]();
}
