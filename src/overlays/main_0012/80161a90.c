/* Overlay range [80161A90,80161B18) from MAIN.CD member 0012.
 * SHA256(span)=6447d02f5b4ebe5a4a0a33455f61433fa69ffeb0996a2502f8d32e3e8a6d1eb0.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80161A90 - 34 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_8014AC10();

void func_80161A90(s32 a0)
{
    extern u8 D_80078E78[];
    extern u8 D_80078EC0;
    u8 *p = D_80078E78;
    s32 t;
    if (*(s16 *)(a0 + 0x1C8) == 0) {
        t = 0;
    } else {
        t = ((D_80078EC0 & 0x7F) == 6);
    }
    if (t != 0) {
        __asm__ __volatile__("" ::: "memory");
        *(u16 *)(a0 + 0x1C8) -= 1;
        __asm__("" : "=r"(p) : "0"(p));
    }
    if ((p[0x48] & 0x7F) == 6) {
        if (*(s16 *)(a0 + 0x1C8) == 0) {
            func_8014AC10(0x3B);
        }
    }
}
