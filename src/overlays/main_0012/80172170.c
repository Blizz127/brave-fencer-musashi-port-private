/* Overlay range [80172170,801722CC) from MAIN.CD member 0012.
 * SHA256(span)=7a7ae65a30a162ad3a3f55075f2edf6d5b5348b19e31d60929dff8a7d4a4bbfe.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8004787C(s32);                             /* extern */
s32 func_80047948(s32);                             /* extern */
s32 func_8004CFEC(s32, s32, s32);                   /* extern */
extern void *D_801151D4;

void func_80172170(void *arg0, s32 arg1) {
    s32 temp_a2;
    s32 temp_s0;
    s32 var_s1;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;

    M2C_FIELD(arg0, s8 *, 0xA9) = 0x73;
    temp_a2 = M2C_FIELD(D_801151D4, s32 *, 0x70);
    temp_s0 = (M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12) - ((func_8004CFEC(M2C_FIELD(D_801151D4, s32 *, 0x68) - M2C_FIELD(D_801151D4, s32 *, 0x5C), temp_a2 - M2C_FIELD(D_801151D4, s32 *, 0x64), temp_a2) + 0x800) & 0xFFF)) & 0xFF8;
    if ((temp_s0 == 0x400) || (temp_s0 == 0xC00)) {
        var_s1 = 0x80;
    } else {
        var_s1 = ((s32) (-((s32) (arg1 & 0xFF) >> 1) * func_80047948(temp_s0)) / 4096) + 0x80;
    }
    var_v0 = var_s1 < 0x100;
    if (var_s1 < 0) {
        var_s1 = 0;
        var_v0 = 0 < 0x100;
    }
    if (var_v0 == 0) {
        var_s1 = 0xFF;
    }
    if ((temp_s0 == 0) || (temp_s0 == 0x800)) {
        var_v1 = 0x80;
    } else {
        var_v1 = ((s32) (((s32) (arg1 & 0xFF) >> 1) * func_8004787C(temp_s0)) / 4096) + 0x80;
    }
    var_v0_2 = var_v1 < 0x100;
    if (var_v1 < 0) {
        var_v1 = 0;
        var_v0_2 = 0 < 0x100;
    }
    var_v0_3 = var_v1 & 0xFF;
    if (var_v0_2 == 0) {
        var_v0_3 = 0xFF & 0xFF;
    }
    M2C_FIELD(arg0, s16 *, 0xAE) = (s16) (var_v0_3 | (var_s1 << 8));
}
