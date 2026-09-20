/* Exact retail word export for [80018CE8,80018E78); EXE and assembly verified. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_80018CE8
"
    ".ent	func_80018CE8
"
    ".type	func_80018CE8, @function
"
    "func_80018CE8:
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
    ".end	func_80018CE8
"
    ".size	func_80018CE8, .-func_80018CE8
"
);
#else
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016714(u8 *, s32, s32, u8 *);    /* static */
void func_80018F20(u8 *, u8, s32, u8 *);         /* static */
extern s32 *D_80078DE4;

void func_80018CE8(u8 *arg0, s32 arg2) {
    s32 var_a2;
    u8 *var_v0;
    u8 *var_v0_2;
    u8 *var_v0_4;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_v1;
    u8 var_a1;
    void *var_v0_3;
    void *var_v0_5;

    var_a2 = arg2;
    if (arg0 != &D_80078DE4) {
        temp_v1 = *arg0;
        if (temp_v1 != 0x53) {
            if ((s32) temp_v1 < 0x54) {
                var_a2 = 0;
                if (temp_v1 != 0x41) {
                    goto block_20;
                }
                var_v0 = arg0;
                do {
                    var_a2 += 1;
                    temp_a0 = M2C_FIELD(var_v0, u8 *, 0x2A);
                    M2C_FIELD(var_v0, u8 *, 0x42) = (u8) M2C_FIELD(var_v0, u8 *, 0x32);
                    M2C_FIELD(var_v0, s8 *, 0x3A) = (s8) (temp_a0 & (temp_a0 ^ M2C_FIELD(var_v0, u8 *, 0x32)));
                    M2C_FIELD(var_v0, u8 *, 0x32) = (u8) M2C_FIELD(var_v0, u8 *, 0x2A);
                    var_v0 = arg0 + var_a2;
                } while (var_a2 < 2);
                return;
            }
            var_a2 = 0;
            if (temp_v1 != 0x73) {
                goto block_20;
            }
            var_v0_2 = arg0;
            do {
                var_a2 += 1;
                temp_a0_2 = M2C_FIELD(var_v0_2, u8 *, 0x2A);
                M2C_FIELD(var_v0_2, u8 *, 0x42) = (u8) M2C_FIELD(var_v0_2, u8 *, 0x32);
                var_a1 = M2C_FIELD(var_v0_2, u8 *, 0x2A);
                M2C_FIELD(var_v0_2, s8 *, 0x3A) = (s8) (temp_a0_2 & (temp_a0_2 ^ M2C_FIELD(var_v0_2, u8 *, 0x32)));
                M2C_FIELD(var_v0_2, u8 *, 0x32) = var_a1;
                var_v0_2 = arg0 + var_a2;
            } while (var_a2 < 2);
            var_v0_3 = arg0 + var_a2;
            if (var_a2 < 8) {
                do {
                    var_a2 += 1;
                    M2C_FIELD(var_v0_3, u8 *, 0x42) = (u8) M2C_FIELD(var_v0_3, u8 *, 0x32);
                    M2C_FIELD(var_v0_3, u8 *, 0x32) = (u8) M2C_FIELD(var_v0_3, u8 *, 0x2A);
                    var_v0_3 = arg0 + var_a2;
                } while (var_a2 < 8);
            }
            goto block_19;
        }
        var_a2 = 0;
        var_v0_4 = arg0;
        do {
            var_a2 += 1;
            temp_a0_3 = M2C_FIELD(var_v0_4, u8 *, 0x2A);
            M2C_FIELD(var_v0_4, u8 *, 0x42) = (u8) M2C_FIELD(var_v0_4, u8 *, 0x32);
            var_a1 = M2C_FIELD(var_v0_4, u8 *, 0x2A);
            M2C_FIELD(var_v0_4, s8 *, 0x3A) = (s8) (temp_a0_3 & (temp_a0_3 ^ M2C_FIELD(var_v0_4, u8 *, 0x32)));
            M2C_FIELD(var_v0_4, u8 *, 0x32) = var_a1;
            var_v0_4 = arg0 + var_a2;
        } while (var_a2 < 2);
        var_v0_5 = arg0 + var_a2;
        if (var_a2 < 8) {
            do {
                var_a2 += 1;
                M2C_FIELD(var_v0_5, u8 *, 0x42) = (u8) M2C_FIELD(var_v0_5, u8 *, 0x32);
                M2C_FIELD(var_v0_5, u8 *, 0x32) = (u8) M2C_FIELD(var_v0_5, u8 *, 0x2A);
                var_v0_5 = arg0 + var_a2;
            } while (var_a2 < 8);
        }
block_19:
        func_80018F20(arg0, var_a1, var_a2, arg0);
        return;
    }
block_20:
    func_80016714(arg0, 0x4C, var_a2, arg0);
}
#endif

