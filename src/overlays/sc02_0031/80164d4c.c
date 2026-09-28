/* SC02.CD FILE_031 / ov_SC02_031 retail span [80164D4C,80164DB0).
 * Offset 0x3CBF4 at overlay base 80128158. SHA256(span)=9116e0981747fa1cc2400057e58d16dd2e29124883b697de43b9ff32c80f37e6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80164d4c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164D4C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80164E40(void);
extern void func_80146CA0(void *a0);

void func_80164D4C(void *arg0) {
    register s32 a __asm__("$16");
    register s32 iVar3 __asm__("$17");
    s16 sVar1;
    a = (s32)arg0;
    iVar3 = *(s32 *)(a + 0x20);
    if (((s32 (*)(void))func_80164E40)() != 0) {
        func_80146CA0((void *)a);
    } else {
        sVar1 = *(s16 *)(iVar3 + 0x1a) + 0x100;
        *(s16 *)(iVar3 + 0x1a) = sVar1;
        *(s16 *)(iVar3 + 0x18) = sVar1;
    }
}
