/* SC02.CD FILE_031 / ov_SC02_031 retail span [80153410,80153490).
 * Offset 0x2B2B8 at overlay base 80128158. SHA256(span)=4e9b5b2aaef2d28b4c75d01bafefcf656a3452d943d26ba9aafd9c23094baa17.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80153410.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153410 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149020(s32 *a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_801470B4(s32 a0);
extern void func_8015369C(s32 a0);
extern void func_80146CA0(void *a0);

void func_80153410(s32 *a0) {
    func_80149020(a0);
    func_80148038((s32)a0, 0x18000);
    func_80147460((s32)a0);
    if (*(s16 *)((u8 *)a0 + 0xA) < 0x201) {
        u8 v1 = *(u8 *)((u8 *)a0 + 0xDE);
        *(u8 *)((u8 *)a0 + 0xDE) = v1 + 0xFF;
        if (v1 != 0) {
            return;
        }
    }
    func_801470B4((s32)a0);
    func_8015369C((s32)a0);
    func_80146CA0(a0);
}
