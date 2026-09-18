/* Overlay range [80177F84,80178004) from MAIN.CD member 0012.
 * SHA256(span)=bed8f3b04b51ef580ed5ea79d423f6ed955c6b21d88e5e6043358e88815c0ce0.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80177F84 - 32 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */


void func_80177F84(s32 param_1, s32 param_2) {
    u16 uVar4;
    s16 iVar3;
    register u8 *pcVar2 __asm__("$6");
    u32 uVar1;
    register s32 c5 __asm__("$10");
    register s32 cmask __asm__("$9");
    uVar4 = 0x100;
    iVar3 = 0;
    c5 = 5;
    cmask = -257;
    pcVar2 = (u8 *)(param_1 + 0xc);
    do {
        register u32 src __asm__("$2");
        register u32 byteval __asm__("$3");
        register u32 testval __asm__("$4");
        src = (param_2 >> 0x10) & 0xf;
        __asm__ __volatile__("" : : "r"(src));
        byteval = src;
        __asm__ __volatile__("" : "=r"(byteval) : "0"(byteval));
        testval = src;
        __asm__ __volatile__("" : : "r"(byteval), "r"(testval));
        param_2 = param_2 << 4;
        if ((iVar3 == c5) || (testval != 0)) {
            uVar4 = 0;
        }
        pcVar2 += 0x14;
        iVar3 += 1;
        {
            register s32 r __asm__("$4");
            r = *(u16 *)(pcVar2 - 2);
            pcVar2[0] = (u8)(byteval * 8 + 8);
            *(u16 *)(pcVar2 - 2) = uVar4 | (r & cmask);
        }
    } while (iVar3 < 5);
}
