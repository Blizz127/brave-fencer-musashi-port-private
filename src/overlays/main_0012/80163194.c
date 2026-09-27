/* Overlay range [80163194,80163234) from MAIN.CD member 0012.
 * SHA256(span)=f9bb7d641582330dd9fbf0a802545daa78a4f3ddb537226233b93d358f55a99c.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80163194 - 40 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void func_80162F60(s32 arg0, s32 arg1);
extern void func_80162F80(s32 arg0, s32 arg1);
extern void func_80162FA0(s32 arg0, s32 arg1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern void func_80146D30(s32 a0);

void func_80163194(s32 a0, s32 a1, s32 a2, s32 a3, s32 arg4) {
    s32 pad[4];
    s32 out[3];
    (void)pad;
    func_80162F60(a0, a1);
    func_80162F80(a0, a2);
    func_80162FA0(a0, a3);
    func_800484EC(arg4, a0 + 0x24, (s32)out);
    aD_80127090 = out[0];
    aD_80127094 = out[1];
    aD_80127098 = out[2];
    func_80146D30(a0);
}
