/* SC02.CD FILE_031 / ov_SC02_031 retail span [801736B0,801736FC).
 * Offset 0x4B558 at overlay base 80128158. SHA256(span)=5bc77525d4006cbbcbe5cfb8b968f2a0c25c0209cc6b0f6117df2f4f4e8658de.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801736b0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801736B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_8014C118(void *a0, s32 a1, s32 a2);
extern void func_80174684(void *);
extern s32 func_801736FC();
extern s32 D_80126B58;
extern s32 D_80127508;

void func_801736B0(s32 a0, s32 a1) {
    D_80127508 = func_8014C118(&D_80126B58, a0, (s16)a1);
    func_80174684(func_801736FC);
}
