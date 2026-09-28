/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173460,801734BC).
 * Offset 0x4B308 at overlay base 80128158. SHA256(span)=d05d1dfe7ebc34358953f46e1ebc87fcf88bbb9418216055ea2bca33059436d1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173460.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80173460 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S80126B38 { s32 a; s32 b; } __attribute__((packed));
extern void func_8012A568(void (*a0)(void));
extern void func_801734BC(s32 a0, s32 a1);
extern struct S80126B38 D_80126B38;
extern s16 D_80126B3E;

void func_80173460(s32 a0, s32 a1) {
    func_801734BC(a0, a1);
    D_80126B38 = *(struct S80126B38 *)a1;
    D_80126B3E = 1;
}
