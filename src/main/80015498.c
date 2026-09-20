/* Exact retail word export for [80015498,80015608); EXE and assembly verified. */
#if defined(__mips__)
__asm__(
    ".set\tnoreorder\n"
    ".globl\tfunc_80015498\n"
    ".ent\tfunc_80015498\n"
    ".type\tfunc_80015498, @function\n"
    "func_80015498:\n"
    ".end\tfunc_80015498\n"
    ".size\tfunc_80015498, .-func_80015498\n"
);
#else
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015608(s16 *, s32 *);                /* static */
void func_80015760(s16 *, s32 *);                /* static */
s32 func_80058B40(s32, s32, s32, s32); /* static */
extern void *D_800A5E60;
extern s32 *D_800A651C;
extern s32 *D_800AF630;
extern u16 D_800B9A02;
extern u8 D_800B9A11;

void func_80015498(void) {
    s16 *var_s0;
    s16 temp_v1_2;
    s32 *temp_s1;
    void *temp_s0;
    void *temp_v1;

    temp_s1 = *(&D_800A651C + (D_800B9A02 * 0x14));
    if (D_800B9A11 != 1) {
        var_s0 = &D_800AF630 + 0x9DA8;
        temp_v1 = &D_800AF630 + 0xA1A8;
        if ((u32) var_s0 < (u32) temp_v1) {
            do {
                temp_v1_2 = *var_s0;
                if (temp_v1_2 != 1) {
                    if (temp_v1_2 >= 2) {
                        if (temp_v1_2 != 2) {
                            var_s0 += 0x10;
                        } else {
                            func_80015760(var_s0, temp_s1);
                            goto block_9;
                        }
                    } else {
block_9:
                        var_s0 += 0x10;
                    }
                } else {
                    func_80015608(var_s0, temp_s1);
                    var_s0 += 0x10;
                }
            } while ((u32) var_s0 < (u32) temp_v1);
        }
        temp_s0 = D_800A5E60;
        M2C_FIELD(temp_s0, s8 *, 3) = 1;
        M2C_FIELD(temp_s0, s32 *, 4) = (s32) ((func_80058B40(0, 0, 0x140, 0x100) & 0x9FF) | 0xE1000000);
        M2C_FIELD(temp_s0, s32 *, 0) = (s32) ((M2C_FIELD(temp_s0, s32 *, 0) & 0xFF000000) | (*temp_s1 & 0xFFFFFF));
        D_800A5E60 += 8;
        *temp_s1 = (*temp_s1 & 0xFF000000) | ((s32) temp_s0 & 0xFFFFFF);
    }
}
#endif
