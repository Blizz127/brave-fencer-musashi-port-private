/* Overlay range [80149450,801494CC) from MAIN.CD member 0012.
 * SHA256(span)=1c18dd186e20628c2bdcd8cc5023a3b49bf38ce2c5122518d59c872047814648.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80149450 - 31 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_8012F038(int param_1, short *param_2, short *param_3);

void func_80149450(s32 a0, s16 *a1) {
    s16 *s0 = a1;
    s16 sp10[3];
    s16 sp18[3];
    sp18[0] = *(u16 *)((char *)s0 + 0x2);
    sp18[1] = *(u16 *)((char *)s0 + 0x6);
    sp18[2] = *(u16 *)((char *)s0 + 0xA);
    ((void (*)(s32, s32, s32))func_8012F038)(*(s32 *)(a0 + 0x20) + 0x34, (s32)sp18, (s32)sp10);
    *(s16 *)((char *)s0 + 0x2) = *(u16 *)((char *)sp10 + 0x0);
    *(s16 *)((char *)s0 + 0x6) = *(u16 *)((char *)sp10 + 0x2);
    *(s16 *)((char *)s0 + 0xA) = *(u16 *)((char *)sp10 + 0x4);
}
