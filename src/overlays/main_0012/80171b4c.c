/* Overlay range [80171B4C,80171C64) from MAIN.CD member 0012.
 * SHA256(span)=2419efb76e4de6ffde5d8a9ab35167ddd2fb9da9800bab164ae3b7663801ea53.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8004CFEC(s32, s32, s32);                   /* extern */
void func_80146D90(void *);                      /* static */
extern void *D_801151D4;

s32 func_80171B4C(void *arg0, s32 arg1) {
    s16 var_v0_2;
    s32 temp_a2;
    s32 temp_v0;
    s32 var_v0;
    s32 var_v1;
    u8 temp_v0_2;

    M2C_FIELD(arg0, s8 *, 0xA9) = 0x41;
    temp_a2 = M2C_FIELD(D_801151D4, s32 *, 0x70);
    temp_v0 = ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12) - ((func_8004CFEC(M2C_FIELD(D_801151D4, s32 *, 0x68) - M2C_FIELD(D_801151D4, s32 *, 0x5C), temp_a2 - M2C_FIELD(D_801151D4, s32 *, 0x64), temp_a2) + 0x800) & 0xFFF)) + 0x100) & 0xE00;
    var_v1 = temp_v0 >> 9;
    if (temp_v0 < 0) {
        var_v1 = (s32) (temp_v0 + 0x1FF) >> 9;
    }
    switch (var_v1) {
    case 0:
        var_v0_2 = 0x1000;
block_12:
        M2C_FIELD(arg0, s16 *, 0xAA) = var_v0_2;
        break;
    case 1:
        var_v0_2 = 0x3000;
        goto block_12;
    case 2:
        var_v0_2 = 0x2000;
        goto block_12;
    case 3:
        var_v0_2 = 0x6000;
        goto block_12;
    case 4:
        var_v0_2 = 0x4000;
        goto block_12;
    case 5:
        var_v0_2 = 0xC000;
        goto block_12;
    case 6:
        var_v0_2 = 0x8000;
        goto block_12;
    case 7:
        var_v0_2 = 0x9000;
        goto block_12;
    }
    temp_v0_2 = M2C_FIELD(arg0, u8 *, 0x20C);
    M2C_FIELD(arg0, u8 *, 0x20C) = (u8) (temp_v0_2 + 1);
    var_v0 = 0;
    if ((temp_v0_2 & 0xFF) == (arg1 & 0xFF)) {
        func_80146D90(arg0);
        var_v0 = 1;
    }
    return var_v0;
}
