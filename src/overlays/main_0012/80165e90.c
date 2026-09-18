/* Overlay range [80165E90,80165FA4) from MAIN.CD member 0012.
 * SHA256(span)=a333e8cb00dfd8aa5c4395585cb5d118b4e81b4ec8c1666c334844ceec9cf00a.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80165E90 - 69 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_801484B0(s32 a0, s32 a1);
extern s32 func_80165FA4(s32 a0, s32 a1, s32 a2);
extern s32 func_80167DBC(s32 a0, s32 a1, s32 a2);
extern void func_80148534(s32 a0, s32 a1);
extern s32 func_80167AE0();
extern s32 D_80126B9C;
extern s32 D_80126B58;
extern s32 *D_80126B78;

void func_80165E90(void) {
    s32 s1 = (s32)&D_80126B58;
    s32 buf1[2];
    s32 buf2[2];
    s32 v1;
    if ((D_80126B9C & 0x10000400) == 0x10000000) {
        v1 = (s32)D_80126B78;
        if (*(s32 *)(v1 + 0x4) >= 0) {
            if (*(s32 *)(v1 + 0x20) != 0) {
                func_801484B0((s32)buf1, (s32)buf2);
                func_80165FA4(s1, (s32)buf1, (s32)buf2);
                func_80167DBC(s1, (s32)buf1, (s32)buf2);
            }
        }
    }
    if ((*(s32 *)(s1 + 0x44) & 0x20020400) == 0x20000000) {
        v1 = *(s32 *)(s1 + 0x20);
        if (*(s32 *)(v1 + 0x4) >= 0) {
            if (*(s32 *)(v1 + 0x20) != 0) {
                func_80148534((s32)buf1, (s32)buf2);
                func_80165FA4(s1, (s32)buf1, (s32)buf2);
                func_80167AE0(s1, (s32)buf1, (s32)buf2);
            }
        }
    }
}
