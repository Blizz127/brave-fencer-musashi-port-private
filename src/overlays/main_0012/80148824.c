/* Overlay range [80148824,801488A8) from MAIN.CD member 0012.
 * SHA256(span)=0191bf98db38650cf3a148bccf2d1274051a2fb2d62398ea07cf56d43646b58a.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80148824 - 33 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80047D3C(s32 a0);

s32 func_80148824(void *arg0)
{
    register u32 t __asm__("$2");
    register s32 hi __asm__("$3");
    register s32 lo __asm__("$2");
    register s32 chi __asm__("$5");
    register s32 clo __asm__("$4");
    t = *(u16 *)((u8 *)arg0 + 0xAE);
    hi = (t >> 8) - 0x80;
    chi = hi;
    __asm__ __volatile__("" : : "r"(chi));
    lo = (t & 0xFF) - 0x80;
    clo = lo;
    if (hi == 0) {
        if (lo < 0) {
            return (-clo) & 0xFF;
        }
        return clo & 0xFF;
    } else if (lo == 0) {
        if (hi < 0) {
            return (-chi) & 0xFF;
        }
        return chi & 0xFF;
    }
    hi = hi * hi;
    chi = lo * lo;
    return func_80047D3C(hi + chi) & 0xFF;
}
