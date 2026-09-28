/* SC02 resident retail span [8016DA30,8016DA7C). Offset 0x458D8 at base 80128158.
 * SHA256(span)=d49e945414dd49550a097c104fb89955ba9e8ca6fd9125073cb2202904e2788b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018167C->D_80187F6C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016DA30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016DBD8(u8 *a0);
extern void (*D_80187F6C[])(int);
extern void func_8012A568(void (*a0)(void));

void func_8016DA30(int param_1)
{
    ((void (*)(void))func_8016DBD8)();
    D_80187F6C[*(unsigned short *)(param_1 + 2)](param_1);
}
