/* Overlay range [80145B24,80145BF8) from MAIN.CD member 0012.
 * SHA256(span)=8e6b43d6d8746bc27309c9ceb3cc4a60ee6d375dccfc29f2dbb360d5b9c63e09.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80145B24 - 53 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80029504(void);
extern s32 func_800291DC(s32);
extern void func_800291C8(s32, s32);
extern void func_80162120(void);
extern void func_80029124(s32, s32);
extern s32 func_80165A50(s32);
extern void func_80029514(s32);
extern u8 D_800AF630[];
extern u8 D_80078EC0;
extern s32 D_80126B58;

void func_80145B24(void)
{
    s32 iVar1;
    s32 uVar2;
    register u8 *p __asm__("$17");
    p = &D_800AF630;
    iVar1 = func_80029504();
    uVar2 = func_800291DC(8);
    if ((uVar2 & 0x8000) != 0) {
        func_800291C8(8, 0);
        func_80162120();
    }
    if (iVar1 >= 0x6A4) {
        func_80029124(0x1A, 0);
        func_80029124(0x8E, 0);
        func_80029124(0x143, 0);
        if ((D_80078EC0 & 0x7F) != 0) {
            D_80078EC0 = 1;
        }
        func_80165A50((s32)&D_80126B58);
        func_80029514(0x4B0);
    }
    *(s16 *)(p + 0xA3DA) = 0x3000;
}
