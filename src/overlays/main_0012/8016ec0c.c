/* Overlay range [8016EC0C,8016ED6C) from MAIN.CD member 0012.
 * SHA256(span)=0712f096bc44a1231f58abb4388f1f1e16318b11d879448fd1957190f3e642d7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80017B98(u16 *);                       /* extern */
extern s32 D_8018172C[];

void func_8016EC0C(void *arg0, s8 arg1) {
    u8 sp28;
    s32 sp24;
    s8 sp22;
    s8 sp21;
    s8 sp20;
    s16 sp1E;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    s32 sp14;
    u16 sp12;
    u16 sp10;
    u16 temp_s4;
    u16 temp_s4_2;
    u16 temp_v0;
    u16 var_s3;
    u16 var_v0;
    u16 var_v1;
    u8 *var_s2;

    sp22 = arg1;
    sp21 = arg1;
    sp20 = arg1;
    sp1C = 0x640;
    sp1E = 0x1C8;
    sp24 = 0;
    sp18 = 0x28;
    sp1A = 8;
    sp28 = *(D_8018172C + M2C_FIELD(arg0, u8 *, 3));
    var_s3 = M2C_FIELD(arg0, u16 *, 4);
    var_s2 = arg0 + 8;
    sp10 = var_s3 + 0x10;
    temp_s4 = M2C_FIELD(arg0, u16 *, 6);
    sp14 = 0x10;
    sp12 = temp_s4;
    func_80017B98(&sp10);
    sp18 = 8;
    temp_s4_2 = temp_s4 + 0xA;
    if (M2C_FIELD(arg0, u16 *, 8) != 0xFFFF) {
        var_v1 = M2C_FIELD(arg0, u16 *, 8);
        do {
            if (var_v1 != 0x1858) {
                if ((s32) var_v1 < 0x1859) {
                    var_v0 = var_s3 + 4;
                    if (var_v1 != 0x1850) {
                        sp10 = var_s3;
                        goto block_11;
                    }
                    goto block_9;
                    goto block_12;
                }
                if (var_v1 != 0x3872) {
                    sp10 = var_s3;
block_11:
                    var_s3 += 8;
                    sp12 = temp_s4_2;
                    goto block_12;
                }
                var_s3 += 2;
                var_s2 += 2;
            } else {
                var_v0 = var_s3 + 4;
block_9:
                sp10 = var_v0;
                sp12 = temp_s4_2 - 7;
block_12:
                sp1C = *var_s2 + 0x500;
                temp_v0 = (u16) *var_s2;
                var_s2 += 2;
                sp1E = (temp_v0 >> 8) + 0x100;
                func_80017B98(&sp10);
            }
            var_v1 = *var_s2;
        } while (var_v1 != 0xFFFF);
    }
}
