/* Overlay range [80177DA8,80177EA4) from MAIN.CD member 0012.
 * SHA256(span)=bb577e1f8b8414c92759c3efb4d346d279dcd474ddf760bccb3b21baff22bfbf.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80181B64[];

void func_80177DA8(void *arg0, s32 arg1, s16 arg2) {
    s16 temp_t1;
    s16 temp_v0;
    s16 var_t0;
    s32 temp_a0;
    s32 temp_v0_3;
    s32 var_a1;
    s32 var_t2;
    u32 temp_v0_2;
    u8 temp_t3;
    void *temp_a3;
    void *temp_a3_2;
    void *temp_a3_3;
    void *temp_a3_4;
    void *temp_a3_5;
    void *var_a2;

    var_a1 = arg1;
    var_t2 = 0x100;
    var_t0 = 0;
    temp_t3 = *(D_80181B64 + arg2);
    temp_t1 = (temp_t3 << 6) | 0x4016;
    M2C_FIELD(arg0, s16 *, 0xE) = temp_t1;
    temp_a3 = arg0 + 0x14;
    M2C_FIELD(temp_a3, s16 *, 0xE) = temp_t1;
    temp_a3_2 = temp_a3 + 0x14;
    var_a2 = temp_a3_2 + 0xC;
    do {
        temp_v0_2 = (u32) (var_a1 << 0x10) >> 0x1C;
        if ((temp_v0_2 != 0) || (var_t0 == 2) || (var_t0 == 0xFF)) {
            var_t2 = 0;
        }
        var_a1 *= 0x10;
        temp_v0 = var_t0 + 1;
        var_t0 = temp_v0;
        M2C_FIELD(var_a2, s8 *, 0) = (s8) ((temp_v0_2 * 8) + 8);
        M2C_FIELD(var_a2, u16 *, -2) = (u16) (var_t2 | (M2C_FIELD(var_a2, u16 *, -2) & ~0x100));
        var_a2 += 0x14;
    } while (temp_v0 < 3);
    M2C_FIELD(temp_a3_2, s16 *, 0xE) = temp_t1;
    temp_a3_3 = temp_a3_2 + 0x14;
    M2C_FIELD(temp_a3_3, s16 *, 0xE) = temp_t1;
    temp_a3_4 = temp_a3_3 + 0x14;
    M2C_FIELD(temp_a3_4, s16 *, 0xE) = temp_t1;
    temp_a3_5 = temp_a3_4 + 0x14;
    temp_v0_3 = ((temp_t3 << 6) | 0x4016) << 0x10;
    temp_a0 = (s32) (arg2 << 0x10) >> 0xC;
    M2C_FIELD(temp_a3_5, s32 *, 0xC) = (s32) (temp_v0_3 | (temp_a0 | 0x1000));
    M2C_FIELD(temp_a3_5, s32 *, 0x20) = (s32) (temp_v0_3 | (temp_a0 | 0x1008));
}
