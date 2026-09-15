/* Exact retail word export for [8001ACF0,8001AE90); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006313C[];
extern s32 D_800747E4;
extern s32 D_800747E8;
extern s32 D_800747F0;
extern s32 D_800747F4;
extern s32 D_800747F8;
void func_8002D4C8(s32, s32);                /* static */
extern s32 *D_80063138;
extern s32 D_800A6430;
extern s32 D_800A654C;
extern s32 D_800A6550;
extern s32 D_800AE640;
extern s32 *D_800AE6E4;
extern s32 D_800BA1B4;
extern s32 D_800BA318;
extern s32 D_800C6D2C;

s32 func_8001ACF0(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4) {
    s16 temp_v0;
    s32 temp_a0;

    D_800747F0 = arg0;
    if (arg0 != 1) {
        if (arg0 < 2) {
            if (arg0 != 0) {
                return 0;
            }
            D_800C6D2C = arg1;
            D_800AE6E4 = arg2;
            D_800BA318 = arg3;
            D_800A6550 = arg4;
            D_800BA1B4 = 1;
            D_800747F4 = (s32) *arg2;
            return 0;
        }
        switch (arg0) {                             /* irregular */
        case 2:
            D_800AE6E4 = arg2;
            D_800BA1B4 = 4;
            D_800747F4 = (s32) *arg2;
            return 0;
        case 3:
            D_800A6430 = arg1;
            D_800AE6E4 = arg2;
            D_800747F4 = arg1;
            D_800BA1B4 = 5;
            D_800747E4 = 0;
            D_800747E8 = 1;
            return 0;
        default:
            return 0;
        }
    } else {
        D_800BA1B4 = 2;
        if (arg1 == D_800A654C) {
            goto block_9;
        }
        temp_a0 = arg1 * 6;
        if (*(&D_80063138 + temp_a0) == D_800747F8) {
            temp_v0 = *(D_8006313C + temp_a0);
            if (temp_v0 != 0) {
                func_8002D4C8(temp_v0 & 0xFFFF, 0);
                D_800A654C = arg1;
                return 1;
            }
block_9:
            return 1;
        }
        D_800AE640 = arg1;
        D_800747F4 = arg1;
        return 0;
    }
}
