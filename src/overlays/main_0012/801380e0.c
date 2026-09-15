/* Overlay range [801380E0,801387B8) from MAIN.CD member 0012.
 * SHA256(span)=6d66675bee4ac82947d39a9b3c91f618eb998e5840e36cccdb4ac1aa4e9dbf5f.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001931C(s32);                         /* extern */
void func_8001AAD0(s32, s16);                    /* extern */
s32 func_8001B22C();                                /* extern */
void func_80029124(s32, s32);                /* extern */
s32 func_80029178(s32, u8);                         /* extern */
s32 func_800CF864(u16, u8);                         /* extern */
void func_80138AB4(void *, u8);                  /* static */
s32 func_80138C60(void *, u8);                      /* static */
void func_80138D58(void *, u8);                  /* static */
s32 func_80138DE0(void *, u8, u8);                  /* static */
void func_801391F0(void *, u8);                  /* static */
void func_80139220(void *, u8);                  /* static */
void func_80139788(s32);                         /* static */
void func_80139914(void *);                      /* static */
void func_80139A8C(void *);                      /* static */
void func_80139B18(void *);                      /* static */
extern s16 D_8012752C;
extern s32 *D_8012752E;
extern s32 *D_80127530;

void func_801380E0(void *arg0) {
    s32 var_a1;
    s32 temp_a0_2;
    s32 temp_v1;
    s32 var_s3;
    s32 var_s4;
    s32 var_v0;
    s32 var_v0_3;
    s32 var_v1;
    s8 var_v0_4;
    u16 *var_s0;
    u16 temp_a0;
    u16 temp_a0_3;
    u16 temp_v0_4;
    u16 temp_v0_5;
    u16 var_v0_2;
    u16 var_v0_5;
    u8 temp_a1;
    u8 temp_s2;
    u8 temp_v0;
    u8 var_a0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_6;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0xC);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8 *, 0xC) = (u8) (temp_v0 - 1);
        goto block_88;
    }
loop_5:
    var_s4 = 0;
    if (M2C_FIELD(arg0, s32 *, 8) & 0x400) {
        var_s3 = *(&D_80127530 + (M2C_FIELD(arg0, u16 *, 0x4A) * 4));
        var_s0 = arg0 + 0x44;
    } else {
        var_s0 = arg0 + 0x10;
        var_s3 = M2C_FIELD(arg0, s32 *, 0);
    }
    temp_a0 = *var_s0;
    temp_v0_2 = temp_a0 + var_s3;
    temp_a1 = M2C_FIELD(temp_v0_2, u8 *, 0);
    temp_s2 = M2C_FIELD(temp_v0_2, u8 *, 1);
    if (temp_a1 >= 0x20U) {
        var_s4 = func_80138DE0(arg0, temp_a1, temp_s2);
        if (!(M2C_FIELD(arg0, s32 *, 8) & 0x80220)) {
            var_s4 = 0;
        }
        goto block_85;
    }
    switch (temp_a1) {                              /* irregular */
    case 10:
        func_80139220(arg0, temp_a1);
        *var_s0 += 1;
        var_v0 = M2C_FIELD(arg0, s32 *, 8);
        var_v1 = 0xFFF7FFFF;
block_29:
        M2C_FIELD(arg0, s32 *, 8) = (s32) (var_v0 & var_v1);
block_85:
        if (var_s4 == 0) {
            if (M2C_FIELD(arg0, u8 *, 0xC) == 0) {
                M2C_FIELD(arg0, u8 *, 0xC) = (u8) M2C_FIELD(arg0, u8 *, 0xD);
            }
block_88:
            func_80139A8C(arg0);
            func_80139B18(arg0);
            return;
        }
        goto loop_5;
    case 7:
        if (M2C_FIELD(arg0, s32 *, 8) & 0x10000) {
            var_s4 = 1;
        } else {
            M2C_FIELD(arg0, s16 *, 4) = 3;
        }
        var_v0_2 = *var_s0 + 1;
block_73:
        *var_s0 = var_v0_2;
        goto block_85;
    case 8:
        func_801391F0(arg0, temp_a1);
        var_v0_2 = *var_s0 + 1;
        goto block_73;
    case 1:
        M2C_FIELD(arg0, u8 *, 0x23) = temp_s2;
block_51:
        var_s4 = 1;
        *var_s0 += 2;
        goto block_85;
    case 2:
        M2C_FIELD(arg0, u8 *, 0x22) = temp_s2;
        M2C_FIELD(arg0, u8 *, 0x20) = (u8) M2C_FIELD((*var_s0 + var_s3), u8 *, 2);
        *var_s0 += 3;
        if (func_80138C60(arg0, temp_a1) != 0) {
            M2C_FIELD(arg0, s16 *, 4) = 9;
            if (*(s32 *) (var_s3 + *var_s0) == 5) {
                M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) | 0x4000);
                var_v0_2 = *var_s0 + 1;
                goto block_73;
            }
            goto block_85;
        }
        func_80139914(arg0);
        return;
    case 22:
        var_v0_3 = (M2C_FIELD(arg0, s32 *, 8) & ~0x20) | 0x4001;
block_72:
        M2C_FIELD(arg0, s32 *, 8) = var_v0_3;
        var_s4 = 1;
        var_v0_2 = *var_s0 + 1;
        goto block_73;
    case 5:
        var_v0_3 = M2C_FIELD(arg0, s32 *, 8) | 0x4000;
        goto block_72;
    case 4:
        M2C_FIELD(arg0, u8 *, 0xD) = temp_s2;
        goto block_51;
    case 3:
        if (!(M2C_FIELD(arg0, s32 *, 8) & 0x20000)) {
            M2C_FIELD(arg0, s16 *, 4) = 0xB;
            var_v1 = -0x21;
            M2C_FIELD(arg0, u8 *, 0xD) = temp_s2;
            var_v0 = M2C_FIELD(arg0, s32 *, 8) | 0x8000;
            goto block_29;
        }
        goto block_51;
        goto block_85;
    case 6:
        M2C_FIELD(arg0, s16 *, 4) = 4;
        var_v0_2 = *var_s0 + 1;
        goto block_73;
    case 11:
        if ((M2C_FIELD(&D_8012752E, s16 *, 0) != 0) || (M2C_FIELD(arg0, s32 *, 8) & 0x20) || (func_800CF864(temp_a0, temp_a1) == 0)) {
            var_s4 = 1;
            *var_s0 += 4;
        } else {
            temp_v0_3 = *var_s0 + var_s3;
            M2C_FIELD(&D_8012752E, s16 *, -2) = (s16) (M2C_FIELD(temp_v0_3, u8 *, 2) + (M2C_FIELD(temp_v0_3, u8 *, 3) << 8));
            *var_s0 += 4;
            M2C_FIELD(arg0, s32 *, 8) = (s32) ((M2C_FIELD(arg0, s32 *, 8) & 0xFFF9FFDF) | 0x10000);
            if (M2C_FIELD(&D_8012752E, s16 *, -2) != 0) {
                func_8001AAD0(temp_s2 & 0x7F, M2C_FIELD(&D_8012752E, s16 *, -2));
                if (temp_s2 & 0x80) {
                    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) | 0x40000);
                }
                if ((*(s32 *) (var_s3 + *var_s0) == 2) || (M2C_FIELD(arg0, s32 *, 8) & 0x40000)) {
                    var_s4 = 1;
                } else {
                    M2C_FIELD(arg0, s16 *, 4) = 0x10;
                }
                if (func_8001B22C() == 0) {
                    temp_a0_2 = M2C_FIELD(arg0, s32 *, 8);
                    if (temp_a0_2 & 1) {
                        func_8001931C(temp_a0_2);
                    } else {
                        M2C_FIELD(arg0, s32 *, 8) = (s32) ((temp_a0_2 & 0xFFFEFFFF) | 0x20020);
                        func_80139788(temp_a0_2);
                    }
                    M2C_FIELD(arg0, s16 *, 4) = 2;
                }
            } else {
block_79:
                var_s4 = 1;
            }
        }
        goto block_85;
    case 12:
        M2C_FIELD(arg0, s16 *, 4) = 6;
        var_v0_4 = 2;
block_49:
        M2C_FIELD(arg0, s8 *, 0x21) = var_v0_4;
        *var_s0 += 1;
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) | 0x4300);
        goto block_85;
    case 13:
        M2C_FIELD(arg0, s16 *, 4) = 6;
        var_v0_4 = 3;
        goto block_49;
    case 9:
        func_80138D58(arg0, temp_s2);
        goto block_51;
    case 14:
        M2C_FIELD(arg0, s16 *, 4) = 8;
        M2C_FIELD(arg0, s16 *, 0x44) = 0;
        func_80138AB4(arg0, temp_a1);
        var_v0_2 = *var_s0 + 1;
        goto block_73;
    case 15:
        M2C_FIELD(arg0, s16 *, 0x44) = 0;
        var_v0_3 = M2C_FIELD(arg0, s32 *, 8) | 0x400;
        goto block_72;
    case 16:
        var_a0 = M2C_FIELD((*var_s0 + var_s3), u8 *, 2);
        var_a1 = 1;
block_55:
        func_80029124(temp_s2 | (var_a0 << 8), var_a1);
block_65:
        var_s4 = 1;
        *var_s0 += 3;
        goto block_85;
    case 17:
        var_a0 = M2C_FIELD((*var_s0 + var_s3), u8 *, 2);
        var_a1 = 0;
        goto block_55;
    case 18:
        if (func_80029178(temp_s2 | (M2C_FIELD((*var_s0 + var_s3), u8 *, 2) << 8), temp_a1) & 0xFF) {
            temp_v0_4 = *var_s0;
            *var_s0 = M2C_FIELD((temp_v0_4 + var_s3), u8 *, 3) + (temp_v0_4 + 4);
        } else {
            var_v0_5 = *var_s0 + 4;
block_78:
            *var_s0 = var_v0_5;
        }
        goto block_79;
    case 19:
        if (!(func_80029178(temp_s2 | (M2C_FIELD((*var_s0 + var_s3), u8 *, 2) << 8), temp_a1) & 0xFF)) {
            temp_v0_5 = *var_s0;
            *var_s0 = M2C_FIELD((temp_v0_5 + var_s3), u8 *, 3) + (temp_v0_5 + 4);
        } else {
            var_v0_5 = *var_s0 + 4;
            goto block_78;
        }
        goto block_79;
    case 20:
        if (!(M2C_FIELD(arg0, s32 *, 8) & 0x20000)) {
            temp_v0_6 = *var_s0 + var_s3;
            M2C_FIELD(arg0, u16 *, 0xE) = (u16) (M2C_FIELD(temp_v0_6, u8 *, 1) + (M2C_FIELD(temp_v0_6, u8 *, 2) << 8));
        }
        goto block_65;
    case 21:
        if (M2C_FIELD(arg0, u16 *, 0xE) != 0) {
            M2C_FIELD(arg0, s16 *, 4) = 0xF;
        } else {
            var_s4 = 1;
        }
        var_v0_2 = *var_s0 + 1;
        goto block_73;
    case 23:
        var_v0_3 = M2C_FIELD(arg0, s32 *, 8) | 2;
        goto block_72;
    case 24:
        var_v0_3 = M2C_FIELD(arg0, s32 *, 8) | 0x80000;
        goto block_72;
    case 25:
        *var_s0 += 1;
        if ((M2C_FIELD(arg0, s32 *, 8) & 0x10000) && (D_8012752C != 0)) {
            M2C_FIELD(arg0, s16 *, 4) = 0x10;
        } else {
            goto block_79;
        }
        goto block_85;
    default:
        var_v0_5 = temp_a0 + 1;
        goto block_78;
    case 0:
        temp_v1 = M2C_FIELD(arg0, s32 *, 8);
        if (temp_v1 & 0x400) {
            temp_a0_3 = M2C_FIELD(arg0, u16 *, 0x4A);
            M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_v1 & ~0x400);
            if (temp_a0_3 < 3U) {
                M2C_FIELD(arg0, u16 *, 0x4A) = (u16) (temp_a0_3 + 1);
            }
            goto block_85;
        }
        if (!(temp_v1 & 0x2000)) {
            M2C_FIELD(arg0, s16 *, 4) = 0xA;
            return;
        }
        M2C_FIELD(arg0, s16 *, 4) = 0xD;
        return;
    }
}
