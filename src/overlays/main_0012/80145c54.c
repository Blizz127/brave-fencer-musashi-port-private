/* Overlay range [80145C54,80145CEC) from MAIN.CD member 0012.
 * SHA256(span)=33df775a473edcbd3f2feda0f8359bf32bd7198724e9702f1327bc65e09df524.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80145C54 - 38 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_800291B4(s32 arg);
extern void func_800291A0(s32, s32);

void func_80145C54(void) {
    register s32 a1 __asm__("$5");
    register s32 v1 __asm__("$3");
    s32 s0;
    a1 = func_800291B4(0x4A) & 0xFF;
    if (a1 >= 0x20) {
        v1 = a1 + 1;
        a1 = v1;
        if ((v1 & 0xF) == 0) {
            a1 = (u32)v1 >> 4;
        }
        s0 = a1 & 0xFF;
        func_800291A0(0x4A, s0);
        func_800291A0(0x50, s0);
    }
    a1 = func_800291B4(0x4D) & 0xFF;
    if (a1 >= 0x20) {
        v1 = a1 + 1;
        a1 = v1;
        if ((v1 & 0xF) == 0) {
            a1 = (u32)v1 >> 4;
        }
        func_800291A0(0x4D, a1 & 0xFF);
    }
}
