/* Exact retail word export for [80053D44,80053E28); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80053D44(void *arg0, void *arg1) {
    u32 temp_v0;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;

    temp_v0 = M2C_FIELD(arg0, u32 *, 0);
    M2C_FIELD(arg1, u32 *, 0) = temp_v0;
    if ((temp_v0 >> 3) & 1) {
        temp_a0 = arg0 + 4;
        temp_v0_2 = temp_a0 + (((u32) M2C_FIELD(arg0, u32 *, 4) >> 2) * 4);
        temp_a0_2 = temp_a0 + 4;
        M2C_FIELD(arg1, s16 *, 0x10) = (s16) M2C_FIELD(temp_a0, s32 *, 4);
        temp_a0_3 = temp_a0_2 + 4;
        M2C_FIELD(arg1, u16 *, 0x12) = (u16) M2C_FIELD(temp_a0_2, u16 *, 2);
        temp_v0_3 = temp_v0_2 + 4;
        M2C_FIELD(arg1, s16 *, 0x14) = (s16) M2C_FIELD(temp_a0_2, s32 *, 4);
        M2C_FIELD(arg1, void **, 0x18) = (void *) (temp_a0_3 + 4);
        M2C_FIELD(arg1, u16 *, 0x16) = (u16) M2C_FIELD(temp_a0_3, u16 *, 2);
        M2C_FIELD(arg1, s16 *, 4) = (s16) M2C_FIELD(temp_v0_2, s32 *, 4);
        temp_v0_4 = temp_v0_3 + 4;
        M2C_FIELD(arg1, u16 *, 6) = (u16) M2C_FIELD(temp_v0_3, u16 *, 2);
        M2C_FIELD(arg1, s16 *, 8) = (s16) M2C_FIELD(temp_v0_3, s32 *, 4);
        M2C_FIELD(arg1, void **, 0xC) = (void *) (temp_v0_4 + 4);
        M2C_FIELD(arg1, u16 *, 0xA) = (u16) M2C_FIELD(temp_v0_4, u16 *, 2);
        return;
    }
    temp_a0_4 = arg0 + 8;
    M2C_FIELD(arg1, s16 *, 4) = (s16) M2C_FIELD(arg0, s32 *, 8);
    temp_a0_5 = temp_a0_4 + 4;
    M2C_FIELD(arg1, u16 *, 6) = (u16) M2C_FIELD(temp_a0_4, u16 *, 2);
    M2C_FIELD(arg1, s16 *, 8) = (s16) M2C_FIELD(temp_a0_4, s32 *, 4);
    M2C_FIELD(arg1, void **, 0xC) = (void *) (temp_a0_5 + 4);
    M2C_FIELD(arg1, u16 *, 0xA) = (u16) M2C_FIELD(temp_a0_5, u16 *, 2);
}
