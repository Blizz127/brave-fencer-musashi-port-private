/* SC02.CD FILE_031 / ov_SC02_031 retail span [801726D0,80172710).
 * Offset 0x4A578 at overlay base 80128158. SHA256(span)=f6dd5958e70086a2db1d1f348602c2f3dc904a865bc89004f24b917132e82297.
 * STOP pc=801726d0 (func_801726D0), CPU_BOUNDARY/REFUSED, ra=8016ef98.
 * Callee from burned func_8016EF78 (jal 0C05C9B4; a0=&D_80126B58).
 * Donor shape: Druthulu shared/ov/func_801726D0.h (D_80127088=func_80172760; clear flags; jal func_80174650).
 * NOT in parked PAC0 hole 8014E934…80153C8C; later SC02 text near jr_8017AE2C / shared OV body.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801726D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80172760(s32 a0);
extern s32 func_80174650(s32);
extern void (*D_80127088)(void);
extern s32 D_801270BC;
extern s16 D_80126B0C;

void func_801726D0(void * _arg0)
{
    D_80127088 = func_80172760;
    D_801270BC = 0;
    D_80126B0C = 0;
    ((void (*)(void))func_80174650)();
}
