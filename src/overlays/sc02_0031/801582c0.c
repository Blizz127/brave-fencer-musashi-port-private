/* SC02.CD FILE_031 / ov_SC02_031 retail span [801582C0,80158344).
 * Offset 0x30168 at overlay base 80128158. SHA256(span)=e4e773f03bc00be7f7576b624a1e5bb7524fc3e56034618a0346d1ce9925a7fc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801582c0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801582C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800D52A8[];
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801585A4(s32 *a0);
extern void func_8016706C(s32 a0);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);

void func_801582C0(void *a0) {
    s32 s0 = (s32)a0;
    *(s32 *)(s0 + 0x44) = *(s32 *)(s0 + 0x44) | 2;
    *(s8 *)(s0 + 0x1AA) = 0x10;
    func_80154274((s32 *)s0, (s32)D_800D52A8);
    func_80154A74(s0, 0x15);
    func_801585A4((s32 *)s0);
    func_8016706C(5);
    func_80146994(4, s0, 8, 0);
    func_80147324(0x446);
    func_80146CA0((void *)s0);
}
