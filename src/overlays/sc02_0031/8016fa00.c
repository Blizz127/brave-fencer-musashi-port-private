/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FA00,8016FA44).
 * Offset 0x478A8 at overlay base 80128158. SHA256(span)=01f757a07326757868a65a5de2231d0e3f49f8a0d4b21bcf16c686d891b71164.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fa00.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FA00 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801719A4(int a0, int a1);
extern void func_80171B44(s32 *a0);
extern s32 func_80171990(u8 *a0);
extern void func_8016FA44(s32 a0);
extern void func_8012A568(void (*a0)(void));

void func_8016FA00(s32 a0) {
    func_801719A4(a0, 1);
    func_80171B44((s32 *)a0);
    func_80171990((u8 *)a0);
    func_8016FA44(a0);
}
