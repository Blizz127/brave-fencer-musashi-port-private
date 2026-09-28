/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016EF78,8016EFA8).
 * Offset 0x46E20 at overlay base 80128158. SHA256(span)=4d566ca109d04e990eb5850cf9ad039e1d3760b26874531c6c708cc8b8c0dcd5.
 * STOP pc=8016ef78 (func_8016EF78), CPU_BOUNDARY/REFUSED, ra=8016ee50.
 * Callee from burned func_8016EE40 (jal 0C05BBDE).
 * Donor shape: Druthulu shared/ov/func_8016EF78.h (func_8016EFC8(a0) + func_801726D0(&D_80126B58)).
 * NOT in parked PAC0 hole 8014E934…80153C8C; later SC02 text near jr_8017AE2C / shared OV body.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016EF78 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8016EFC8();
extern void func_801726D0(void *a0);
extern s32 D_80126B58;
extern void func_8012A568(void (*a0)(void));

void func_8016EF78(s32 a0) {
    func_8016EFC8(a0);
    func_801726D0(&D_80126B58);
}
