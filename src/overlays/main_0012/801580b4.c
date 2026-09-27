/* Overlay range [801580B4,801581AC) from MAIN.CD member 0012.
 * SHA256(span)=b8663fcb562445a6f0e2a40d82dd5f4fc9800cc5de3fed65fae0c183f1338c01.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801580B4 - 62 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_800D524C[];
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_80147AD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_801473EC(s32 *a0);
extern void func_80161418(void *a0);
extern void func_80156648(s32 *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);
extern int func_80155FF8(int arg, int a1);

void func_801580B4(s32 a0) {
    s32 reserved[4];
    (void)reserved;
    *(s32 *)(a0 + 0x44) |= 2;
    if ((*(u16 *)(a0 + 0xB8) & 0x4000) != 0) {
        func_801477E8((s32 *)a0, 0xFFF40000);
        *(s32 *)(a0 + 0x234) += 1;
    }
    if (*(s32 *)(a0 + 0x234) != 0) {
        func_80148038(a0, 0x10000);
        func_80147460(a0);
    }
    func_80147AD4(a0, 0, 0, 0);
    func_801473EC((s32 *)a0);
    {
        register s32 ret __asm__("$2");
        func_80161418((void *)a0);
        __asm__ __volatile__("" : "=r"(ret));
        if (ret != 0) {
            return;
        }
    }
    if (*(u16 *)(a0 + 0xB8) == 0x8000) {
        func_80156648((s32 *)a0);
        *(s8 *)(a0 + 0x1AA) = 0xF;
        func_80154274((s32 *)a0, (s32)D_800D524C);
        func_80147324(0x455);
        func_80146CA0((void *)a0);
    } else {
        func_80155FF8(a0, *(u8 *)(a0 + 0x1AA));
    }
}
