/* SC02.CD FILE_031 / ov_SC02_031 retail span [80181224,8018124C).
 * Offset 0x590CC at overlay base 80128158. SHA256(span)=e8ce7cafc534972c041753909eca18d20fa988f686c9674d7d3cceffbcdb05dc.
 * STOP pc=80181224 (func_80181224), CPU_BOUNDARY/REFUSED, ra=80180dc4.
 * Callee from burned func_80180DB0 (jal 0C060489).
 * Donor shape: Druthulu ov_SC02_031_jr_8017AE2C func_80181224 (func_8016EE40(&D_80188DA4, 0x1000000)).
 * NOT in parked PAC0 hole 8014E934…80153C8C; later SC02 text in jr_8017AE2C.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80181224 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

/* m2c compat (vendor/bfm-decomp/include/common.h). */
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))

extern void func_8012A568(void (*a0)(void));
extern void func_8016EE40(s32 a0, s32 a1, s32 a2);
extern M2C_UNK D_80188DA4;

void func_80181224(void) {
    ((void (*)(void *, s32))func_8016EE40)(&D_80188DA4, 0x1000000);
}
