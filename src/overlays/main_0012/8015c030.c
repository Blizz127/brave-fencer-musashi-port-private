/* Overlay range [8015C030,8015C08C) from MAIN.CD member 0012.
 * SHA256(span)=f0aaa22cdf388e25ced7e01778f043ec3a353de79b43278db88fa632e5df7ecb.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8015C030 - 23 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80146CA0(void *a0);

void func_8015C030(s32 *a0, s32 a1)
{
    s32 t = *(s16 *)a1 << 7;
    *(s32 *)((s32)a0 + 0x238) = 0x80000;
    *(s32 *)((s32)a0 + 0x234) = t;
    *(s32 *)((s32)a0 + 0x23C) = *(s16 *)(a1 + 4) << 7;
    func_80154150((s32)a0, 0x11);
    func_801553A8(a0);
    func_80146CA0((void *)a0);
}
