/* Main-exec range [8001BC6C,8001BD80) from the SLUS executable.
 * SHA256(span)=89fc8f8417c38e63cd3ed28eb578c07527f75e86f64650c3c3051dff55ceefc8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800A5E60;
extern s32 *D_800A6610;
extern u16 D_800B9A02;

void func_8001BC6C(void *arg0, s32 arg1) {
    s32 *temp_a3;
    s32 temp_a0;
    s32 var_t2;
    u16 temp_t3;
    u16 temp_v0;
    u16 var_t0;
    void *temp_t1;

    var_t2 = 0x100;
    temp_v0 = M2C_FIELD(arg0, u16 *, 0);
    temp_t3 = M2C_FIELD(arg0, u16 *, 2);
    temp_a3 = D_800A5E60;
    var_t0 = temp_v0;
    temp_t1 = (D_800B9A02 << 0xE) + &D_800A6610;
    if ((s16) var_t0 >= 0x80) {
        var_t0 -= 0x80;
        var_t2 = 0x102;
    }
    M2C_FIELD(temp_a3, s8 *, 3) = 5;
    M2C_FIELD(temp_a3, s32 *, 4) = (s32) (var_t2 | 0xE1000000);
    M2C_FIELD(temp_a3, s8 *, 0xB) = 0x64;
    M2C_FIELD(temp_a3, s32 *, 0xC) = (s32) (((temp_t3 - 0x78) << 0x10) | ((temp_v0 - 0xA0) & 0xFFFF));
    M2C_FIELD(temp_a3, s32 *, 0x10) = (s32) (((s32) (temp_t3 << 0x10) >> 8) | (s16) var_t0);
    temp_a0 = M2C_FIELD(temp_a3, s32 *, 0);
    M2C_FIELD(temp_a3, s32 *, 8) = (s32) ((arg1 << 0x10) | ((arg1 << 8) | 0x64000000) | arg1);
    M2C_FIELD(temp_a3, s32 *, 0x14) = (s32) ((M2C_FIELD(arg0, u16 *, 6) << 0x10) | (s16) M2C_FIELD(arg0, u16 *, 4));
    D_800A5E60 = temp_a3 + 0x18;
    M2C_FIELD(temp_a3, s32 *, 0) = (temp_a0 & 0xFF000000) | (M2C_FIELD(temp_t1, s32 *, 4) & 0xFFFFFF);
    M2C_FIELD(temp_t1, s32 *, 4) = (s32) ((M2C_FIELD(temp_t1, s32 *, 4) & 0xFF000000) | ((s32) temp_a3 & 0xFFFFFF));
}
