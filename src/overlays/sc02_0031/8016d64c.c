/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016D64C,8016D688).
 * Offset 0x454F4 at overlay base 80128158. SHA256(span)=d1fa464c77dbf4b8238b12222209a6433dc103a1a6052f7bdc60ca66ec91a8fc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016d64c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016D64C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern short func_8016CBC0(void);
extern void func_80146C3C();

void func_8016D64C(int param_1)
{
    if (func_8016CBC0() == 0) {
        ((void (*)(int))func_80146C3C)(param_1);
    }
    return;
}
