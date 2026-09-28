/* SC02.CD FILE_031 / ov_SC02_031 retail span [801516F0,8015173C).
 * Offset 0x29598 at overlay base 80128158. SHA256(span)=b37632c15ecb3f83ad6b59b424d0131850f7c9834639d01e1928b6fbcd55cfa0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801516f0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801516F0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014C8F0(s32 arg0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80151780(s32 a0);

void func_801516F0(s32 *a0) {
    func_8014C8F0((s32)a0);
    *((u8 *)a0 + 0xDE) = (u8)*(u16 *)a0;
    func_80147078(a0, 0x19);
    *(s16 *)((u8 *)a0 + 0x2) = 1;
    func_80151780((s32)a0);
}
