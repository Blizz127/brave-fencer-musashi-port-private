/* Overlay range [80138DE0,80138ED0) from MAIN.CD member 0012.
 * SHA256(span)=15677e92abe0e8c1cc8cf2f72e1d869999df25a69f85ad6913530e9fe9cee8f1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80138ED0(s32, void *);                  /* static */
extern s32 *D_800D3AB4;
extern s32 D_80127548;

s32 func_80138DE0(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 var_a2;
    u16 *var_s0;
    u16 var_v0;
    u32 temp_v1;

    var_a2 = arg2;
    if (D_80127548 != 0) {
        var_s0 = arg0 + 0x44;
        if (!(M2C_FIELD(arg0, s32 *, 8) & 0x400)) {
            var_s0 = arg0 + 0x10;
            if (M2C_FIELD(arg0, s16 *, 4) == 8) {
                var_s0 = arg0 + 0x44;
            }
        }
        temp_v1 = arg1 & 0xFF;
        if (temp_v1 >= 0xE0U) {
            var_a2 = func_80138ED0(0x1F, &D_800D3AB4);
            if (var_a2 == 0) {
                var_v0 = *var_s0 + 2;
                goto block_10;
            }
            goto block_13;
        }
        if (temp_v1 >= 0x20U) {
            var_a2 = func_80138ED0(((arg1 & 0xFF) - 0x20) & 0xFFFF, &D_800D3AB4);
            if (var_a2 == 0) {
                var_v0 = *var_s0 + 1;
block_10:
                *var_s0 = var_v0;
                goto block_11;
            }
            /* Duplicate return node #14. Try simplifying control flow for better match */
            return 0;
        }
block_11:
        if (var_a2 == 0) {
            temp_v0 = D_80127548 - 1;
            D_80127548 = temp_v0;
            return temp_v0;
        }
        /* Duplicate return node #14. Try simplifying control flow for better match */
        return 0;
    }
block_13:
    return 0;
}
