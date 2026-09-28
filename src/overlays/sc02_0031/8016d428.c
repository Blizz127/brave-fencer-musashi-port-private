/* SC02 resident retail span [8016D428,8016D464). Offset 0x452D0 at base 80128158.
 * SHA256(span)=24604c3c7091ee58299965221a6b46adf7fa61ba0011d5908132675aa4a53aae.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181614->D_80187F04.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016D428 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187F04[])(void);
extern void func_8012A568(void (*a0)(void));

void func_8016D428(void *a0) {
    D_80187F04[*(u16 *)((s32)a0 + 0x2)]();
}
