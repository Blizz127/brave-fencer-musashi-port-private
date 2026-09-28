/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157EA4,80157F64).
 * Offset 0x2FD4C at overlay base 80128158. SHA256(span)=d003359fe39d381abf1d959f45ab41c716247a8b24504af6f3aede46562488e5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157ea4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157EA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80157F64(s32 *a0);
extern int func_80155FF8(int arg, int a1);
extern s32 func_80156600(void *a0);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_80157EA4(void *a0) {
    s32 *v1;
    *(s32 *)((u8 *)a0 + 0x44) = *(s32 *)((u8 *)a0 + 0x44) | 2;
    if (*(u16 *)((u8 *)a0 + 0xB8) == 0x8000) {
        func_801599A4(a0);
        func_80159B3C(a0);
        return;
    }
    if (func_80157F64((s32 *)a0) != 0) {
        return;
    }
    func_80155FF8((int)a0, *(u8 *)((u8 *)a0 + 0x1AA));
    v1 = (s32 *)func_80156600(a0);
    if (v1 == 0) {
        return;
    }
    if (*(s16 *)((u8 *)a0 + 0x244) != 0) {
        return;
    }
    *(s16 *)((u8 *)a0 + 0x244) = 1;
    func_80146A6C(0x54, a0, *(s16 *)v1, *(s16 *)((u8 *)v1 + 2), *(s16 *)((u8 *)v1 + 4), 0, 0);
}
