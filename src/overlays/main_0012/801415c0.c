/* Overlay range [801415C0,8014168C) from MAIN.CD member 0012.
 * SHA256(span)=6301d48d84a1a1ee6a47424522d6b169b5bb5c8132fbc84fc438b386aa374de9.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801415C0 - 51 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_800291B4(s32 arg);
extern void func_800291A0(s32, s32);
extern s32 func_800291DC(s32);
extern void func_800291C8(s32, s32);

void func_801415C0(s32 param_1, s32 param_2) {
    register s32 a __asm__("$16");  /* $s0: param_2 raw -> sext -> *2+0x14 */
    register s32 b __asm__("$17");  /* $s1: param_1 sext / *2+0x14 */
    register s32 c __asm__("$18");  /* $s2: param_2 sext + 0x2F   */
    register s32 d __asm__("$19");  /* $s3: param_1 sext + 0x2F   */
    register s32 e __asm__("$20");  /* $s4: 291B4(d)&0xFF / 291DC(b) */
    a = param_2;
    b = (s16)param_1;
    d = b + 0x2F;
    e = func_800291B4(d) & 0xFF;
    a = (s16)a;
    c = a + 0x2F;
    func_800291A0(d, func_800291B4(c) & 0xFF);
    func_800291A0(c, e);
    b = b * 2 + 0x14;
    e = func_800291DC(b);
    a = a * 2 + 0x14;
    func_800291C8(b, (s16)func_800291DC(a));
    func_800291C8(a, (s16)e);
}
