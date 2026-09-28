/* SC02.CD FILE_031 / ov_SC02_031 retail span [801746A4,801746DC).
 * Offset 0x4C54C at overlay base 80128158. SHA256(span)=21766d9d2128dd062ba7133cbc2b71a2a4b39e3c1f9cf61f9dbaec6a7632cb2e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801746a4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801746A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80172760(s32 a0);
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_80174684(void *);

void func_801746A4(void)
{
    ((void (*)(void *, int))func_8016EDEC)(func_80172710, 0x1000000);
    func_80174684(func_80172760);
}
