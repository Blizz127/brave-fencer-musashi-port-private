/* SC02.CD FILE_031 / ov_SC02_031 retail span [801701C8,80170240).
 * Offset 0x48070 at overlay base 80128158. SHA256(span)=485604e7b70fd9c92e481de6f91aa3f90a39bdaa6e25fc35e41344cfdabd7159.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801701c8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801701C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_8012A568(void (*a0)(void));

void func_801701C8(u8 * a0)
{
    s16 *p;
    s32 r;
    r = func_80012B04(((s16 **)a0)[8][9], *(s16 *)&D_8011F738, 4);
    if ((s16)r == 0) {
        func_80171928(a0);
    }
    p = ((s16 **)a0)[8];
    ((u16 *)p)[9] = (((u16 *)p)[9] + r) & 0xFFF;
}
