/* Overlay range [8014A048,8014A1B0) from MAIN.CD member 0012.
 * SHA256(span)=8dc9afab9bc0e6df6da4e0760cdbef904a8a0a77285398c249c0cc15f95bdeb3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8012F14C(s32, s16 *, void *);       /* static */
s32 func_80135260(s32, s32, u16 *, void *);      /* static */
void func_8014A1B0(void *, void *);              /* static */
s32 func_8014BEF8(void *, s16 *);                   /* static */
extern s32 *D_801202A0;

s32 func_8014A048(void *arg0) {
    s16 sp24;
    s16 sp22;
    s16 sp20;
    s32 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 temp_a1;
    s32 var_s2;
    u16 temp_v1;
    u32 var_s3;
    void *temp_s0;

    if (!(M2C_FIELD(arg0, s32 *, 0x44) & 0x400)) {
        temp_v1 = M2C_FIELD(arg0, u16 *, 0xAC);
        if (!(temp_v1 & 0x80)) {
            if (temp_v1 & 0x10) {
                if (func_8014BEF8(arg0, &sp20) != 0) {
                    goto block_4;
                }
                /* Duplicate return node #15. Try simplifying control flow for better match */
                return 0;
            }
            /* Duplicate return node #15. Try simplifying control flow for better match */
            return 0;
        }
block_4:
        sp10 = M2C_FIELD(arg0, u16 *, 6);
        var_s3 = 0;
        sp12 = M2C_FIELD(arg0, u16 *, 0xA);
        sp22 = -0x10;
        sp20 = 0;
        sp24 = -0x20;
        sp14 = M2C_FIELD(arg0, u16 *, 0xE);
        var_s2 = 0;
        func_8012F14C(M2C_FIELD(arg0, s32 *, 0x20) + 0x34, &sp20, &sp18);
loop_5:
        temp_s0 = var_s2 + &D_801202A0;
        if ((M2C_FIELD(temp_s0, u16 *, 0) == 0) || (temp_a1 = M2C_FIELD(temp_s0, s32 *, 0x58), (temp_a1 == 0)) || (M2C_FIELD(temp_s0, s16 *, 0xAA) != 0) || (M2C_FIELD(arg0, s32 *, 0x184) == temp_s0) || !(M2C_FIELD(temp_s0, u16 *, 0x5C) & 0x200) || (func_80135260(M2C_FIELD(temp_s0, s32 *, 0x20), temp_a1, &sp10, &sp18) == 0)) {
            var_s3 += 1;
            var_s2 += 0x10C;
            if (var_s3 >= 0x60U) {
                return 0;
            }
            goto loop_5;
        }
        M2C_FIELD(arg0, void **, 0x178) = temp_s0;
        func_8014A1B0(arg0, temp_s0);
        return 1;
    }
    return 0;
}
