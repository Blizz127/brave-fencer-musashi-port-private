/* Exact retail word export for [80053804,8005386C); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800538BC(s32, void *);              /* static */
extern s32 *D_800A6558;

void func_80053804(void *arg0) {
    s32 temp_a1;

    M2C_FIELD(&D_800A6558, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD(&D_800A6558, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 4);
    M2C_FIELD(&D_800A6558, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 8);
    temp_a1 = M2C_FIELD(arg0, s32 *, 0x14);
    M2C_FIELD(&D_800A6558, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(&D_800A6558, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
    M2C_FIELD(&D_800A6558, s32 *, 0x14) = temp_a1;
    M2C_FIELD(&D_800A6558, s32 *, 0x18) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    M2C_FIELD(&D_800A6558, s32 *, 0x1C) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
    func_800538BC(temp_a1, &D_800A6558);
}
