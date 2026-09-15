/* Exact retail word export [80046D1C,8004768C); verified against pinned EXE and asm. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8006D058;
extern s32 *D_8006D060;
extern s32 *D_8006D064;
extern s32 *D_8006D068;
extern s32 *D_8006D06C;
extern s32 *D_8006D078;
extern s32 *D_8006D088;
extern s32 D_8006D0A0;
s32 func_8004357C(s32, u8 *);                         /* static */
void func_800469CC();                                  /* static */
void func_80046BFC(s32, s32);                          /* static */
void func_8004768C(u16 *, s32, s32, s32);                  /* static */
void func_800476C0(s32, u16 *, s32, s32, s32, s32, s32);     /* static */
extern u16 *D_80078808;
extern u32 D_80078E38;
extern s16 D_800A2B94;
extern s32 D_800A2B9C;
extern s32 D_800A2BA4;
extern s32 (*D_800A5E84)();
extern s32 D_800A5F1C;
extern s32 D_800A6424;
extern s32 D_800A642C;
extern s32 D_800A6608;
extern s32 D_800AE644;
extern s32 D_800BA0D4;
extern s32 D_800C6D38;
extern s32 D_800C6D3C;
extern s32 D_800C7C78;
extern u32 D_800C7C84;
extern s32 D_800C7C8C;
extern u16 *D_800C7C90;
extern u16 *D_800C7C94;
extern s32 D_800C7F00;

void func_80046D1C(void) {
    u8 sp30;
    s32 sp2C;
    u8 sp28;
    s16 sp24;
    u16 sp22;
    s32 temp_v0_2;
    s32 var_t0;
    u16 *temp_v1;
    u16 *var_a0;
    u16 *var_a1;
    u32 temp_v0;
    u32 var_v1_2;
    u32 var_v1_3;
    u8 *var_v1;

    if (D_800AE644 != 1) {
        if ((D_800A2B9C != 0) && (*D_8006D078 & 0x01000000)) {
            D_800A5F1C = 1;
            if (D_800C7C78 != 0) {
                D_800BA0D4 += 1;
            }
            D_8006D0A0 = 1;
            return;
        }
        if (func_8004357C(1, &sp30) != 5) {
            sp22 = (u16) sp30;
            sp24 = (s16) sp31;
            if (sp30 & 4) {
                D_8006D0A0 = 3;
                return;
            }
            temp_v1 = D_800C7C94 + (D_800C6D38 << 5);
            D_80078808 = temp_v1;
            if (*temp_v1 != 0) {
                if (D_800C7C78 != 0) {
                    D_800BA0D4 += 1;
                }
                D_8006D0A0 = 4;
                return;
            }
            *D_8006D058 = 0;
            *D_8006D064 = 0;
            *D_8006D058 = 0;
            *D_8006D064 = 0x80;
            *D_8006D068 = 0x20943;
            *D_8006D06C = 0x1323;
            if (D_800A2BA4 == 0) {
                var_v1 = &sp28;
                do {
                    *var_v1 = *D_8006D060;
                    var_v1 += 1;
                } while ((u32) var_v1 < (u32) &sp2C);
                var_v1_2 = 0;
                do {
                    var_v1_2 += 1;
                } while (var_v1_2 < 8U);
            }
            if (D_800C7C78 != 0) {
                func_8004768C(D_80078808, D_800C7C78 + (D_800BA0D4 << 0xB), 8, 0);
            } else {
                func_800476C0(3, D_80078808, 0, 8, 0x11000000, 0, 0);
            }
            if (*D_8006D088 & 0x01000000) {
                do {

                } while (*D_8006D088 & 0x01000000);
            }
            D_80078808->unk1F = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            *D_8006D068 = 0x20843;
            *D_8006D06C = 0x1325;
            if ((D_800C7C8C == 1) && (D_800A642C != 0)) {
                if (D_800A642C != D_80078808->unk8) {
                    D_80078808->unk0 = 0;
                    if (D_800C7C78 != 0) {
                        D_800BA0D4 += 1;
                    }
                } else {
                    D_800C7C8C = 0;
                    goto block_30;
                }
            } else {
block_30:
                if (((D_80078808->unk0 & 0xFFFF) != 0x160) || ((((u16) D_80078808->unk2 >> 0xA) & 0x1F) != D_800A6608)) {
                    if (D_800C7C78 != 0) {
                        D_800BA0D4 = 0;
                    }
                    D_8006D0A0 = 5;
                    D_80078808->unk0 = 0;
                    return;
                }
                if ((D_800A2B94 != D_80078808->unk4) || ((D_80078E38 != 0) && (D_80078E38 != D_80078808->unk8))) {
                    D_80078E38 = 0;
                    D_800A2B94 = 0;
                    func_80046BFC(D_800C6D3C, D_800C6D38 - D_800C6D3C);
                    D_800C6D38 = D_800C6D3C;
                    D_80078808->unk0 = 0;
                    if (D_800C7C78 != 0) {
                        D_800BA0D4 += 1;
                    }
                    D_8006D0A0 = 6;
                    return;
                }
                if (D_80078808->unk4 == 0) {
                    D_800A2B94 = 0;
                    temp_v0 = D_80078808->unk8 & 0xFFFF;
                    D_80078E38 = temp_v0;
                    if ((D_800C7C84 != 0) && (temp_v0 >= (u32) D_800C7C84)) {
                        D_80078E38 = 0;
                        D_800A2B94 = 0;
                        func_80046BFC(D_800C6D3C, D_800C6D38 - D_800C6D3C);
                        D_800C6D38 = D_800C6D3C;
                        D_80078808->unk0 = 0;
                        D_800C7C8C = 1;
                        if (D_800A5E84 != 0) {
                            D_800A5E84();
                        }
                        if (D_800C7C78 != 0) {
                            D_800BA0D4 += 1;
                        }
                        D_8006D0A0 = 7;
                        return;
                    }
                    if ((u32) ((D_800C7F00 - D_800C6D38) - 1) < (u16) D_80078808->unk6) {
                        if (D_800C7C84 == 0) {
                            D_80078808->unk0 = 1;
                            D_800C7C8C = 1;
                            if (D_800A5E84 != 0) {
                                D_800A5E84(D_80078808);
                            }
                            if (D_800C7C78 != 0) {
                                D_800BA0D4 += 1;
                            }
                            D_8006D0A0 = 8;
                            return;
                        }
                        if ((s16) *D_800C7C94 != 0) {
                            D_80078808->unk0 = 0;
                            if (D_800C7C78 != 0) {
                                D_800BA0D4 += 1;
                            }
                            D_8006D0A0 = 9;
                            return;
                        }
                        D_80078808->unk0 = 1;
                        var_a1 = D_800C7C94;
                        var_a0 = D_80078808;
                        var_v1_3 = 0;
                        D_800C6D38 = 0;
                        do {
                            temp_v0_2 = *var_a0;
                            var_a0 += 4;
                            var_v1_3 += 1;
                            *var_a1 = temp_v0_2;
                            var_a1 += 4;
                        } while (var_v1_3 < 8U);
                        D_80078808 = D_800C7C94;
                        goto block_64;
                    }
block_64:
                    D_800C6D3C = D_800C6D38;
                    goto block_65;
                }
block_65:
                D_8006D0A0 = 0xA;
                D_800A2B94 = (u16) D_800A2B94 + 1;
                D_800C7C90 = D_800C7C94 + (D_800C7F00 << 5) + (D_800C6D38 * 0x7E0);
                var_t0 = 0x11000000;
                if (D_800A2B9C != 0) {
                    *D_8006D068 = 0x20943;
                    *D_8006D06C = 0x1323;
                } else {
                    var_t0 = 0x11400100;
                    *D_8006D068 = 0x21020843;
                }
                if ((D_80078808->unk6 - 1) == D_80078808->unk4) {
                    D_800AE644 = 1;
                    if (D_800C7C78 != 0) {
                        func_8004768C(D_800C7C90, D_800C7C78 + (D_800BA0D4 << 0xB) + 0x20, 0x1F8, 1);
                        D_800BA0D4 += 1;
                    } else {
                        func_800476C0(3, D_800C7C90, 0, 0x1F8, var_t0, 1, 0);
                    }
                    D_800A2B94 = 0;
                    D_80078E38 = 0;
                    D_800A6608 = D_800A6424;
                } else if (D_800C7C78 != 0) {
                    func_8004768C(D_800C7C90, D_800C7C78 + (D_800BA0D4 << 0xB) + 0x20, 0x1F8, 0);
                    D_800BA0D4 += 1;
                } else {
                    func_800476C0(3, D_800C7C90, 0, 0x1F8, var_t0, 0, 0);
                }
                *D_8006D06C = 0x1325;
                D_80078808->unk0 = 3;
                D_800C6D38 += 1;
                if ((D_800C7C78 != 0) && (D_800AE644 != 0)) {
                    func_800469CC();
                }
            }
        }
    }
}
