/* Overlay range [801508F8,8015094C) from MAIN.CD member 0012.
 * SHA256(span)=5ebc2ed3db8c594218111f3d6bc1fda68831539b10ffedc7694f33d010a04410.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801508F8 - 21 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_8015094C(s32 a0);

short func_801508F8(s32 a0)
{
  if ((*((u8 *) (a0 + 0x1BF))) != 0)
  {
    if ((*((u16 *) a0)) != 0x1A)
    {
      while (func_8015094C(a0) != 0)
      {
        ;
      }
    }
  }
}
