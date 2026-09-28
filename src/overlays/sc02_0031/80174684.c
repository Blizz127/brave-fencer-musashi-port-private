/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174684,801746A4).
 * Offset 0x4C52C at overlay base 80128158. SHA256(span)=2961562b4080a5b0a7e21e106247a305aeed2831b2f163a88f45492a8f0725f6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174684.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174684 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u8 D_80126D6C;
extern void (*D_80127088)(void);
extern s32 D_801270BC;

void func_80174684(void* a0)
{
    D_80126D6C = 0;
    (*(void * *)&D_80127088) = a0;
    D_801270BC = 0;
}
