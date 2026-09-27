/* Exact retail word export for [8005DCA0,8005DE78); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800729BC;
extern s32 D_800729C0;
s32 func_8005FBC8();                                /* static */
extern s32 D_80078F24;
extern s32 D_800C5320;

s8 func_8005DCA0(void *arg0, s32 arg1) {
    s16 var_a2;
    s8 temp_s1;
    s8 temp_s1_2;
    s8 var_v0;

    if (arg1 < 0) {
        M2C_FIELD(arg0, u8 *, 0x44) = 0xFFU;
        M2C_FIELD(arg0, u8 *, 0x45) = 1U;
        *M2C_FIELD(arg0, s8 **, 0x40) = ~arg1;
        temp_s1 = M2C_FIELD(D_800729C0, u8 *, 0) & 0xFF;
        if (!(M2C_FIELD(D_800729C0, u16 *, 4) & 1)) {
            do {

            } while (!(M2C_FIELD(D_800729C0, u16 *, 4) & 1));
        }
        do {

        } while (func_8005FBC8() == 0);
        M2C_FIELD(D_800729C0, u8 *, 0) = (u8) ~arg1;
        return temp_s1;
    }
    var_a2 = 0x88;
    if (((s32) *M2C_FIELD(arg0, u8 **, 0x3C) >> 4) == 8) {
        if ((u8) M2C_FIELD(arg0, u8 *, 0x44) >= 9U) {
            var_a2 = 0x22;
        }
    }
    D_800C5320 = 0x1AE;
    D_80078F24 = (s32) *(u16 *)0x1F801120;
    if (!(M2C_FIELD(D_800729C0, u16 *, 4) & 2)) {
        do {

        } while (!(M2C_FIELD(D_800729C0, u16 *, 4) & 2));
    }
    M2C_FIELD(D_800729C0, s16 *, 0xE) = var_a2;
    temp_s1_2 = M2C_FIELD(D_800729C0, u8 *, 0) & 0xFF;
    if (!(*D_800729BC & 0x80)) {
loop_12:
        var_v0 = -0x14;
        if (func_8005FBC8() == 0) {
            if (*D_800729BC & 0x80) {
                goto block_14;
            }
            goto loop_12;
        }
    } else {
block_14:
        M2C_FIELD(D_800729C0, u8 *, 0) = (u8) arg1;
        M2C_FIELD(arg0, u8 *, 0x45) = (u8) (M2C_FIELD(arg0, u8 *, 0x45) + 1);
        *(M2C_FIELD(arg0, u8 **, 0x3C) + M2C_FIELD(arg0, u8 *, 0x44)) = temp_s1_2;
        M2C_FIELD(arg0, u8 *, 0x44) = (u8) (M2C_FIELD(arg0, u8 *, 0x44) + 1);
        var_v0 = temp_s1_2;
    }
    return var_v0;
}
