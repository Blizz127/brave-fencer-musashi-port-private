/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015AD08,8015AD3C).
 * Offset 0x32BB0 at overlay base 80128158. SHA256(span)=eb56edfcb8ad2b606138461e208d465bb2c2f8d58d3264bb39fa06fe992ba824.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015ad08.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015AD08 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015AD3C(void *a0);

void func_8015AD08(void *arg0)
{
    func_80147078((s32 *)arg0, 2);
    func_8015AD3C(arg0);
}
