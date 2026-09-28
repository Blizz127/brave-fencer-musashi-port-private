/* SC02.CD FILE_031 / ov_SC02_031 retail span [80159B3C,80159B70).
 * Offset 0x319E4 at overlay base 80128158. SHA256(span)=8d0c06bb90e75f6cc634681ff84b42995f91b430adb989a6422b2173590fdad6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80159b3c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80159B3C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);

void func_80159B3C(void * a0)
{
    func_80147078(a0, 0);
    func_80159B70(a0);
}
