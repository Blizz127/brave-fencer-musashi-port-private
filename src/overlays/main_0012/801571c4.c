/* Overlay range [801571C4,801574DC) from MAIN.CD member 0012.
 * SHA256(span)=ab7319ae7a91b5c346dfba04e57779f5257c58ca7dc9da4cb3c06f100bb1b032.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80135004(s32, s32, void *);                    /* static */
s32 func_80135260(s32, s32, s32, void *);             /* static */
void func_8014C4AC(void *, s32, s32, void *, s32);        /* static */
s8 func_8014C918(void *, u8);                       /* static */
extern s32 *D_801202A0;

s32 func_801571C4(void *arg0, s32 arg1, u16 arg2, s32 arg3, void *arg4, void *arg5, void *arg6, void **arg7, void *arg8, s32 arg9, u16 arg10, s8 *arg11, s8 *arg12) {
    s32 sp30;
    u16 sp28;
    u16 sp20;
    s32 sp1F;
    s8 sp1E;                                        /* compiler-managed */
    s32 sp1B;
    s32 sp18;
    s32 temp_a1;
    s32 temp_s4;
    s32 var_s1;
    s32 var_s2;
    u16 temp_v1;
    u32 var_s3;
    void *temp_s0;

    var_s1 = 0;
    sp20 = arg2;
    sp28 = arg10;
    var_s3 = 0;
    if (func_80135004(1, arg3, arg4) != 0) {
        *arg11 = (s8) ((u16) arg4->unk6 >> 0xD);
        *arg12 = (s8) arg4->unk6;
        var_s1 = 2;
        arg6->unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        arg6->unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    }
    temp_s4 = arg1 & 0xFFFF;
    sp30 = arg2 & 0x8000;
    var_s2 = 0;
loop_3:
    temp_s0 = var_s2 + &D_801202A0;
    if ((temp_s0->unk0 != 0) && (temp_a1 = temp_s0->unk58, (temp_a1 != 0)) && ((temp_s0->unk5C & 0x8100) == 0x8000) && (temp_v1 = temp_s0->unk5E, (temp_v1 != 0xA)) && ((arg9 & 0x80) || (temp_v1 != temp_s4)) && ((temp_s4 != 0xD) || ((u16) temp_s0->unk5C & 0x2000)) && (func_80135260(temp_s0->unk20, temp_a1, arg3, arg4) != 0)) {
        if (((u16) temp_s0->unk5C & 0x4000) || (sp28 & temp_s0->unkAE)) {
            *arg11 = func_8014C918(arg0, temp_s0->unk75);
            *arg12 = 0;
            arg6->unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            arg6->unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            var_s1 |= 4;
            *arg7 = temp_s0;
            goto block_19;
        }
        sp1B = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        sp1F = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        if (sp30 != 0) {
            sp1E = 1;
        } else {
            sp1E = 0;
        }
        func_8014C4AC(temp_s0, arg1 & 0xFFFF, sp20 & 0x7FFF, &sp18, (s32) arg0->unk20->unk12);
        arg5->unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        arg5->unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        *arg7 = temp_s0;
        arg8->unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        arg8->unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        var_s1 |= 1;
        if (!(arg9 & 0x7F)) {
            goto block_19;
        }
    } else {
block_19:
        var_s3 += 1;
        var_s2 += 0x10C;
        if (var_s3 < 0x60U) {
            goto loop_3;
        }
    }
    return var_s1;
}
