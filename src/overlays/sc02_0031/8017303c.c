/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017303C,80173078).
 * Offset 0x4AEE4 at overlay base 80128158. SHA256(span)=b1eeaa3c642113e4c323b806460caac246f7540e501c20b7587ca8bc3bc42b89.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017303c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017303C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80174684(void *);
extern s32 func_80173078();
extern s32 D_80127508;
extern s16 D_80126B30;

void func_8017303C(void * a0)
{
    D_80127508 = a0;
    D_80126B30 = 1;
    func_80174684((void *)func_80173078);
}
