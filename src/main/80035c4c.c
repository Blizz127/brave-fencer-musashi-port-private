/* Main-exec range [80035C4C,8003602C) from the SLUS executable.
 * SHA256(span)=4650693379b42fe7d19748b1a913437b52643c4aae0e494fe705cf40eb3f5b83.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006AEEC;
extern s32 func_80036130;
void func_800361CC(s32 (*)());               /* static */
void func_8003621C();                            /* static */
void func_8003D650(s32, s32, s32);   /* static */
void func_8003EDE8(s32, s32, s32);           /* static */
s32 func_80043410();                                /* static */
s32 func_80043420();                                /* static */
s32 func_8004355C(s32, u8 *);                   /* static */
void func_800435CC(s32, s8 *, s32);      /* static */
void func_80043704(s32, void *);             /* static */
extern s32 D_80076108;
extern s32 D_8007610C;
extern u8 D_8007620C;
extern u8 D_80076214;
extern s32 D_80078F10;
extern s16 D_800A4EF8;
extern s32 D_800A5BC8;
extern u8 D_800A63E4;
extern s32 D_800A63E8;
extern s32 D_800C6D28;
extern s32 *D_800C7D30;

s32 func_80035C4C(void *arg0) {
    s8 sp18;
    u8 sp10;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v1;
    s32 var_v0;
    u32 temp_v0_2;
    u8 temp_v1_2;

    if (M2C_FIELD(arg0, u8 *, 7) != 0) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0xC);
        D_8007620C = 0;
        M2C_FIELD(arg0, u8 *, 7) = 0U;
        M2C_FIELD(arg0, u8 *, 3) = 0U;
        if (D_800A5BC8 >= temp_v1) {
            if (temp_v1 != 0) {
                if (!(func_80043420() & 0x80)) {
                    M2C_FIELD(arg0, u8 *, 3) = 1U;
                }
                D_80076108 = 0;
                sp18 = 5;
                func_800435CC(0xE, &sp18, 0);
                D_800A63E8 = M2C_FIELD(arg0, s32 *, 0xC);
                goto block_8;
            }
            if (D_800C6D28 != 0) {
                D_800A63E8 = D_800C6D28;
                func_80043704(3, 0);
                D_800C6D28 = 0;
                M2C_FIELD(arg0, u8 *, 3) = 2U;
                goto block_8;
            }
            goto block_38;
        }
        goto block_38;
    }
block_8:
    temp_v1_2 = M2C_FIELD(arg0, u8 *, 3);
    switch (temp_v1_2) {
    case 0:
        temp_v0 = D_80076108 + 1;
        D_80076108 = temp_v0;
        var_v0 = 0;
        if (temp_v0 >= 3) {
            M2C_FIELD(arg0, u8 *, 3) = (u8) (M2C_FIELD(arg0, u8 *, 3) + 1);
        case 1:
            D_80076108 = 0;
            temp_v0_2 = (u32) (D_800A4EF8 * 0x61) >> 7;
            temp_a1 = temp_v0_2 & 0xFF;
            D_8006AEEC = (s8) temp_v0_2;
            func_8003EDE8(0, temp_a1, temp_a1);
            func_8003D650(0, 1, 0);
            func_80043704(3, (M2C_FIELD(arg0, s32 *, 0xC) * 4) + &D_800C7D30);
            func_800361CC(func_80036130);
            M2C_FIELD(arg0, u8 *, 3) = (u8) (M2C_FIELD(arg0, u8 *, 3) + 1);
        case 2:
            if (func_80043410() & 0x40) {
                temp_v0_3 = D_80076108 < 0x12D;
                D_80076108 += 1;
                if (temp_v0_3 != 0) {
                    return 0;
                }
                goto block_37;
            }
            temp_v0_4 = func_8004355C(1, &sp10);
            if (temp_v0_4 != 2) {
                var_v0 = 0;
                if (temp_v0_4 == 5) {
                    if (!(sp10 & 0x10)) {
                        return 1;
                    }
block_37:
                    D_80076214 = 1;
block_38:
                    return 1;
                }
                /* Duplicate return node #40. Try simplifying control flow for better match */
                return var_v0;
            }
block_24:
            M2C_FIELD(arg0, u8 *, 3) = (u8) (M2C_FIELD(arg0, u8 *, 3) + 1);
        default:
block_39:
            var_v0 = 0;
            /* Duplicate return node #40. Try simplifying control flow for better match */
            return var_v0;
        }
        return var_v0;
    case 3:
        temp_v0_5 = func_80043410();
        if (!(temp_v0_5 & 0x80)) {
            if (!(temp_v0_5 & 0x10)) {
                return 0;
            }
            goto block_37;
        }
        D_800A63E4 = 0xC;
        D_8007610C = 0;
        D_8007620C |= 0x80;
        goto block_24;
    case 4:
        if (D_800A63E4 == 0xD) {
            func_8003621C();
            func_8003EDE8(0, 0, 0);
            func_80043704(9, 0);
            D_8007620C = 0;
            D_80078F10 = 0;
            goto block_33;
        }
        var_v0 = 0;
        if (D_8007610C != 0) {
            temp_v0_6 = func_80043410();
            var_v0 = 0;
            if (!(temp_v0_6 & 0x80)) {
                if (temp_v0_6 & 0x10) {
                    D_80076214 = 1;
                }
                func_8003621C();
                func_8003EDE8(0, 0, 0);
                D_8007620C = 0;
                D_80078F10 = 0;
                var_v0 = 1;
                if (D_80076214 == 0) {
                    func_80043704(9, 0);
block_33:
                    M2C_FIELD(arg0, u8 *, 3) = (u8) (M2C_FIELD(arg0, u8 *, 3) + 1);
                    return 0;
                }
                /* Duplicate return node #40. Try simplifying control flow for better match */
                return var_v0;
            }
        }
        /* Duplicate return node #40. Try simplifying control flow for better match */
        return var_v0;
    case 5:
        temp_v0_7 = func_8004355C(1, &sp10);
        if (temp_v0_7 != 0) {
            var_v0 = 1;
            if (temp_v0_7 == 5) {
                if (sp10 & 0x10) {
                    goto block_37;
                }
                goto block_38;
            }
            /* Duplicate return node #40. Try simplifying control flow for better match */
            return var_v0;
        }
        goto block_39;
    }
}
