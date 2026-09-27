/* Exact retail word export for [8005DE78,8005E0AC); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800729A0;
extern s32 *D_800729BC;
extern s32 D_800729C0;
void func_8005FBA8();                     /* static */
s32 func_8005FBC8();                                /* static */
extern u32 D_80078F24;
extern u32 D_800C5320;

s8 func_8005DE78(void *arg0, u8 arg1) {
    s16 var_s1;
    s8 temp_s2;
    s8 var_v0;
    u32 var_v1;

    var_s1 = 0x88;
    if ((((s32) *M2C_FIELD(arg0, u8 **, 0x3C) >> 4) == 8) && ((u8) M2C_FIELD(arg0, u8 *, 0x44) >= 9U)) {
        var_s1 = 0x22;
    }
    do {

    } while (!(M2C_FIELD(D_800729C0, u16 *, 4) & 2));
    func_8005FBA8(0x190);
    temp_s2 = M2C_FIELD(D_800729C0, u8 *, 0) & 0xFF;
    if ((M2C_FIELD(arg0, u8 *, 0x44) != 0) || ((temp_s2 >> 4) != 8)) {
        M2C_FIELD(D_800729C0, s16 *, 0xE) = var_s1;
    } else {
        M2C_FIELD(D_800729C0, s16 *, 0xE) = 0x22;
    }
    if (!(*D_800729BC & 0x80)) {
loop_11:
        var_v1 = *(u16 *)0x1F801120 & 0xFFFF;
        if (var_v1 < (u32) D_80078F24) {
            if (*(u16 *)0x1F801128 != 0) {
                var_v1 += *(u16 *)0x1F801128;
            } else {
                var_v1 += 0x10000;
            }
        }
        if (!(*(u16 *)0x1F801124 & 0x200) || (var_v0 = -2, (((u32) (var_v1 - D_80078F24) < (u32) D_800C5320) != 0))) {
            var_v0 = -2;
            if ((u32) ((u32) (var_v1 - D_80078F24) >> 3) < (u32) D_800C5320) {
                if (*D_800729BC & 0x80) {
                    goto block_19;
                }
                goto loop_11;
            }
        }
    } else {
block_19:
        if ((M2C_FIELD(arg0, u8 *, 0xE8) != 8) && (D_800729A0 == 2)) {
            func_8005FBA8(0x3C);
            do {

            } while (func_8005FBC8() == 0);
        }
        M2C_FIELD(D_800729C0, u8 *, 0) = arg1;
        M2C_FIELD(arg0, u8 *, 0x45) = (u8) (M2C_FIELD(arg0, u8 *, 0x45) + 1);
        if (M2C_FIELD(arg0, u8 *, 0x44) != 0xFF) {
            *(M2C_FIELD(arg0, u8 **, 0x3C) + M2C_FIELD(arg0, u8 *, 0x44)) = temp_s2;
        }
        var_v0 = temp_s2;
        M2C_FIELD(arg0, u8 *, 0x44) = (u8) (M2C_FIELD(arg0, u8 *, 0x44) + 1);
    }
    return var_v0;
}
