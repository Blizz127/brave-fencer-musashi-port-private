/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160FE0,80161034).
 * Offset 0x38E88 at overlay base 80128158. SHA256(span)=1ad0627ab36df6573858465d58627418f4cc430426cb9e8e6bdf6679c100168b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160fe0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160FE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149020(s32 *a0);
extern s32 func_801399F0(s32 a0);
extern void func_80139914(s32 a0);
extern void func_80146CA0(void *a0);

void func_80160FE0(s32 *a0) {
    s32 *s0 = a0;
    func_80149020(a0);
    if (func_801399F0(*(s32 *)((u8 *)s0 + 0x198)) != 0) {
        func_80139914(*(s32 *)((u8 *)s0 + 0x198));
        *(s32 *)((u8 *)s0 + 0x198) = 0;
        func_80146CA0(s0);
    }
}
