/* SC02.CD FILE_031 / ov_SC02_031 retail span [80153150,801531BC).
 * Offset 0x2AFF8 at overlay base 80128158. SHA256(span)=28fd7c08f3b6b2a5a13835e6048a1283a4087af7d184f1936c6e1c052e2019d6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80153150.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153150 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S80153150 {
    u8 pad0[0x60];
    s16 f60;   /* 0x60 */
    s16 f62;   /* 0x62 */
    u16 f64;   /* 0x64 */
    u8 padr[0x78];
    u8 fDE;    /* 0xDE */
};
extern void func_80149020(s32 *a0);
extern void func_801470B4(s32 a0);
extern void func_8015369C(s32 a0);
extern void func_80146CA0(void *a0);

void func_80153150(struct S80153150 *a0) {
    s16 nv;
    func_80149020((s32 *)a0);
    nv = (s16)(a0->f64 - 0x100);
    a0->f64 = nv;
    a0->f62 = nv;
    a0->f60 = nv;
    if (nv <= 0) {
        a0->fDE = 0x10;
        func_801470B4((s32)a0);
        func_8015369C((s32)a0);
        func_80146CA0(a0);
    }
}
