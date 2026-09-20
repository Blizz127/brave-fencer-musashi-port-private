/* Exact retail word export for [8001A114,8001A338); EXE and assembly verified. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_8001A114
"
    ".ent	func_8001A114
"
    ".type	func_8001A114, @function
"
    "func_8001A114:
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
    ".end	func_8001A114
"
    ".size	func_8001A114, .-func_8001A114
"
);
#else
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80063028;
void func_800434BC();                            /* static */
s32 func_80043830(s32, void *, u8 *);        /* static */
s32 func_80045374(s32 (*)(), void *);           /* static */
s32 func_80046630();                         /* static */
s32 func_8004674C();                                /* static */
extern u32 D_800AE6F4;
extern u8 D_800AE738;
extern s32 *D_800AE740;
extern s32 D_800AE750;

s32 func_8001A114(void) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_s0;
    s32 var_s3;
    s32 var_v0;
    u32 var_v0_2;
    u32 var_v0_3;

    var_s3 = 0;
    switch (D_800AE6F4) {
    case 0:
        func_800434BC();
        func_80043830(1, 0, &D_800AE738);
        var_v0 = 0;
        if (!(D_800AE738 & 0x10)) {
            D_800AE6F4 += 1;
        case 1:
            temp_v0 = func_80046630(0);
            if (temp_v0 != 2) {
                var_v0 = 0;
                if (temp_v0 == 0x10) {
block_6:
                    D_800AE6F4 = 0;
                    return 0;
                }
                /* Duplicate return node #26. Try simplifying control flow for better match */
                return var_v0;
            }
block_18:
            D_800AE6F4 += 1;
        default:
block_25:
            var_v0 = var_s3;
            /* Duplicate return node #26. Try simplifying control flow for better match */
            return var_v0;
        }
        return var_v0;
    case 2:
        M2C_FIELD(&D_800AE740, s8 *, 0) = 0x80;
        var_v0 = 0;
        if (func_80043830(0xE, &D_800AE740, &D_800AE740 - 8) != 0) {
            if (!(M2C_FIELD(&D_800AE740, u8 *, -8) & 0x10)) {
                D_800AE750 = 0;
                var_v0_2 = D_800AE6F4 + 1;
block_12:
                D_800AE6F4 = var_v0_2;
                return 0;
            }
            goto block_6;
        }
        /* Duplicate return node #26. Try simplifying control flow for better match */
        return var_v0;
    case 3:
        temp_v0_2 = D_800AE750 + 1;
        D_800AE750 = temp_v0_2;
        var_v0 = 0;
        if (temp_v0_2 >= 3) {
            D_800AE750 = 0;
            var_v0_2 = D_800AE6F4 + 1;
            goto block_12;
        }
        /* Duplicate return node #26. Try simplifying control flow for better match */
        return var_v0;
    case 4:
        temp_v0_3 = func_8004674C();
        if ((temp_v0_3 == 1) || (temp_v0_3 == 0x10) || (temp_v0_3 == 0)) {
            D_800AE6F4 = 0;
        }
        var_v0 = 0;
        if (temp_v0_3 == 2) {
            goto block_18;
        }
        /* Duplicate return node #26. Try simplifying control flow for better match */
        return var_v0;
    case 5:
        var_s0 = 0;
loop_20:
        temp_v0_4 = func_80045374(D_80063028, D_80063028 - 0x14);
        var_v0_3 = temp_v0_4 + 1;
        if (temp_v0_4 == -1) {
            var_s0 += 1;
            if (var_s0 >= 0x10) {
                var_v0_3 = temp_v0_4 + 1;
            } else {
                goto loop_20;
            }
        }
        if (var_v0_3 >= 2U) {
            var_s3 = 1;
            goto block_25;
        }
        goto block_6;
    }
}
#endif

