/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015BE94,8015BEC4).
 * Offset 0x33D3C at overlay base 80128158. SHA256(span)=505f5faa6c942bb0acd20ff68f686ff6f90a9fb34fadf4d23899b43473efc673.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015be94.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015BE94 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80161124(void *a0);
extern void func_80146CA0(void *a0);

s32 func_8015BE94(s32 *a0)
{
        ((void (*)(s32 *))func_80161124)(a0);
        ((s32 (*)(s32))func_80146CA0)((s32)a0);
    }
