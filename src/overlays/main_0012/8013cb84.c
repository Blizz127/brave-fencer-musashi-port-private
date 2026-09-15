/* Overlay range [8013CB84,8013CF68) from MAIN.CD member 0012.
 * SHA256(span)=98173c3cb468079b71fa4ea282b5abd3bc843494f58ad3f59ede091c8e3cc4ca.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017ECB8;
extern s32 D_8017ECE8;
extern s32 D_8017ECEC;
extern s32 D_8017ECF0;
extern s32 D_801841B0;
extern s32 D_801841B4;
extern s32 D_801841B8;
extern s32 D_801841BC;
extern s32 D_801841C0;
extern s32 D_801841C4;
extern s32 D_801841D0;
extern s32 D_801841D8;
extern s32 D_80185B31;
extern s32 D_80185B64;
extern s32 D_80185B70;
extern s32 D_80185BEC;
extern s32 D_80185BF0;
extern s32 D_80185C7E;
void func_8013CF68();                                  /* static */
void func_8013D178();                                  /* static */
void func_8013D330();                                  /* static */
void func_8013D9B0(u8, s8, void *);                       /* static */
void func_8013DBE4(u8, s8, void *);                       /* static */
extern u8 D_80078EAF;
extern s16 D_800B9A08;
extern s32 D_80185BC8;

void func_8013CB84(s8 arg1, void *arg2) {
    void *var_a2;
    s16 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s8 var_a1;
    u8 temp_s0;
    u8 var_a0;

    var_a1 = arg1;
    var_a2 = arg2;
    temp_s1 = D_800B9A08;
    temp_s0 = D_80078EAF;
    D_80185BF0 = 0;
    if ((D_801841C0 == 0) && (temp_s0 != D_801841B8)) {
        temp_v0 = temp_s0 * 0xC;
        D_801841B8 = (s32) temp_s0;
        D_80185B31 = (s8) *(D_8017ECF0 + temp_v0);
        D_80185C7E = (s8) *(D_8017ECE8 + temp_v0);
        D_80185BEC = (s8) *(D_8017ECEC + temp_v0);
        var_a2 = &D_80185BC8;
        var_a1 = *(D_8017ECB8 + (temp_s0 * 9));
        D_80185BC8.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        D_80185BC8.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        D_80185BC8.unk8 = var_a1;
        D_801841BC = 1;
        D_801841B0 = 1;
        if (D_801841D0 & 2) {
            if (temp_s0 == 4) {
                D_80185B64 = 0x100;
                D_80185B70 = 0x80;
            }
            if (temp_s0 == 0) {
                D_80185B64 = 0x100;
                D_80185B70 = 0;
            }
        }
    }
    if (D_801841BC != 0) {
        temp_v0_2 = D_801841B0 - 1;
        D_801841B0 = temp_v0_2;
        if (temp_v0_2 == 0) {
            if (D_801841C0 == 0) {
                if ((D_801841D0 & 2) && (temp_s0 == 4)) {
                    var_a0 = 6;
                    if (D_801841D8 != 0) {
                        func_8013DBE4(6U, var_a1, var_a2);
                    } else {
                        goto block_16;
                    }
                } else {
                    var_a0 = temp_s0;
                    if (D_801841D8 != 0) {
                        func_8013DBE4(temp_s0, var_a1, var_a2);
                    } else {
block_16:
                        func_8013D9B0(var_a0, var_a1, var_a2);
                    }
                }
                func_8013D330();
                func_8013D178();
                func_8013CF68();
                D_801841B0 = 2;
                if (D_801841BC != 0) {
                    if (D_801841D0 & 2) {
                        if (temp_s0 == 4) {
                            temp_v0_3 = D_80185B70 - 8;
                            D_80185B70 = temp_v0_3;
                            if (temp_v0_3 < 0) {
                                D_80185B70 = 0;
                            }
                        } else if (temp_s0 == 0) {
                            temp_v0_4 = D_80185B70 + 0x20;
                            D_80185B70 = temp_v0_4;
                            if (temp_v0_4 >= 0x81) {
                                D_80185B70 = 0x80;
                            }
                        }
                    }
                } else if (D_801841D0 & 2) {
                    if (temp_s0 == 4) {
                        D_80185B70 = 0;
                    }
                    if (temp_s0 == 0) {
                        D_80185B70 = 0x80;
                    }
                }
            } else {
                if (D_801841D8 != 0) {
                    func_8013DBE4(5U, var_a1, var_a2);
                } else {
                    func_8013D9B0(5U, var_a1, var_a2);
                }
                D_801841B0 = 1;
            }
        }
    }
    D_801841C4 = 0;
    if (temp_s1 == 0x1010) {
        if (temp_s0 == 3) {
            if (D_801841BC != 0) {
                D_801841C4 = (s32) D_801841B4;
                return;
            }
            D_801841C4 = 0x1F;
            return;
        }
        if (temp_s0 == 4) {
            if (D_801841BC != 0) {
                D_801841C4 = (s32) (0x1F - D_801841B4);
                return;
            }
            D_801841C4 = 0;
        }
    }
}
