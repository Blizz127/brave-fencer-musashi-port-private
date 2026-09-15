/* Exact retail word export for [8001AF34,8001B0D4); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800747E4;
void func_80019AF8();                     /* static */
s32 func_8001B0D4(s32 *, s16);                      /* static */
s32 func_8001B394(s32);                             /* static */
s32 func_8001B7C4(s32 *);                           /* static */
s32 func_80034B98();                                /* static */
extern s16 D_800A6430;
extern s32 D_800A6550;
extern s32 D_800AE640;
extern s32 *D_800AE6E4;
extern s32 D_800AE708;
extern s32 D_800AE720;
extern s32 D_800AE724;
extern s32 D_800AE72C;
extern s32 *D_800AE7A4;
extern s32 D_800AE7A8;
extern s32 D_800AE7B0;
extern u32 D_800BA1B4;
extern s32 D_800BA318;
extern s32 D_800C6D2C;

void func_8001AF34(void) {
    s32 *temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 var_v0;

    func_80034B98();
    switch (D_800BA1B4) {
    case 0:
    case 3:
        break;
    case 1:
        temp_s0 = D_800AE6E4;
        temp_s2 = D_800BA318;
        temp_s3 = D_800C6D2C;
        temp_s1 = D_800A6550;
        if (func_80034B98() == 0) {
            if (D_800AE708 != 0) {
                if (*temp_s0 != D_800AE708) {
                    goto block_5;
                }
                goto block_7;
            }
block_7:
            D_800AE72C = temp_s2;
            D_800AE7A8 = temp_s3;
            D_800AE7A4 = temp_s0;
            D_800AE724 = temp_s1;
            D_800AE720 = 0;
            D_800AE708 = *temp_s0;
            if (temp_s1 == 0) {
                D_800AE720 = 1;
            }
            func_80019AF8(0);
            var_v0 = D_800AE7B0;
        } else {
block_5:
            var_v0 = 0;
        }
        if (var_v0 != 0) {
block_18:
            D_800BA1B4 = 3;
        }
        break;
    case 2:
        if (func_8001B394(D_800AE640) != 0) {
            goto block_18;
        }
        break;
    case 4:
        if (func_8001B7C4(D_800AE6E4) != 0) {
            goto block_18;
        }
        break;
    case 5:
        if (func_8001B0D4(D_800AE6E4, D_800A6430) != 0) {
            D_800747E4 = 0;
            goto block_18;
        }
        break;
    }
}
