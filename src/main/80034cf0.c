/* Exact retail word export for [80034CF0,80034DFC); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006AEF5;
extern s32 D_8006AEF8;
extern s32 D_8006AEFC;
extern s32 *D_80076118;

s32 func_80034CF0(void *arg0) {
    s32 temp_a0;
    s32 var_a2;
    u8 temp_t0;
    void *temp_v1;

    temp_t0 = D_8006AEF5;
    D_8006AEF5 = 1U;
    var_a2 = D_8006AEFC + 1;
    if (var_a2 >= 4) {
        var_a2 = 0;
    }
    if (var_a2 != D_8006AEF8) {
        temp_v1 = (D_8006AEFC * 0x30) + &D_80076118;
        M2C_FIELD(temp_v1, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 8);
        M2C_FIELD(temp_v1, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
        M2C_FIELD(temp_v1, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
        M2C_FIELD(temp_v1, s32 *, 0x14) = (s32) M2C_FIELD(arg0, s32 *, 0x14);
        M2C_FIELD(temp_v1, s32 *, 0x18) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
        M2C_FIELD(temp_v1, s32 *, 0x1C) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
        M2C_FIELD(temp_v1, s32 *, 0x20) = (s32) M2C_FIELD(arg0, s32 *, 0x20);
        M2C_FIELD(temp_v1, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
        M2C_FIELD(temp_v1, s8 *, 0) = 1;
        M2C_FIELD(temp_v1, s8 *, 1) = 0;
        M2C_FIELD(temp_v1, s8 *, 2) = 0;
        M2C_FIELD(temp_v1, s8 *, 3) = 0;
        M2C_FIELD(temp_v1, s8 *, 7) = 1;
        temp_a0 = D_8006AEFC;
        D_8006AEFC = var_a2;
        D_8006AEF5 = temp_t0;
        M2C_FIELD(temp_v1, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
        M2C_FIELD(temp_v1, s32 *, 0x2C) = temp_a0;
        return temp_a0 + 1;
    }
    D_8006AEF5 = temp_t0;
    return 0;
}
