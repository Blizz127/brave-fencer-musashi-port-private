/* Overlay range [80161774,80161888) from MAIN.CD member 0012.
 * SHA256(span)=13417d0289afb9accfc5d551a247974f07cb37adf5d77383e421106274426440.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_8004CFEC(s16, s16);                        /* extern */
s32 func_8014A6C4(void *);                          /* static */
void func_8014C010(void *, s32);                         /* static */
void func_801599A4(void *);                            /* static */
void func_8015BF48(void *);                            /* static */
void func_8015F2F0(void *);                            /* static */
void func_80161D20(void *, u16);                       /* static */
extern s16 D_801152B0;
extern s16 D_801152B4;

s32 func_80161774(void *arg0, s32 arg1) {
    if (arg1 & 1) {
        func_8014C010((void *)1);
        func_80161D20(arg0, arg0->unk16E);
        return 1;
    }
    if (arg1 & 0x4000) {
        func_801599A4(arg0);
        func_8015BF48(arg0);
        func_8014C010(arg0, 1);
        func_80161D20(arg0, arg0->unk16E);
        return 2;
    }
    if (arg1 & 0x2000) {
        func_8014C010(arg0, 1);
        func_80161D20(arg0, arg0->unk16E);
        return 4;
    }
    if (arg1 & 0x8000) {
        if (arg0->unk16C == 0x15) {
            if (func_8014A6C4(arg0) != 0) {
                func_801599A4(arg0);
                func_8015F2F0(arg0);
                arg0->unk20->unk12 = func_8004CFEC(D_801152B0, D_801152B4);
                return 8;
            }
            goto block_10;
        }
        /* Duplicate return node #11. Try simplifying control flow for better match */
        return 0;
    }
block_10:
    return 0;
}
