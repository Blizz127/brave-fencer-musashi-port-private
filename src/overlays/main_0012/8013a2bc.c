/* Overlay range [8013A2BC,8013A378) from MAIN.CD member 0012.
 * SHA256(span)=f81c78471f49131a9c886c48dc7bd3abc9dab45f47e741c62d67d61f63c5ecff.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8013A2BC - 47 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 D_80127524;
extern s32 D_80127528;
extern void func_80138C30(void *a0);

void func_8013A2BC(s32 a0) {
    s32 s0 = a0;
    s32 *v1;
    s32 *p;
    s32 v0;
    v1 = *(s32 **)(s0 + 0x40);
    if (v1 == 0 || *(u16 *)(s0 + 0x18) == 0 || *(s16 *)v1 == 4) {
        p = &D_80127524;
        if (*p == s0) {
            v0 = D_80127528;
            D_80127528 = 0;
            *p = v0;
            if (v0 != 0) {
                *(s16 *)(D_80127524 + 0x1A) = 1;
                __asm__ __volatile__("" : : : "memory");
                ((void (*)(s32))func_80138C30)(*p);
            }
        }
        if ((*(s32 *)(s0 + 8) & 0x8000) == 0) {
            *(s16 *)(s0 + 4) = 0xD;
        } else {
            *(s16 *)(s0 + 4) = 0xE;
        }
    }
}
