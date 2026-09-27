/* Main-exec range [8001FC08,80020248) from the SLUS executable.
 * SHA256(span)=988ccf15b7f42064a00b3dfc57012efac4690cae0e8e684e0aa78d5076a541e0.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800CAE80(s32 *, void *, s32);                  /* extern */
extern s32 D_80062BA8;
s32 func_80020248(s32 *, s32, void *, void *, s32);       /* static */
void func_80020598(s32 *, s32, void *, void *);              /* static */
s32 func_80020A28(s32 *, s32, void *, void *, s32);       /* static */
void func_80020DA4(void *, s32 *);                     /* static */
void func_80020F34(s32 *, void *);                     /* static */
void func_80021008(s32);                               /* static */
void func_80021050(s32);                               /* static */
void func_8002109C(s32, s32 *);                        /* static */
void func_80021120(s32 *, s32);                        /* static */
s32 func_80021174(s32, s32 *);                      /* static */
void func_800243EC(s32 *, void *, s32);                  /* static */
void func_80027BF0(s32 *, void *, s32);                  /* static */
void func_80052E38(void *);                               /* static */
void func_80052F04(void *);                               /* static */
void func_80054AAC(s32 *, void *, void *);                   /* static */
void func_80055D40(s32 *, void *, s32, s32);             /* static */
void func_80056F18(s32, s32 *, s32);                     /* static */
void func_80057094(s32 *, void *, s32, s32);             /* static */
extern s32 *D_1F800020;
extern s32 *D_80074818;
extern s32 *D_80075018;
extern s32 *D_800A5BD0;
extern s32 *D_800A6518;
extern u16 D_800B9A02;

void func_8001FC08(void *arg0) {
    s32 spD0;
    s32 spC8;
    s32 spC4;
    s32 spC0;
    s32 spB8;
    s32 spA8;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp50;
    s32 sp30;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp18;
    void *var_s0;
    void *var_s0_2;
    void *var_s1;
    void *var_s1_2;
    s32 *var_s3;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_s1;
    s32 temp_s4_2;
    s32 temp_s7;
    s32 temp_v0;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_s2;
    u16 temp_s4;
    u32 var_fp;
    void *temp_s6;
    void *var_s5;

    var_s5 = saved_reg_s5;
    temp_s7 = arg0->unk4;
    temp_s2 = arg0->unk2;
    temp_s4 = arg0->unk2C;
    sp70 = 0;
    spB8 = arg0->unk78;
    temp_s6 = (D_800B9A02 * 0x14) + &D_800A6518;
    spC8 = D_80062BA8;
    if (temp_s4 & 1) {
        arg0->unk2C = (u16) (arg0->unk2C & 0xFFFE);
        sp74 = arg0->unk34;
        sp78 = arg0->unk38;
        sp7C = arg0->unk3C;
        sp80 = arg0->unk40;
        sp84 = arg0->unk44;
        sp88 = arg0->unk48;
        sp8C = arg0->unk4C;
        sp90 = arg0->unk50;
        var_v0 = temp_s4 & 0x20;
    } else {
        func_80020DA4(arg0 + 0x10, &sp74);
        sp88 = (s32) arg0->unk8;
        sp8C = (s32) arg0->unkA;
        sp90 = (s32) arg0->unkC;
        var_v0 = temp_s4 & 0x20;
    }
    spD0 = 0;
    if (var_v0 != 0) {
        spD0 = arg0->unk80;
    }
    if (temp_s4 & 0x80) {
        if (spD0 != 0) {
            spC0 = arg0->unk80 + 0x30;
        } else {
            spC0 = arg0->unk80;
        }
    } else {
        spC0 = 0;
    }
    spC4 = 0;
    var_fp = 0;
    if (temp_s4 & 0x10) {
        func_80020F34(&sp74, arg0 + 0x18);
    }
    func_80054AAC(&sp70, &sp30, &sp50);
    arg0->unk34 = sp74;
    arg0->unk38 = sp78;
    arg0->unk3C = sp7C;
    arg0->unk40 = sp80;
    arg0->unk44 = sp84;
    arg0->unk48 = sp88;
    arg0->unk4C = sp8C;
    arg0->unk50 = sp90;
    arg0->unk54 = sp94;
    arg0->unk58 = sp98;
    arg0->unk5C = sp9C;
    arg0->unk60 = spA0;
    arg0->unk64 = spA4;
    arg0->unk68 = spA8;
    arg0->unk6C = spAC;
    arg0->unk70 = spB0;
    var_s3 = arg0->unk24;
    if (var_s3 != 0) {
        temp_s1 = arg0->unk20;
        if ((temp_s1 != 0) && (func_80021174(arg0->unk28, &spA8) != 0)) {
            if ((temp_s2 == 1) || (temp_s2 == 6)) {
                sp18 = temp_s7;
                sp28 = 0;
                var_s5 = (arg0->unk2E * 0x14) + &D_800A5BD0;
            } else {
                sp18 = temp_s7;
            }
            if (spD0 != 0) {
                func_80021008(spD0);
            }
            if (!(temp_s1 & 0x01000000) && !(temp_s4 & 0x40)) {
                var_s1 = &D_1F800020;
                if (func_80020248(var_s3, temp_s1, &sp30, &sp50, temp_s7 & 0x40) == 0) {
                    var_s1 = &D_80074818;
                    var_s0 = &D_80075018;
                } else {
                    var_s0 = (void *)0x1F8000E0;
                }
                var_a0 = *var_s3;
                if (var_a0 != 0) {
                    do {
                        if ((var_a0 & 0x7F000000) != 0x01000000) {
                            func_80056F18((var_a0 & 0x80FFFFFF) + 0xC, &sp18, 0);
                            if (!(temp_s7 & 0x40)) {
                                func_80052F04(var_s1);
                            }
                            func_80052E38(var_s0);
                            if (spC0 != 0) {
                                func_8002109C(spC4, &spC0);
                            }
                            if (temp_s2 == 0) {
                                func_80057094(&sp18, temp_s6, 0, spC8);
                            } else if (temp_s2 == 5) {
                                func_800243EC(&sp18, temp_s6, 0);
                            }
                        }
                        if (spC0 != 0) {
                            func_80021120(&spC4, spC0);
                        }
                        var_s3 += 4;
                        var_a0 = *var_s3;
                        var_s0 += 0x20;
                    } while (var_a0 != 0);
                }
            } else {
                temp_a1 = temp_s1 & 0xFEFFFFFF;
                if (temp_s4 & 0x40) {
                    func_80020598(var_s3, temp_a1, &sp30, &sp50);
                    goto block_43;
                }
                var_s1_2 = &D_1F800020;
                if (func_80020A28(var_s3, temp_a1, &sp30, &sp50, temp_s7 & 0x40) == 0) {
block_43:
                    var_s1_2 = &D_80074818;
                    var_s0_2 = &D_80075018;
                } else {
                    var_s0_2 = (void *)0x1F8000E0;
                }
                var_a0_2 = *var_s3;
                if (var_a0_2 != 0) {
                    temp_s4_2 = temp_s4 & 0x40;
                    do {
                        temp_a0 = var_a0_2 & 0x80FFFFFF;
                        if ((var_a0_2 & 0x7F000000) == 0x01000000) {
                            if ((temp_s2 == 1) || (temp_s2 == 6)) {
                                var_s5 += 0x14;
                            }
                        } else {
                            if ((temp_s2 == 0) || (temp_s2 == 5)) {
                                func_80056F18(temp_a0 + 0xC, &sp18, 0);
                                var_v0_2 = temp_s7 & 0x40;
                            } else {
                                if ((temp_s2 == 1) || (temp_s2 == 6)) {
                                    sp20 = var_s5->unk8;
                                    temp_v0 = var_s5->unkC;
                                    var_s5 += 0x14;
                                    sp24 = temp_v0;
                                } else {
                                    sp20 = temp_a0;
                                }
                                var_v0_2 = temp_s7 & 0x40;
                            }
                            if (var_v0_2 == 0) {
                                func_80052F04(var_s1_2);
                            }
                            func_80052E38(var_s0_2);
                            if ((temp_s4_2 == 0) && (spC0 != 0)) {
                                func_8002109C(spC4, &spC0);
                            }
                            if (temp_s2 == 0) {
                                func_80057094(&sp18, temp_s6, 0, spC8);
                            } else if (temp_s2 == 1) {
                                if (var_fp < 2U) {
                                    func_80027BF0(&sp18, temp_s6, 0);
                                    var_fp += 1;
                                } else {
                                    func_80055D40(&sp18, temp_s6, 0, spC8);
                                }
                            } else if (temp_s2 == 6) {
                                func_800CAE80(&sp18, temp_s6, 0);
                            } else if (temp_s2 == 5) {
                                func_800243EC(&sp18, temp_s6, 0);
                            }
                        }
                        if ((temp_s4_2 == 0) && (spC0 != 0)) {
                            func_80021120(&spC4, spC0);
                        }
                        var_s3 += 4;
                        var_a0_2 = *var_s3;
                        var_s0_2 += 0x20;
                    } while (var_a0_2 != 0);
                }
            }
            if (spD0 != 0) {
                func_80021050(spD0);
            }
        }
    }
}
