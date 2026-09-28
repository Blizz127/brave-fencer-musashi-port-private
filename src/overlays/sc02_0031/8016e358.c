/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E358,8016E3CC).
 * Offset 0x46200 at overlay base 80128158. SHA256(span)=45a91c3fda19b7f557c3a1de639091b7e89932e9248537d2cf6b84f78efb114d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e358.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E358 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D22E4(s32 a0);
extern void func_8016E460(void *a0, void *a1);
extern void func_80146C3C();
extern void func_8012A568(void (*a0)(void));

void func_8016E358(void *a0) {
    s32 v0;
    v0 = *(s32*)((s32)a0 + 0x1C) - 1;
    *(s32*)((s32)a0 + 0x1C) = v0;
    if (v0 != 0) {
        func_800D22E4((s32)a0);
        *(s16*)((s32)a0 + 0x16) = *(u16*)((s32)a0 + 0x16) - 3;
        *(s32*)((s32)a0 + 0x30) = *(s32*)((s32)a0 + 0x30) - 0xE;
        func_8016E460(a0, (void*)((s32)a0 + 0x38));
    } else {
        ((void (*)(void *))func_80146C3C)(a0);
    }
}
