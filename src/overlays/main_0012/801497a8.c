/* Overlay range [801497A8,80149864) from MAIN.CD member 0012.
 * SHA256(span)=1630b703df402c56365905e67a3cea5e2241cebaeb0afbea6b00eec964dc878b.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801497A8 - 47 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_80078E78[];
extern u8 D_80078EC1;
extern s32 func_8014CB7C(void);
extern s32 func_8014C088(s32 a0, s32 a1);
extern u8 func_80165658(s32 a0, s32 a1);

s32 func_801497A8(s32 *a0) {
    u8 *s1 = D_80078E78;
    /* Zero-byte RC-7 "second set": reg_n_sets(s1)==2 fails update_equiv_regs'
       single-set gate -> no REG_EQUIV -> the address constant is NOT
       rematerialized at its lone use; it is held in a callee-saved reg ($s1)
       across the calls, as the target does. NOT a register pin (no $N). */
    __asm__("" : "=r"(s1) : "0"(s1));
    if (*(u16 *)a0 == 0x1A) goto ret0;
    if (func_8014CB7C() != 0) goto ret0;
    if (D_80078EC1 == 0xF) {
        if (func_8014C088((s32)a0, 0xA) != 0) goto ret0;
    }
    if (*(s32 *)((u8 *)a0 + 0x44) & 0x404) goto ret0;
    if (func_80165658((s32)a0, s1[0x49]) & 0x80) goto ret0;
    if (*(u16 *)((u8 *)a0 + 0xAC) & 0x20) return 1;
ret0:
    return 0;
}
