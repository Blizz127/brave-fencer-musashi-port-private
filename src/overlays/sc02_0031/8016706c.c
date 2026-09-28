/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016706C,801670E4).
 * Offset 0x3EF14 at overlay base 80128158. SHA256(span)=18fc729174a54e8d10762126e3d3659fa4585811110d0a02f8c3cfc9a827a99d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016706c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016706C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80146C3C(void);

void func_8016706C(s32 param_1)
{
    extern s32 D_8011D030;
    unsigned short *puVar1;
    short iVar2;
    iVar2 = 0;
    puVar1 = ((unsigned short *)&D_8011D030);
    do {
        if ((unsigned int)*puVar1 == ((short)param_1)) {
            ((void(*)(unsigned short *))func_80146C3C)(puVar1);
        }
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 0x2c;
    } while (iVar2 < 0x1e);
}
