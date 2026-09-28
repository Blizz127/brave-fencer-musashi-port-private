/* SC02 resident retail span [8015FCC8,8015FD74). Offset 0x37B70 at base 80128158.
 * SHA256(span)=a6ee56a55c177886865c8fe2beb570e6322216183bd2a35c240356c95d1b8ac1.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015FCC8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_800AE6B0;
extern void (*D_8018730C[])(void *);
extern void func_8016007C(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void func_8014BFF4(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);

void func_8015FCC8(void *param_1) {
    if ((D_800AE6B0 & 0x80FFFFFF) != 0) {
        ((void (*)(void))func_8016007C)();
        D_8018730C[*(u16 *)param_1](param_1);
        ((void (*)(void *, s32))func_80147078)(param_1, 0);
        func_80159B70(param_1);
    } else {
        *(u8 *)((s32)param_1 + 0x197) = 0;
        *(u8 *)((s32)param_1 + 0xBE) = 0;
        *(u8 *)((s32)param_1 + 0xBF) = 0;
        *(u8 *)((s32)param_1 + 0x1A0) = (u8)*(s32 *)((s32)param_1 + 0x184);
        ((s32 (*)(void *, s32))func_8014BFF4)(param_1, 1);
        func_80146CA0(param_1);
    }
}
