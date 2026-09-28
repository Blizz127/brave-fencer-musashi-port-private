/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017248C,801724EC).
 * Offset 0x4A334 at overlay base 80128158. SHA256(span)=cb72ecf8427459d7fc59739af2beb9b1b34a99e60d65175cdf3bbed79be33082.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017248c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017248C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_801724EC(s32 a0);

s32 func_8017248C(s32 arg0, s32 arg1)
{
    if (((s32 (*)(void*, void*))func_801724EC)(arg0, arg1) != 0) {
        *(u16*)((u8*)arg0 + 6) = *(u16*)((u8*)arg1 + 0);
        *(u16*)((u8*)arg0 + 0xA) = *(u16*)((u8*)arg1 + 2);
        *(u16*)((u8*)arg0 + 0xE) = *(u16*)((u8*)arg1 + 4);
        return 1;
    }
    return 0;
}
