/* Overlay range [801325B8,8013277C) from MAIN.CD member 0012.
 * SHA256(span)=4d5e9f8d67646fdf60569c7cd1db10a35269af8983f8fcd94ab0b0038217268c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8004806C(s32, void *, s32, s32);       /* extern */
void func_8005C324(s32, s32, s32);               /* extern */

void func_801325B8(void *arg0, void *arg1, void *arg2, void *arg3, s32 arg4) {
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s2;
    s32 temp_s2_2;
    u32 var_a1;
    u32 var_a1_2;
    u32 var_s2;
    u32 var_s2_2;

    if (M2C_FIELD(arg1, s32 *, 4) == 1) {
        var_a1 = M2C_FIELD(arg1, u32 *, 0xC);
    } else {
        var_a1 = (u32) (arg1 + ((((u32) M2C_FIELD(arg1, u32 *, 0xC) >> 2) * 4) + 0xC));
    }
    if (M2C_FIELD(arg0, s32 *, 4) == 1) {
        var_s2 = M2C_FIELD(arg0, u32 *, 0xC);
    } else {
        var_s2 = (u32) (arg0 + ((((u32) M2C_FIELD(arg0, u32 *, 0xC) >> 2) * 4) + 0xC));
    }
    temp_s1 = M2C_FIELD(arg2, s32 *, 0xC);
    temp_s2 = var_s2 + (M2C_FIELD(arg2, s32 *, 8) * 8);
    func_8005C324(temp_s2, var_a1 + (M2C_FIELD(arg2, s32 *, 8) * 8), temp_s1 * 8);
    func_8004806C(temp_s2, arg2 + 0x10, temp_s1, arg4);
    if (arg3 != 0) {
        if (M2C_FIELD(arg1, s32 *, 4) == 1) {
            var_a1_2 = M2C_FIELD(arg1, u32 *, 0x14);
        } else {
            var_a1_2 = (u32) (arg1 + ((((u32) M2C_FIELD(arg1, u32 *, 0x14) >> 2) * 4) + 0xC));
        }
        if (M2C_FIELD(arg0, s32 *, 4) == 1) {
            var_s2_2 = M2C_FIELD(arg0, u32 *, 0x14);
        } else {
            var_s2_2 = (u32) (arg0 + ((((u32) M2C_FIELD(arg0, u32 *, 0x14) >> 2) * 4) + 0xC));
        }
        temp_s1_2 = M2C_FIELD(arg3, s32 *, 0xC);
        temp_s2_2 = var_s2_2 + (M2C_FIELD(arg3, s32 *, 8) * 8);
        func_8005C324(temp_s2_2, var_a1_2 + (M2C_FIELD(arg3, s32 *, 8) * 8), temp_s1_2 * 8);
        func_8004806C(temp_s2_2, arg3 + 0x10, temp_s1_2, arg4);
    }
}
