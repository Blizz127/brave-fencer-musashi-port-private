/* SC02.CD FILE_031 / ov_SC02_031 retail span [801705C0,801705F8).
 * Offset 0x48468 at overlay base 80128158. SHA256(span)=bd0b0c2514b7bcbd7116753de98446c34e5829f0c0351c606456a64be94cd35d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801705c0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801705C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void *D_8011F738;
extern void func_80171928(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_801705C0(u8 * a0)
{
    ((void (*)(void))D_8011F738)();
    ((void (*)(s32))func_80171928)(a0);
}
