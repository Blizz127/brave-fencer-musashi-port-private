/* Exact retail word export for [8001B3C4,8001B710); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006313A;
extern s32 D_8006313C;
extern s32 D_800747F8;
s32 func_8001A114();                                /* static */
void func_8001B710();                                  /* static */
s32 func_8001B788(s16);                             /* static */
void func_8002D4C8(s32, s32);                            /* static */
s32 func_80034B98(s16);                             /* static */
s32 func_800363CC(s16, void *, s32);                  /* static */
void func_80036D58(s16);                               /* static */
extern s32 *D_80063138;
extern s32 D_800A654C;
extern s32 D_800AE6F4;
extern s32 D_800AE708;
extern s32 D_800AE70C;
extern s32 D_800AE7EC;
extern s32 *D_800AE830;
extern s32 D_800C6D10;
extern s32 D_800C6D34;

void func_8001B3C4(void) {
    s16 temp_v0;
    s16 temp_v0_4;
    s16 var_a0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 var_s1;

    var_s1 = 0;
    switch (D_800AE7EC) {                           /* irregular */
    case 0:
        if (D_800C6D34 == D_800A654C) {
            D_800C6D10 = 1;
            return;
        }
        var_a0 = D_800C6D34 * 6;
        if (*(&D_80063138 + var_a0) == D_800747F8) {
            temp_v0 = *(D_8006313C + var_a0);
            var_a0 = temp_v0;
            if (temp_v0 != 0) {
                func_8002D4C8(var_a0 & 0xFFFF, 0);
                D_800C6D10 = 1;
                D_800A654C = D_800C6D34;
                return;
            }
        }
        if (func_80034B98(var_a0) == 0) {
            temp_v1 = D_800C6D34 * 6;
            if (*(&D_80063138 + temp_v1) < 0) {
                func_80036D58(*(D_8006313A + temp_v1));
                goto block_14;
            }
            if (func_8001B788((s16) D_800C6D34) == 0) {
block_14:
                D_800C6D10 = 1;
                return;
            }
            if ((D_800AE708 == 0) || (*(&D_800AE830 + (*(&D_80063138 + (D_800C6D34 * 6)) * 8)) == D_800AE708)) {
                D_800AE7EC += 1;
                D_800AE708 = *(&D_800AE830 + (*(&D_80063138 + (D_800C6D34 * 6)) * 8));
            case 1:
                temp_v0_2 = D_800C6D34 * 6;
                var_s1 = func_800363CC(*(D_8006313A + temp_v0_2), (*(&D_80063138 + temp_v0_2) * 8) + &D_800AE830, 0x10);
                if (var_s1 == 2) {
                    D_800AE7EC += 1;
                    var_s1 = 0;
                }
            }
            goto block_23;
        }
    default:
block_23:
        if (var_s1 != 0) {
            temp_v0_3 = D_800C6D34 * 6;
            temp_v0_4 = *(D_8006313C + temp_v0_3);
            D_800747F8 = (s32) *(&D_80063138 + temp_v0_3);
            if (temp_v0_4 > 0) {
                func_8002D4C8(temp_v0_4 & 0xFFFF, 0);
                D_800A654C = D_800C6D34;
                if (D_800C6D34 == 0x3D) {
                    func_8001B710();
                }
            }
            D_800AE7EC = 0;
            D_800AE708 = 0;
        }
        D_800C6D10 = var_s1;
        return;
    case 2:
        D_800AE6F4 = 0;
        D_800AE70C = 0;
        D_800AE7EC = 3;
        /* fallthrough */
    case 3:
        if (func_8001A114() != 0) {
            D_800AE7EC = 0;
        }
        goto block_23;
    }
}
