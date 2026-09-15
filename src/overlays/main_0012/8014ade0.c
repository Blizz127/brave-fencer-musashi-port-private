/* Overlay range [8014ADE0,8014B00C) from MAIN.CD member 0012.
 * SHA256(span)=7e1847b170e00610a7cf94118042dfe92b2c91d0bd523d766a536f9add7bf279.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029178(s32, s32);                            /* extern */
void func_8014B084();                                  /* static */
s32 func_8014B154(void *, s32, s32);                /* static */
void func_8014BB24(void *, s32, s32);                      /* static */
void func_8014BC80(void *, s32);                         /* static */
void func_8014BD24(void *, s32, s32);                      /* static */
void func_8014BD60(void *, s32);                         /* static */
s32 func_8016F1C4();                                /* static */
extern s32 D_80078E78;
extern s32 D_80078E90;

void func_8014ADE0(void *arg0) {
    s32 var_a1;
    s32 var_a1_2;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_hi;
    s32 temp_s2;
    s32 var_v0;
    u16 temp_v1;

    if (func_8016F1C4() == 0) {
        temp_v1 = arg0->unk0;
        if ((temp_v1 != 0x1A) && (temp_v1 != 0x1E) && !(arg0->unk44 & 0x10)) {
            temp_s2 = D_80078E90;
            if (func_8014B154(arg0) != 0) {
                var_v0 = D_80078E90 + 0xAAA8;
            } else {
                var_v0 = D_80078E90 + 0x1555;
            }
            D_80078E90 = var_v0;
            if ((D_80078E78.unk1A - (temp_s2 >> 0x10)) > 0) {
                if (D_80078E78.unk49 == 3) {
                    func_8014BD24(arg0, 1, 0x88880000);
                }
            }
            temp_a1 = temp_s2 >> 0x10;
            temp_hi = temp_s2 / 122880;
            temp_a1_2 = (s32) (temp_a1 << 0x10) >> 0x1F;
            if (((s16) (D_80078E78.unk1A / 60) - (s16) (((s32) (temp_hi + (s16) temp_a1) >> 5) - temp_a1_2)) > 0) {
                var_a1 = 4;
                if (func_8014B154(arg0, temp_a1_2, temp_hi) != 0) {
                    var_a1 = 4;
                    if (func_80029178(0x1B, 4) & 0xFF) {
                        var_a1 = 0xA;
                    }
                }
                if (D_80078E78.unk40 != 0) {
                    func_8014BB24(arg0, var_a1, 0);
                } else if (D_80078E78.unk3C != 0) {
                    if ((u16) D_80078E78.unk3C >= 5U) {
                        func_8014BC80(arg0, 4);
                    } else {
                        D_80078E78.unk3C = 1U;
                    }
                }
                if (func_8014B154(arg0) != 0) {
                    if (func_80029178(0x1B) & 0xFF) {
                        func_8014BD24(arg0, 8);
                    } else {
                        var_a1_2 = 1;
                        goto block_26;
                    }
                } else {
                    var_a1_2 = 4;
block_26:
                    func_8014BD60(arg0, var_a1_2);
                }
            }
            if (D_80078E78.unk1A >= 0x5A0) {
                D_80078E78.unk18 = 0;
                func_8014B084();
            }
        }
    }
}
