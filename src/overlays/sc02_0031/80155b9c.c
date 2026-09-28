/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155B9C,80155C0C).
 * Offset 0x2DA44 at overlay base 80128158. SHA256(span)=9c8a9cde8c462b98ed65007b70456c551259d06cdfc4e02f6cfaa4021f5f6b90.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155b9c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80155B9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 a0);
extern s32 D_800D4DB4;

void func_80155B9C(s32 a0) {
    *(s32 *)(a0 + 0x44) |= 2;
    func_80148038(a0, 0x30000);
    func_80147460(a0);
    if (*(s32 *)(a0 + 0x34) >= 0) {
        func_80154274((s32 *)a0, (s32)&D_800D4DB4);
        func_80146CA0((void *)a0);
        func_80147324(0x447);
    }
}
