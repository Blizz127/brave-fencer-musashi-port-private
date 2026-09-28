/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174650,80174674).
 * Offset 0x4C4F8 at overlay base 80128158. SHA256(span)=8cea767259d5bb1349fed52df6f905adb72b998cb45cce63eb7470bc527357d6.
 * STOP pc=80174650 (func_80174650), CPU_BOUNDARY/REFUSED, ra=80172700.
 * Callee from burned func_801726D0 (jal 0C05D194).
 * Donor shape: Druthulu shared/ov/func_80174650.h (D_801150F8=0; D_801270BC|=1).
 * NOT in parked PAC0 hole 8014E934…80153C8C; later SC02 text near jr_8017AE2C / shared OV body.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174650 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801270BC;
extern s32 D_801150F8;

s32 func_80174650(s32 _arg0)
{
        D_801270BC = D_801270BC | 1;
        D_801150F8 = 0;
    }
