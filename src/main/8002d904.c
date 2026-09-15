/* Exact retail word export for [8002D904,8002DC68); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800652F0;
extern s32 D_80065438;
extern s32 D_80068B5E;
extern s32 D_80068B62;
extern s32 D_80068B66;
void func_8002EE64();                                  /* static */
void func_8003819C(s16, s32, s32, s32);                      /* static */
u16 func_80038210(s32, s32, s32, u16);              /* static */
void func_80038308(s16);                               /* static */
void func_8003834C(s16, s16, s32);                     /* static */
void func_80038638(s16, s32);                            /* static */
extern s32 *D_80068B5C;
extern s32 *D_80068B60;
extern s32 D_800760E0;
extern s32 *D_800A4642;
extern s32 D_800A4E7C;
extern u16 D_800A4E84;
extern u16 D_800A4E86;
extern s16 D_800A4E8A;
extern s16 D_800A4E8C;
extern u16 D_800A4E8E;
extern u16 D_800A4E9A;
extern u16 D_800A4EA0;
extern u16 D_800A4EA2;
extern u8 D_800A4F1C;
extern u8 D_800A4F1E;

void func_8002D904(s32 arg0) {
    s16 temp_s0;
    s16 temp_v0;
    s16 temp_v0_2;
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_s1;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a1;
    s32 var_v0;
    u16 temp_a1;
    u16 temp_v0_4;
    u16 temp_v0_5;

    func_8002EE64();
    temp_s1 = arg0 & 0xFFFF;
    temp_s0 = temp_s1 - 0x100;
    temp_a0 = temp_s0 * 0x10;
    temp_v0 = *(&D_800A4642 + (*(&D_80068B5C + temp_a0) * 0x18));
    if ((temp_v0 >= 0) && (D_800A4E8E & 0x20) && (D_800A4F1E == 0)) {
        var_v0 = temp_s0 * 0x10;
        if (temp_s1 == 0x18E) {
            var_a0 = D_800760E0;
            goto block_10;
        }
        temp_v0_2 = *(D_80068B62 + temp_a0);
        if (temp_v0_2 != 0) {
            temp_v0_3 = *((temp_v0_2 * 4) + D_800A4E7C);
            if (temp_v0_3 != 0) {
                var_a0 = D_800A4E7C + temp_v0_3 + 4;
                goto block_9;
            }
        } else {
            var_a0 = D_800A4E7C + 0x10;
block_9:
            var_v0 = temp_s0 * 0x10;
block_10:
            if (D_800A4EA2 & 4) {
                var_a1 = temp_v0 << 0x10;
                if (D_800A4EA0 == temp_s0) {
                    temp_v0_4 = D_800A4EA2 | 4;
                    D_800A4EA0 = 0;
                    D_800A4E8E = D_800A4EA2;
                    D_800A4EA2 = 0;
                    D_800A4E8E = temp_v0_4;
                    D_800A4E8C = temp_s0;
                    D_800A4E8A = 0;
                    D_800A4E86 = D_800A4E9A;
                    D_800A4E84 = *(D_80068B5E + ((temp_s0 & 0xFFFF) * 0x10));
                    func_8003819C((s16) D_800A4E9A, 0, 0x4000, 0x111);
                    func_8003834C((s16) D_800A4E86, (s16) D_800A4E84);
                    goto block_26;
                }
                goto block_14;
            }
            var_a1 = temp_v0 << 0x10;
block_14:
            temp_v0_5 = func_80038210(var_a0, var_a1 >> 0x10, *(D_800652F0 + (*(D_80065438 + (*(&D_80068B60 + var_v0) * 2)) * 4)), D_800A4EA2);
            D_800A4E86 = temp_v0_5;
            if ((s16) temp_v0_5 != -1) {
                if ((arg0 & 0xFFFF) == 0x134) {
                    if (!(D_800A4F1C & 2)) {
                        func_80038638((s16) temp_v0_5, 4);
                    }
                    if (!(D_800A4F1C & 4)) {
                        func_80038638((s16) D_800A4E86, 5);
                        func_80038638((s16) D_800A4E86, 6);
                        func_80038638((s16) D_800A4E86, 7);
                    }
                    if (!(D_800A4F1C & 8)) {
                        func_80038638((s16) D_800A4E86, 8);
                    }
                }
                temp_v1 = temp_s0 * 0x10;
                temp_a2 = D_800A4E8E & 0x20;
                temp_a1 = temp_a2 | 4;
                D_800A4E8E = temp_a1;
                D_800A4E8C = temp_s0;
                D_800A4E84 = *(D_80068B5E + temp_v1);
                if (*(D_80068B66 + temp_v1) & 1) {
                    D_800A4E8E = temp_a2 | 0x104;
                } else {
                    D_800A4E8E = temp_a1;
                }
                func_8003834C((s16) D_800A4E86, (s16) D_800A4E84, temp_a2);
                D_800A4E8A = 0;
block_26:
                func_80038308((s16) D_800A4E86);
                D_800A4E8E |= 9;
            }
        }
    }
}
