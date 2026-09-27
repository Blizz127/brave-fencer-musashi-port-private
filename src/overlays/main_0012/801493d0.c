/* Overlay range [801493D0,8014942C) from MAIN.CD member 0012.
 * SHA256(span)=7dcaaf9f4d91fd0675ee48a3d253e14fed74f3b64f29cbf13632d8ccaebd82b6.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801493D0 - 23 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_80015954(s32 a0, s32 a1);

void func_801493D0(s32 param_1, s32 param_2, s32 param_3)
{
  u8 buf1[8];
  u8 *new_var;
  u8 buf2[8];
  ((void (*)(s32, u8 *)) func_80015978)(param_2, buf1);
  new_var = buf2;
  ((void (*)(s32, u8 *, u8 *)) func_8012F14C)((*((s32 *) (param_1 + 0x20))) + 0x34, buf1, new_var);
  new_var++;
  new_var--;
  ((void (*)(u8 *, s32)) func_80015954)(buf2, param_3);
}
