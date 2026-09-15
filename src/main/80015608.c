/* Exact retail word export for [80015608,80015760); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

u16 *func_80015908(u8, s32, s32);                   /* static */
extern s32 D_800A5E60;
extern u16 D_800AF7BC;
extern u16 D_800AF7BE;

void func_80015608(void *arg0, s32 *arg1) {
    s32 sp10;
    s32 temp_fp;
    s32 temp_v0;
    s32 var_s1;
    s32 var_s3;
    s32 var_s6;
    s32 var_v1;
    u8 *var_s2;
    u8 temp_a0;
    u8 temp_s7;
    void *var_s0;

    var_s2 = M2C_FIELD(arg0, u8 **, 8);
    temp_s7 = M2C_FIELD(arg0, u8 *, 0xC);
    var_s3 = M2C_FIELD(arg0, u16 *, 2) - ((u16) D_800AF7BC >> 1);
    var_s6 = 8;
    if (temp_s7 & 0x80) {
        var_s6 = 0x10;
    }
    var_v1 = 0x7C000000;
    if ((var_s6 & 0xFF) == 8) {
        var_v1 = 0x74000000;
    }
    var_s1 = D_800A5E60;
    if (*var_s2 != 0) {
        sp10 = var_v1 | 0x808080;
        temp_fp = (M2C_FIELD(arg0, u16 *, 4) - ((u16) D_800AF7BE >> 1)) << 0x10;
        var_s0 = var_s1 + 0xC;
        do {
            temp_v0 = var_s3 & 0xFFFF;
            var_s3 += var_s6;
            M2C_FIELD(var_s0, s32 *, -4) = (s32) (temp_v0 | temp_fp);
            M2C_FIELD(var_s0, s32 *, -8) = sp10;
            temp_a0 = *var_s2;
            var_s2 += 1;
            M2C_FIELD(var_s0, s32 *, 0) = (s32) (*func_80015908(temp_a0, temp_s7 & 0xFFFF, sp10) | 0x40560000);
            var_s0 += 0x10;
            *(s32 *) var_s1 = (s32) ((*arg1 & 0xFFFFFF) | 0x03000000);
            *arg1 = var_s1 & 0xFFFFFF;
            var_s1 += 0x10;
        } while (*var_s2 != 0);
    }
    D_800A5E60 = var_s1;
}
