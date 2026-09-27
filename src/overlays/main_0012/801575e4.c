/* Overlay range [801575E4,801576A8) from MAIN.CD member 0012.
 * SHA256(span)=79b9bab8889a7f24ce10a106b00c51ce2cd5d4eb9934baa1bc477fd161f5c8c3.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801575E4 - 49 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80156648(s32 *a0);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8014B768(s32 a0, s32 a1);
extern void func_80147300(u16 arg0);
extern void func_80146CA0(void *a0);
extern u8 D_800D4F14[];
extern s32 D_8011F730;

void func_801575E4(void *a0) {
    s32 v;
    func_80154A74((s32)a0, 0x15);
    v = *(u8 *)((u8 *)a0 + 0x1AB) ^ 1;
    *(u8 *)((u8 *)a0 + 0x1AB) = v;
    if (v != 0) {
        *(u8 *)((u8 *)a0 + 0x1AA) = 0xA;
    } else {
        *(u8 *)((u8 *)a0 + 0x1AA) = 0xB;
    }
    func_80154274((s32 *)a0, (s32)D_800D4F14);
    func_80147324(0x455);
    func_80146E90((s32 *)a0, 0);
    func_80156648((s32 *)a0);
    func_80146994(0x5, (s32)a0, 0, 0);
    func_8014B768((s32)a0, 0x333);
    func_80147300(0x5F3);
    D_8011F730 |= 4;
    func_80146CA0(a0);
}
