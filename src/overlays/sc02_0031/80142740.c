/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142740,80142778).
 * Offset 0x1A5E8 at overlay base 80128158. SHA256(span)=b2881956db37839631c48612d4834d823f6955e9ac9c55461c5c4b64698456b5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80142740.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80142740 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012AD50(void *a0);

void func_80142740(int param_1)
{
    if (((int (*)(void))func_8012BEE8)() != 0) {
        ((void (*)(int))func_8012AD50)(param_1);
    }
}
