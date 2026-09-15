/* Overlay range [80147118,80147264) from MAIN.CD member 0012.
 * SHA256(span)=d988622db65ecd73bc19f45f0d688f9fb1a4dc223c8505753b32d32b8bee3d26.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80147118(void *arg0) {
    s32 sp8;
    s32 sp4;
    s32 sp0;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_a2;
    s32 var_a3;
    s32 var_v1;

    var_v1 = M2C_FIELD(arg0, s16 *, 0x60) * M2C_FIELD(arg0, s16 *, 0x68);
    if (var_v1 < 0) {
        var_v1 += 0xFFF;
    }
    temp_v1 = var_v1 >> 0xC;
    sp0 = temp_v1;
    temp_lo = temp_v1 * M2C_FIELD(arg0, s16 *, 0x70);
    var_a3 = temp_lo >> 0xC;
    if (temp_lo < 0) {
        var_a3 = (s32) (temp_lo + 0xFFF) >> 0xC;
    }
    sp0 = var_a3;
    temp_v1_2 = (s32) (M2C_FIELD(arg0, s16 *, 0x62) * M2C_FIELD(arg0, s16 *, 0x6A)) / 4096;
    sp4 = temp_v1_2;
    temp_lo_2 = temp_v1_2 * M2C_FIELD(arg0, s16 *, 0x72);
    var_a2 = temp_lo_2 >> 0xC;
    if (temp_lo_2 < 0) {
        var_a2 = (s32) (temp_lo_2 + 0xFFF) >> 0xC;
    }
    sp4 = var_a2;
    temp_v1_3 = (s32) (M2C_FIELD(arg0, s16 *, 0x64) * M2C_FIELD(arg0, s16 *, 0x6C)) / 4096;
    sp8 = temp_v1_3;
    temp_v1_4 = (s32) (temp_v1_3 * M2C_FIELD(arg0, s16 *, 0x74)) / 4096;
    sp8 = temp_v1_4;
    if (var_a3 > 0xFFFF) {
        sp0 = 0xFFFF;
    }
    if (var_a2 > 0xFFFF) {
        sp4 = 0xFFFF;
    }
    if (temp_v1_4 > 0xFFFF) {
        sp8 = 0xFFFF;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x18) = (s16) sp0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x1A) = (s16) sp4;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x1C) = (s16) sp8;
}
