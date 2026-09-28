/* SC02.CD FILE_031 / ov_SC02_031 retail span [80137614,8013767C).
 * Offset 0xF4BC at overlay base 80128158. SHA256(span)=ef25364f7b72a5f475f6e8fc0e54889e7b3dcfa85df778425bb032deaff504ed.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80137614.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80137614 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_801399A8(void);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");

s32 aF80137614(s32 a0, s32 a1, s32 a2)
{
    s32 v1, s0;
    __asm__("" : "=r"(v1) : "0"(a1));
    s0 = func_801399A8();
    if (s0 != 0) {
        func_801377B4(a0, a2 & 0xD8, s0);
        *(s16 *)(s0 + 0x1C) = v1;
    }
    return s0;
}
