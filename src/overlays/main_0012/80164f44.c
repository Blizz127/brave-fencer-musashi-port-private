/* Overlay range [80164F44,80165024) from MAIN.CD member 0012.
 * SHA256(span)=f3217cdd0e7fa247bf06b76ea7d1849f8c7795c5b74cce533efa0ea32351160a.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80164F44 - 56 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80165124(void *a0);
extern s32 func_80165140(s32 a0);
extern void func_801651B8(void *a0);

void func_80164F44(void *arg0) {
    s32 iVar4;
    s16 sVar2;
    s16 sVar1;
    s16 sVar3;
    *(s16 *)((u8 *)arg0 + 0x62) = *(u16 *)((u8 *)arg0 + 0x62) + 4;
    iVar4 = *(u16 *)((u8 *)arg0 + 0x60) + 0x40;
    *(s16 *)((u8 *)arg0 + 0x60) = iVar4;
    sVar2 = *(u16 *)((u8 *)arg0 + 0x2E) - iVar4;
    *(s16 *)((u8 *)arg0 + 0x2E) = sVar2;
    *(s16 *)((u8 *)arg0 + 0x2C) = sVar2;
    if (sVar2 < 0x1000) {
        *(s16 *)((u8 *)arg0 + 0x2E) = 0x1000;
        *(s16 *)((u8 *)arg0 + 0x2C) = 0x1000;
        *(s16 *)((u8 *)arg0 + 0x60) = 0x80;
        func_80146E90((s32 *)arg0, 0xE);
        func_80146CA0(arg0);
    }
    func_80165124(arg0);
    sVar3 = 2;
    if (*(s16 *)((u8 *)arg0 + 0x2C) < 0x2800) {
        sVar1 = *(u16 *)((u8 *)arg0 + 0x66) + 1;
    } else {
        sVar3 = 3;
        sVar1 = *(u16 *)((u8 *)arg0 + 0x66) + 1;
    }
    *(s16 *)((u8 *)arg0 + 0x66) = sVar1;
    if (sVar1 == sVar3) {
        func_80165140((s32)arg0);
        *(s16 *)((u8 *)arg0 + 0x66) = 0;
    }
    func_801651B8(arg0);
}
