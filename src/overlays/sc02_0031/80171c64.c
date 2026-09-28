/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171C64,80171CC4).
 * Offset 0x49B0C at overlay base 80128158. SHA256(span)=77cb302c17b62939a06ba55cc0e631d23151f012cc6fa6bc7f026f287c0a88c1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171c64.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171C64 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80171EC8(s32 a0);
extern void func_80146D90(s32 a0);

s32 func_80171C64(s32 param_1, s32 param_2)
{
    register s32 s __asm__("$17") = param_1;
    register s32 d __asm__("$16") = param_2;
    u8 v;
    ((void (*)(void))func_80171EC8)();
    v = *(u8 *)(s + 0x20C);
    *(u8 *)(s + 0x20C) = v + 1;
    if ((v & 0xFF) == (d & 0xFF)) {
        func_80146D90(s);
        return 1;
    }
    return 0;
}
