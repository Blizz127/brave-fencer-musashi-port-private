/* SC02.CD FILE_031 / ov_SC02_031 retail span [801391F0,80139220).
 * Offset 0x11098 at overlay base 80128158. SHA256(span)=bbc8f27ddf1bb0d4318c938a9fae8597e34fdcd7db62077d89b5597a5aa71d93.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801391f0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801391F0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80139634(void *);
extern void func_80139DC8(void);

void func_801391F0(void *a0) {
    *(s16 *)((s32)a0 + 0x12) = 0;
    *(s16 *)((s32)a0 + 0x14) = 0;
    *(s16 *)((s32)a0 + 0x16) = 0;
    func_80139634(a0);
    func_80139DC8();
}
