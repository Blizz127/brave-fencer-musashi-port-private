/* Overlay range [80155D70,80155E30) from MAIN.CD member 0012.
 * SHA256(span)=0acbe3f37a3df0977580619146cf3e6d3b96b13a150e4d3f2a69217d929f94f0.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80155D70 - 48 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u16 func_801487F4(s32 *a0);
extern void func_801599A4(void *a0);
extern void func_8015E880(s32 *a0);
extern void func_80159B3C(void *a0);
extern void func_8014CC28(s32 a0);
extern s32 func_8014F3E8(s32 a0);
extern void func_8015BDD0(s32 *a0);

void func_80155D70(s32 param_1)
{
    s32 iVar2;
    s32 iVar3;
    char buf[64];
    *(u32 *)(param_1 + 0x44) |= 2;
    if (*(u16 *)(param_1 + 0xB8) == 0x8000) {
        if ((((s32 (*)(void))func_801487F4)() & 0x80) != 0) {
            ((void (*)(s32))func_801599A4)(param_1);
            ((void (*)(s32))func_8015E880)(param_1);
        } else {
            ((void (*)(s32))func_801599A4)(param_1);
            ((void (*)(s32))func_80159B3C)(param_1);
        }
    } else {
        iVar2 = ((s32 (*)(s32))func_8014CC28)(param_1);
        iVar3 = ((s32 (*)(s32))func_8014F3E8)(param_1);
        if (iVar3 == 0 && iVar2 == 0) {
            ((void (*)(s32))func_801599A4)(param_1);
            ((void (*)(s32))func_8015BDD0)(param_1);
        }
    }
    (void)buf;
}
