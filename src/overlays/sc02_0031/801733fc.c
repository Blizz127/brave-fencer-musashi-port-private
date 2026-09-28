/* SC02.CD FILE_031 / ov_SC02_031 retail span [801733FC,80173460).
 * Offset 0x4B2A4 at overlay base 80128158. SHA256(span)=c35096dc96be6026f821fcfa787d5c4d479494c51d4782ec7797a9956608b65b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801733fc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801733FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S80126B38 { s32 a; s32 b; } __attribute__((packed));
extern void func_8012A568(void (*a0)(void));
extern void func_801734BC(s32 a0, s32 a1);

void func_801733FC(s32 a0, s32 a1) {
    extern struct S80126B38 D_80126B38;
    extern s16 D_80126B3E;
    extern s16 D_80126B40;
    func_801734BC(a0, a1);
    D_80126B38 = *(struct S80126B38 *)a1;
    D_80126B3E = 1;
    D_80126B40 = 1;
}
